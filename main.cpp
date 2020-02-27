#include <iostream>
#include <array>
#include <vector>
#include <cxxopts.hpp>
#include <klog.h>
#include <reproc++/run.hpp>

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

    return 0;
}
