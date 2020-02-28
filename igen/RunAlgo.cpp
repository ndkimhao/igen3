//
// Created by KH on 2/27/2020.
//

#include "RunAlgo.h"

#include <kcommon.h>
#include "igen/Igen.h"

namespace igen {

void run_interative(const cxxopts::ParseResult &arg) {
    LOG(INFO) << "Run iterative algorithm";

    std::string dom = arg["dom"].asString();
    uint64_t seed = arg["seed"].as<uint64_t>();
    std::string runner = arg["runner"].asString();
    std::string target = arg["target"].asString();

    auto opts = std::make_shared<igen::IgenOpts>(dom, seed, runner, target);
    auto igen = std::make_shared<igen::Igen>(opts);
    igen->init();
    igen->run();
}

}