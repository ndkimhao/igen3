//
// Created by KH on 2/26/2020.
//

#include "Domain.h"

#include <fstream>
#include <sstream>

namespace igen {


Domain::Domain(const std::string &path) {
    parse(path);
}

void Domain::parse(const std::string &path) {
    std::ifstream ifs(path);
    std::string line;
    while (std::getline(ifs, line)) {
        std::stringstream ss(line);
        VarEntry entry;
        ss >> entry.name;
        if (entry.name.empty() || entry.name[0] == '#') continue;

        std::string val;
        while (ss >> val) {
            if (val.empty() || val[0] == '#') break;
            entry.values.push_back(std::move(val));
        }
        vars_.push_back(entry);
    }
}

const std::vector<Domain::VarEntry> &Domain::vars() const {
    return vars_;
}


}