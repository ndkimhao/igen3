//
// Created by KH on 2/26/2020.
//

#include "Runner.h"

#include <kcommon.h>

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
    FVLOG(10, "Result: {}", to_str(ret));
    return ret;
}

loc_t Runner::gen_loc_idx(const std::string &s) {
    auto it = mapLocStrToIdx_.find(s);
    if (it == mapLocStrToIdx_.end()) {
        loc_t sz = mapLocStrToIdx_.size();
        mapLocStrToIdx_.emplace(s, sz);
        mapLocIdxToStr.emplace_back(s);
        return sz;
    }
    return it->second;
}

str Runner::to_str(const vec<loc_t> &v) {
    std::stringstream ss;
    for (const loc_t x : v)
        ss << mapLocIdxToStr[x] << ", ";
    return ss.str();
}

str Runner::to_str(const set<loc_t> &v) {
    std::stringstream ss;
    for (const loc_t x : v)
        ss << mapLocIdxToStr[x] << ", ";
    return ss.str();
}

}