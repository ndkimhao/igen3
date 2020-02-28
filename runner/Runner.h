//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_RUNNER_H
#define IGEN3_RUNNER_H

#include <vector>

#include <kcommon.h>

#include "igen/IgenOpts.h"
#include "igen/Domain.h"
#include "igen/Coverage.h"

namespace igen {


class Runner {
public:
    set<loc_t> run(const std::vector<arg_t> &args);

    void init(std::shared_ptr<IgenOpts> opts, std::shared_ptr<Domain> dom, std::shared_ptr<Coverage> cov);

    virtual ~Runner() = default;

public:
    static std::unique_ptr<Runner> create(std::string type);

protected:
    virtual set<loc_t> v_execute(const std::vector<std::string> &args) = 0;

    Runner() = default;

    std::shared_ptr<IgenOpts> opts_;
    std::shared_ptr<Domain> dom_;
    std::shared_ptr<Coverage> cov_;
};


}


#endif //IGEN3_RUNNER_H
