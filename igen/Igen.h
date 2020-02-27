//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_IGEN_H
#define IGEN3_IGEN_H

#include <memory>

#include "IgenOpts.h"

namespace igen {


class Igen {
public:
    Igen(std::shared_ptr<IgenOpts> opts);

    bool runOnce();

private:
    std::shared_ptr<IgenOpts> opts;
};


}


#endif //IGEN3_IGEN_H
