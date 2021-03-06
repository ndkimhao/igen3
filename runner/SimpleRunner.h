//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_SIMPLERUNNER_H
#define IGEN3_SIMPLERUNNER_H

#include "Runner.h"

namespace igen {

class SimpleRunner : public Runner {
public:
    SimpleRunner();

protected:
    set<loc_t> v_execute(const std::vector<std::string> &args) override;
};

}


#endif //IGEN3_SIMPLERUNNER_H
