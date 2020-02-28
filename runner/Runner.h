//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_RUNNER_H
#define IGEN3_RUNNER_H

#include <vector>

#include <kcommon.h>
#include <tsl/hopscotch_map.h>

#include "igen/IgenOpts.h"
#include "igen/Domain.h"

namespace igen {


class Runner {
public:
    set<loc_t> run(const std::vector<arg_t> &args);

    void init(std::shared_ptr<Domain> dom);

    virtual ~Runner() = default;

public:
    static std::unique_ptr<Runner> create(std::string type, std::shared_ptr<IgenOpts> opts);

protected:
    virtual set<loc_t> v_execute(const std::vector<std::string> &args) = 0;

    loc_t gen_loc_idx(const std::string &s);

    str to_str(const vec<loc_t> &v);
    str to_str(const set<loc_t> &v);

    Runner() = default;

    std::shared_ptr<IgenOpts> opts_;
    std::shared_ptr<Domain> dom_;

    vec<str> mapLocIdxToStr;
    tsl::hopscotch_map<std::string, loc_t> mapLocStrToIdx_;
};


}


#endif //IGEN3_RUNNER_H
