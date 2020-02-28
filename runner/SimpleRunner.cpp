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

set<loc_t> SimpleRunner::v_execute(const std::vector<std::string> &args) {
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

    set<loc_t> ret;
    str line;
    while (getline(ss, line)) {
        if (line.size() && line.back() == '\r')
            line.pop_back();
        ret.insert(gen_loc_idx(line));
    }

    int status = 0;
    std::tie(status, ec) = process.wait(reproc::infinite);
    if (ec) {
        throw std::system_error(ec, "error in process.wait()");
    }

    if (status != 0) {
        throw std::runtime_error("Non zero status code");
    }

    return ret;
}

}