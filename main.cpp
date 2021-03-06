#include <iostream>
#include <array>
#include <vector>
#include <random>

#include <cxxopts.hpp>
#include <kcommon.h>

#include "igen/RunAlgo.h"

void initGlog(int argc, char *argv[]) {
    FLAGS_colorlogtostderr = true;
    FLAGS_timestamp_in_logfile_name = false;
    FLAGS_max_log_size = 2;
    google::SetStderrLogging(0);
    for (int i = 0; i < google::NUM_SEVERITIES; ++i) {
        google::SetLogDestination(i, "app.log");
    }
    google::SetVLOGLevel("*", 20);
    google::InitGoogleLogging(argv[0]);
}

int main(int argc, char *argv[]) {
    initGlog(argc, argv);

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
        igen::run_interative(opts);
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
