//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_DOMAIN_H
#define IGEN3_DOMAIN_H

#include <string>
#include <vector>

namespace igen {


class Domain {
public:
    struct VarEntry {
        std::string name;
        std::vector<std::string> values;
    };

public:
    Domain() = default;

    explicit Domain(const std::string &path);

    void parse(const std::string &path);

    [[nodiscard]] const std::vector<VarEntry> &vars() const;

private:
    std::vector<VarEntry> vars_;
};


}
#endif //IGEN3_DOMAIN_H
