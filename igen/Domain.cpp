//
// Created by KH on 2/26/2020.
//

#include "Domain.h"

#include <fstream>
#include <sstream>

#include <kvecutil.h>

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
            entry.lables.push_back(std::move(val));
        }
        vars_.push_back(entry);
    }
}

std::vector<VecArgs> Domain::genOneCoveringConfigs() const {
    std::vector<VecArgs> ret;

    vec<set<arg_t>> SetVAL;
    for (int i = 0; i < n_vars(); i++) {
        SetVAL.emplace_back(to_set(vars_[i].all_val_idx()));
    }

    int cnt_clr = 0;
    while (cnt_clr < n_vars()) {
        VecArgs va(n_vars());
        for (int i = 0; i < n_vars(); i++) {
            set<arg_t> &st = SetVAL[i];
            if (st.size()) {
                auto it = Rand.get(st);
                va[i] = *it;
                st.erase(it);
                if (st.empty())
                    cnt_clr++;
            } else {
                va[i] = Rand.get(vars_[i].n_possible_vals());
            }
        }
        ret.push_back(std::move(va));
    }

    return ret;
}

str Domain::to_str(const VecArgs &args) const {
    CHECK(args.size() == n_vars());
    std::stringstream ss;
    for (int i = 0; i < args.size(); i++) {
        ss << vars()[i].name << ' ' << vars()[i].lables.at(args[i]) << ", ";
    }
    return ss.str();
}

VecArgs Domain::VarEntry::all_val_idx() const {
    vec<arg_t> ret(n_possible_vals());
    for (int i = 0; i < ret.size(); i++)
        ret[i] = i;
    return ret;
}

}