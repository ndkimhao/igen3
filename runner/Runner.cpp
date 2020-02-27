//
// Created by KH on 2/26/2020.
//

#include "Runner.h"

#include <klog.h>

#include "igen/IgenOpts.h"
#include "runner/SimpleRunner.h"

namespace igen {


std::unique_ptr<Runner> Runner::create(std::string type, std::shared_ptr<IgenOpts> opts) {
    if (type == "s" || type == "simple") {
        return std::make_unique<SimpleRunner>(opts);
    } else {
        throw std::invalid_argument("invalid runner type");
    }
}

void Runner::init(std::shared_ptr<Domain> dom) {
    this->dom_ = dom;
}

void Runner::run(const std::vector<arg_t> &args, dynamic_bitset<> &locs) {
    DCHECK(args.size() == dom_->vars().size());
    std::vector<std::string> strArgs(args.size());
    for (int i = 0; i < args.size(); i++) {
        arg_t v = args[i];
        const auto &valMap = dom_->vars()[i].values;
        DCHECK(0 <= v && v < valMap.size());
        strArgs[i] = valMap[v];
    }
    locs.reset();
    FVLOG(10, "Run target with args: {}", fmt::join(args, " "));
    int status = v_execute(strArgs, locs);
    if (status != 0) {
        FLOG(FATAL, "Program return status code {}", status);
    }
//    locs.shrink_to_fit();
}

loc_t Runner::getLocIdx(const std::string &s) {
    auto it = mapLocStrToIdx_.find(s);
    if (it == mapLocStrToIdx_.end()) {
        loc_t sz = mapLocStrToIdx_.size();
        mapLocStrToIdx_.insert_or_assign(s, sz);
        return sz;
    }
    return it->second;
}

}