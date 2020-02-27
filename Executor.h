//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_EXECUTOR_H
#define IGEN3_EXECUTOR_H

#include <vector>

#include <ktypes.h>
#include <tsl/hopscotch_map.h>

namespace igen {


class Executor {
public:
    void run(const std::vector<arg_t> &args) {

    }

private:
    tsl::hopscotch_map<arg_t, std::string> mapArgStr;
};


}


#endif //IGEN3_EXECUTOR_H
