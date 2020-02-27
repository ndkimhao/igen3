//
// Created by KH on 2/27/2020.
//

#ifndef IGEN3_KLOG_H
#define IGEN3_KLOG_H

#include <glog/logging.h>
#include <fmt/format.h>

#define FLOG(level, f, ...) LOG(level) << fmt::format(f, ##__VA_ARGS__)
#define FLOG_IF(level, cond, f, ...) LOG_IF(level, cond) << fmt::format(f, ##__VA_ARGS__)
#define FVLOG(level, f, ...) VLOG(level) << fmt::format(f, ##__VA_ARGS__)
#define FVLOG_IF(level, cond, f, ...) VLOG_IF(level, cond) << fmt::format(f, ##__VA_ARGS__)
#define FCHECK(cond, f, ...) CHECK(cond) << fmt::format(f, ##__VA_ARGS__)
#define FDCHECK(cond, f, ...) DCHECK(cond) << fmt::format(f, ##__VA_ARGS__)

#endif //IGEN3_KLOG_H
