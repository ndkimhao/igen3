//
// Created by KH on 2/26/2020.
//

#include "Igen.h"

#include <utility>

namespace igen {


Igen::Igen(std::shared_ptr<IgenOpts> opts) : opts_(std::move(opts)) {}

bool Igen::run() {
    FLOG(INFO, "Run, Opts: dom={}, seed={}, runner={}, target={}", dom_, opts_->getSeed(), runner_, opts_->getTarget());
    Rand.seed(opts_->getSeed());

    vec<VecArgs> configs = dom_->genOneCoveringConfigs();
    FVLOG(10, "Initial configs ({}): \n", configs.size()) << _to_str(configs);

    auto res = runner_->run(configs[0]);
    FLOG(INFO, "{}", cov_->to_str(res));

    return false;
}

void Igen::init() {
    dom_ = std::make_shared<Domain>(opts_->getDomInp());
    runner_ = std::shared_ptr<Runner>(Runner::create(opts_->getRunnerType()));
    cov_ = std::make_shared<Coverage>();
    runner_->init(opts_, dom_, cov_);
}

str Igen::_to_str(vec<VecArgs> configs) {
    std::stringstream ss;
    for (auto &c : configs)
        ss << "    " << dom_->to_str(c) << "\n";
    return ss.str();
}

}