//
// Created by KH on 2/26/2020.
//

#include "SimpleRunner.h"

#include <sstream>

#include <reproc++/reproc.hpp>
#include <reproc++/sink.hpp>

namespace igen {

SimpleRunner::SimpleRunner(std::shared_ptr<IgenOpts> opts) {
    this->opts_ = opts;
}

int SimpleRunner::v_execute(const std::vector<std::string> &args, dynamic_bitset<> &locs) {
    reproc::process process;
    std::error_code ec = process.start(args);
    if (ec) {
        throw std::system_error(ec, "error in process.start()");
    }
    std::stringstream ss;
    reproc::sink::ostream sink(ss);
    ec = reproc::drain(process, sink, sink);
    if (ec) {
        throw std::system_error(ec, "error in process.drain()");
    }

    int status = 0;
    std::tie(status, ec) = process.wait(reproc::infinite);
    if (ec) {
        throw std::system_error(ec, "error in process.wait()");
    }

    return status;
}

}