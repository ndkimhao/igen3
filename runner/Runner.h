//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_RUNNER_H
#define IGEN3_RUNNER_H

#include <vector>

#include <ktypes.h>
#include <tsl/hopscotch_map.h>
#include <dynamic_bitset.hpp>

namespace igen {


class Runner {
public:
    Runner() = delete;

    void run(const std::vector<arg_t> &args, dynamic_bitset<> &locs) {

        locs.shrink_to_fit();
    }

public:
    static std::unique_ptr<Runner> create(std::string type);

private:
    int numArgs_;
    std::vector<std::vector<std::string>> mapIdxToArgStr;
    tsl::hopscotch_map<arg_t, std::string> mapLocStrToIdx;
};


}


#endif //IGEN3_RUNNER_H
