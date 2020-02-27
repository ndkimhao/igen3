//
// Created by KH on 2/26/2020.
//

#include "IgenOpts.h"

#include <utility>

#include "runner/Runner.h"

namespace igen {


IgenOpts::IgenOpts(std::string domInp, uint64_t seed, std::string runnerType, std::string target)
        : domInpPath_(std::move(domInp)), seed_(seed), runnerType_(std::move(runnerType)), target_(std::move(target)) {
    runner_ = std::shared_ptr<Runner>(Runner::create(runnerType_));
    domFile_.parse(domInpPath_);
}

const std::string &IgenOpts::getDomInp() const {
    return domInpPath_;
}

uint64_t IgenOpts::getSeed() const {
    return seed_;
}

const std::string &IgenOpts::getRunnerType() const {
    return runnerType_;
}

const std::shared_ptr<Runner> &IgenOpts::getRunner() const {
    return runner_;
}

const std::string &IgenOpts::getTarget() const {
    return target_;
}


}

