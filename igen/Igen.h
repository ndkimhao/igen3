//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_IGEN_H
#define IGEN3_IGEN_H

#include <memory>

#include "IgenOpts.h"
#include "Domain.h"
#include "runner/Runner.h"

namespace igen {


class Igen {
public:
    Igen(std::shared_ptr<IgenOpts> opts);

    void init();

    bool runOnce();

private:
    std::shared_ptr<IgenOpts> opts_;
    std::shared_ptr<Domain> dom_;
    std::shared_ptr<Runner> runner_;
};


}


#endif //IGEN3_IGEN_H