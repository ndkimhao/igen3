//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_DOMAINFILE_H
#define IGEN3_DOMAINFILE_H

#include <string>
#include <vector>

namespace igen {


class DomainFile {
public:
    DomainFile() = default;

    DomainFile(const std::string &path);

    void parse(const std::string &path);

private:
    std::vector<std::pair<std::string, std::vector<std::string>>> rep_;
};


}
#endif //IGEN3_DOMAINFILE_H
