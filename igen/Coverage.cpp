//
// Created by KH on 2/27/2020.
//

#include "Coverage.h"

namespace igen {

loc_t Coverage::gen_loc_idx(const std::string &s) {
    auto it = mapLocStrToIdx_.find(s);
    if (it == mapLocStrToIdx_.end()) {
        loc_t sz = mapLocStrToIdx_.size();
        mapLocStrToIdx_.emplace(s, sz);
        mapLocIdxToStr_.emplace_back(s);
        return sz;
    }
    return it->second;
}

str Coverage::to_str(const VecLocs &v) {
    std::stringstream ss;
    for (const loc_t x : v)
        ss << mapLocIdxToStr_[x] << ", ";
    return ss.str();
}

str Coverage::to_str(const SetLocs &v) {
    std::stringstream ss;
    for (const loc_t x : v)
        ss << mapLocIdxToStr_[x] << ", ";
    return ss.str();
}

}