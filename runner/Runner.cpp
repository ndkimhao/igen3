//
// Created by KH on 2/26/2020.
//

#include "Runner.h"

#include <kcommon.h>

#include "igen/IgenOpts.h"
#include "runner/SimpleRunner.h"

namespace igen {


std::unique_ptr<Runner> Runner::create(std::string type) {
    if (type == "s" || type == "simple") {
        return std::make_unique<SimpleRunner>();
    } else {
        throw std::invalid_argument("invalid runner type");
    }
}

set<loc_t> Runner::run(const std::vector<arg_t> &args) {
    DCHECK(args.size() == dom_->vars().size());
    std::vector<std::string> strArgs(args.size() + 1);
    strArgs[0] = opts_->getTarget();
    for (int i = 0; i < args.size(); i++) {
        arg_t v = args[i];
        const auto &valMap = dom_->vars()[i].lables;
        DCHECK(0 <= v && v < valMap.size());
        strArgs[i + 1] = valMap[v];
    }
    FVLOG(10, "Run target with args: {} {}", opts_->getTarget(), dom_->to_str(args));
    auto ret = v_execute(strArgs);
    FVLOG(10, "Result: {}", cov_->to_str(ret));
    return ret;
}

void Runner::init(std::shared_ptr<IgenOpts> opts, std::shared_ptr<Domain> dom, std::shared_ptr<Coverage> cov) {
    opts_ = opts;
    dom_ = dom;
    cov_ = cov;
}

}