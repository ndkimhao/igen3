#include <iostream>
#include <array>
#include <vector>
#include <random>

#include <misc/cxxopts.hpp>
#include <klog.h>

#include "igen/IgenOpts.h"
#include "igen/Igen.h"

INITIALIZE_EASYLOGGINGPP

void run_interative(const cxxopts::ParseResult arg) {
    LOG(INFO, "Run iterative algorithm");

    std::string dom = arg["dom"].asString();
    uint64_t seed = arg["seed"].as<uint64_t>();
    std::string runner = arg["runner"].asString();
    std::string target = arg["target"].asString();

    auto opts = std::make_shared<igen::IgenOpts>(dom, seed, runner, target);
    auto igen = std::make_shared<igen::Igen>(opts);

    LOG(INFO, "Opts: dom={}, seed={}, runner={}, target={}", dom, seed, runner, target);
    for (bool cont = true; cont;) {
        cont = igen->runOnce();
    }
}

int main(int argc, char *argv[]) {
    START_EASYLOGGINGPP(argc, argv);
    el::Configurations conf("logging.conf");
    el::Loggers::reconfigureAllLoggers(conf);

    cxxopts::Options cxxopts("igen3", "Dynamic Interaction Inference for Configurable Software");
    cxxopts.add_options()
            ("d,dom", "Input domain file", cxxopts::value<std::string>())
            ("s,seed", "Random seed", cxxopts::value<uint64_t>())
            ("r,runner", "Executor: s/simple", cxxopts::value<std::string>())
            ("t,target", "Executable target", cxxopts::value<std::string>())
            ("i,iterative", "Run the iterative algorithm")
            ("h,help", "Print usage");

    auto opts = cxxopts.parse(argc, argv);
    if (opts.count("help")) {
        std::cout << cxxopts.help() << std::endl;
        return 0;
    }

    if (opts["iterative"].asBool()) {
        run_interative(opts);
        return 0;
    }

//    auto result = options.parse(argc, argv);
//    auto dom = result["dom"].as<std::string>();
//
//    std::cout << "dom =   " << dom;
//
//    int status = -1;
//    std::error_code ec;
//
//    reproc::options opt;
//    opt.redirect.parent = true;
//    opt.deadline = reproc::milliseconds(5000);
//
//    const std::vector<std::string> procs = {"1/ex.exe", "1", "1", "1", "1", "1", "1"};
//    std::tie(status, ec) = reproc::run(procs, opt);
//
//    if (ec) {
//        LOG(INFO, "OUTPUT === {} ===", ec.message());
//    }
//
//    {
//        dynamic_bitset<> bitset1(12, 0b0100010110111);
//        std::cout << "bitset1     = " << bitset1 << std::endl;
//
//        // random bitset
//        std::minstd_rand rand(std::random_device{}());
//        std::bernoulli_distribution dist;
//        dynamic_bitset<> bitset2;
//        for(size_t i = 0; i < 12; ++i)
//        {
//            bitset2.push_back(dist(rand));
//        }
//        std::cout << "bitset2     = " << bitset2 << std::endl;
//
//        std::cout << "common bits = " << (bitset1 & bitset2) << std::endl;
//    }
//
//    std::cout << sizeof(std::string);
    return 0;
}
