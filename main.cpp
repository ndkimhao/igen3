#include <iostream>
#include <cxxopts.hpp>
#include <klog.h>

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
    return 0;
}
