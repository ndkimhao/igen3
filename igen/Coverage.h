//
// Created by KH on 2/27/2020.
//

#ifndef IGEN3_COVERAGE_H
#define IGEN3_COVERAGE_H

#include <kcommon.h>

namespace igen {

class Coverage {
public:
    loc_t gen_loc_idx(const std::string &s);

    str to_str(const VecLocs &v);

    str to_str(const SetLocs &v);

private:
    vec<str> mapLocIdxToStr_;
    map<std::string, loc_t> mapLocStrToIdx_;
};

}

#endif //IGEN3_COVERAGE_H
