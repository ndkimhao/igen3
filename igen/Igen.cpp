//
// Created by KH on 2/26/2020.
//

#include "Igen.h"

#include <utility>

igen::Igen::Igen(std::shared_ptr<IgenOpts> opts) : opts(std::move(opts)) {}

bool igen::Igen::runOnce() {
    return false;
}
