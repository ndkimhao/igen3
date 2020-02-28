//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_DOMAIN_H
#define IGEN3_DOMAIN_H

#include <string>
#include <vector>

#include <kcommon.h>

namespace igen {


class Domain {
public:
    struct VarEntry {
        std::string name;
        std::vector<std::string> lables;

        VecArgs all_val_idx() const;

        int n_possible_vals() const {
            return lables.size();
        }
    };

public:
    Domain() = default;

    explicit Domain(const std::string &path);

    void parse(const std::string &path);

    const std::vector<VarEntry> &vars() const {
        return vars_;
    };

    const VarEntry &operator[](size_t i) const {
        return vars_[i];
    }

    int n_vars() const {
        return vars_.size();
    }

    vec<VecArgs> genOneCoveringConfigs() const;

    str to_str(const VecArgs &args) const;

private:
    std::vector<VarEntry> vars_;
};


}
#endif //IGEN3_DOMAIN_H
