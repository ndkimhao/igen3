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
    private:
        std::string name_;
        std::vector<std::string> labels_;
    public:
        void _setName(const std::string &name) { name_ = name; };

        void _setLabels(const std::vector<std::string> &labels) { labels_ = labels; };

        VarEntry() = default;

        VarEntry(const std::string &name, const std::vector<std::string> &labels) : name_(name), labels_(labels) {}

    public:
        VecArgs all_val_idx() const;

        int n_possible_vals() const {
            return labels_.size();
        }

        const str &name() const { return name_; };

        const vec<str> &labels() const { return labels_; };
    };

public:
    Domain() = default;

    explicit Domain(const std::string &path);

    void parse(const std::string &path);

    const std::vector<VarEntry> &vars() const { return vars_; };

    const VarEntry &operator[](size_t i) const { return vars_[i]; }

    int n_vars() const { return vars_.size(); }

    vec<VecArgs> genOneCoveringConfigs() const;

    str to_str(const VecArgs &args) const;

    vec<VarEntry>::const_iterator begin() const { return vars_.begin(); }

    vec<VarEntry>::const_iterator end() const { return vars_.end(); }

private:
    vec<VarEntry> vars_;
};

}

template<>
struct fmt::formatter<igen::Domain::VarEntry> {
    constexpr auto parse(format_parse_context &ctx) { return ctx.begin(); }

    template<typename FormatContext>
    auto format(const igen::Domain::VarEntry &v, FormatContext &ctx) {
        auto it = ctx.out();
        const auto &labels = v.labels();
        format_to(it, "{}={{", v.name());
        for (int i = 0; i < labels.size(); ++i) {
            format_to(it, "{}", labels[i]);
            if (i < labels.size() - 1)
                *it = ' ';
        }
        *it = '}';
        return it;
    }
};

template<>
struct fmt::formatter<igen::Domain> {
    constexpr auto parse(format_parse_context &ctx) { return ctx.begin(); }

    template<typename FormatContext>
    auto format(const igen::Domain &d, FormatContext &ctx) {
        auto it = ctx.out();
        const auto &vars = d.vars();
        for (int i = 0; i < vars.size(); ++i) {
            format_to(it, "{}", vars[i]);
            if (i < vars.size() - 1)
                *it = ',', *it = ' ';
        }
        return it;
    }
};

#endif //IGEN3_DOMAIN_H
