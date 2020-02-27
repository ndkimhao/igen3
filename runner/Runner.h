//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_RUNNER_H
#define IGEN3_RUNNER_H

#include <vector>

#include <ktypes.h>
#include <tsl/hopscotch_map.h>
#include <dynamic_bitset.hpp>

#include "igen/IgenOpts.h"
#include "igen/Domain.h"

namespace igen {


class Runner {
public:
    void run(const std::vector<arg_t> &args, dynamic_bitset<> &locs);

    void init(std::shared_ptr<Domain> dom);

    virtual ~Runner() = default;

public:
    static std::unique_ptr<Runner> create(std::string type, std::shared_ptr<IgenOpts> opts);

protected:
    virtual int v_execute(const std::vector<std::string> &args, dynamic_bitset<> &locs) = 0;

    [[nodiscard]] loc_t getLocIdx(const std::string &s);

    Runner() = default;

    std::shared_ptr<IgenOpts> opts_;
    std::shared_ptr<Domain> dom_;
    tsl::hopscotch_map<std::string, loc_t> mapLocStrToIdx_;
};


}


#endif //IGEN3_RUNNER_H
