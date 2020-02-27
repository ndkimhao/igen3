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
    struct VarEntry {
        std::string name;
        std::vector<std::string> values;
    };

public:
    DomainFile() = default;

    explicit DomainFile(const std::string &path);

    void parse(const std::string &path);

    [[nodiscard]] const std::vector<VarEntry> &getVars() const;

private:
    std::vector<VarEntry> vars_;
};


}
#endif //IGEN3_DOMAINFILE_H
