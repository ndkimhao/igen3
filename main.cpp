#include <iostream>
#include <array>
#include <vector>
#include <random>

#include <misc/cxxopts.hpp>
#include <klog.h>
#include <reproc++/run.hpp>
#include <dynamic_bitset.hpp>

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[]) {
    START_EASYLOGGINGPP(argc, argv);
    el::Configurations conf("logging.conf");
    el::Loggers::reconfigureAllLoggers(conf);

    cxxopts::Options options("igen3", "Dynamic Interaction Inference for Configurable Software");
    options.add_options()
            ("dom", "Input domain", cxxopts::value<std::string>());

    auto result = options.parse(argc, argv);
    auto dom = result["dom"].as<std::string>();

    std::cout << "dom =   " << dom;

    int status = -1;
    std::error_code ec;

    reproc::options opt;
    opt.redirect.parent = true;
    opt.deadline = reproc::milliseconds(5000);

    const std::vector<std::string> procs = {"1/ex.exe", "1", "1", "1", "1", "1", "1"};
    std::tie(status, ec) = reproc::run(procs, opt);

    if (ec) {
        LOG(INFO, "OUTPUT === {} ===", ec.message());
    }

    {
        dynamic_bitset<> bitset1(12, 0b0100010110111);
        std::cout << "bitset1     = " << bitset1 << std::endl;

        // random bitset
        std::minstd_rand rand(std::random_device{}());
        std::bernoulli_distribution dist;
        dynamic_bitset<> bitset2;
        for(size_t i = 0; i < 12; ++i)
        {
            bitset2.push_back(dist(rand));
        }
        std::cout << "bitset2     = " << bitset2 << std::endl;

        std::cout << "common bits = " << (bitset1 & bitset2) << std::endl;
    }

    std::cout << sizeof(std::string);
    return 0;
}
