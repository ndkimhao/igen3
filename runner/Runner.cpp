//
// Created by KH on 2/26/2020.
//

#include "Runner.h"

namespace igen {


std::unique_ptr<Runner> Runner::create(std::string type) {
    if (type == "s" || type == "simple") {
        return std::unique_ptr<Runner>();
    } else {
        throw std::invalid_argument("invalid runner type");
    }
}

}