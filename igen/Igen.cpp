//
// Created by KH on 2/26/2020.
//

#include "Igen.h"

#include <utility>

namespace igen {


Igen::Igen(std::shared_ptr<IgenOpts> opts) : opts_(std::move(opts)) {}

bool Igen::runOnce() {
    return false;
}

void Igen::init() {
    dom_ = std::make_shared<Domain>(opts_->getDomInp());
    runner_ = std::shared_ptr<Runner>(Runner::create(opts_->getRunnerType(), opts_));
    runner_->init(dom_);
}


}