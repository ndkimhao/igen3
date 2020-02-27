//
// Created by KH on 2/26/2020.
//

#include "DomainFile.h"

#include <fstream>

namespace igen {


DomainFile::DomainFile(const std::string &path) {
    parse(path);
}

void DomainFile::parse(const std::string &path) {
    std::ifstream ifs(path);
}


}