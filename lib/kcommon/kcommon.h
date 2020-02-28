//
// Created by KH on 2/27/2020.
//

#ifndef IGEN3_KCOMMON_H
#define IGEN3_KCOMMON_H

#include <glog/logging.h>
#include <fmt/format.h>
#include <effolkronium/random.hpp>

#include <kprettyprint.h>
#include <fmt/ostream.h>

#include <set>
#include <map>

#define FLOG(level, f, ...) LOG(level) << fmt::format(f, ##__VA_ARGS__)
#define FLOG_IF(level, cond, f, ...) LOG_IF(level, cond) << fmt::format(f, ##__VA_ARGS__)
#define FVLOG(level, f, ...) VLOG(level) << fmt::format(f, ##__VA_ARGS__)
#define FVLOG_IF(level, cond, f, ...) VLOG_IF(level, cond) << fmt::format(f, ##__VA_ARGS__)
#define FCHECK(cond, f, ...) CHECK(cond) << fmt::format(f, ##__VA_ARGS__)
#define FDCHECK(cond, f, ...) DCHECK(cond) << fmt::format(f, ##__VA_ARGS__)

namespace igen {

typedef int32_t arg_t;
typedef int32_t loc_t;

typedef std::vector<arg_t> VecArgs;
typedef std::vector<loc_t> VecLocs;
typedef std::set<loc_t> SetLocs;

template<typename T> using vec = std::vector<T>;
template<typename T> using set = std::set<T>;
template<typename T, typename U> using map = std::map<T, U>;
template<typename T, typename U> using pair = std::pair<T, U>;

typedef std::string str;

extern effolkronium::random_local Rand;

}

#endif //IGEN3_KCOMMON_H
