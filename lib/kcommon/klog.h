//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_KLOG_H
#define IGEN3_KLOG_H

#include <misc/easylogging++.h>
#include <fmt/format.h>

#define LOG(level, f, ...) ELPP_LOG(level) << fmt::format(f, ##__VA_ARGS__)
#define LOG_IF(condition, level, f, ...) ELPP_LOG_IF(condition, level) << fmt::format(f, ##__VA_ARGS__)

#endif //IGEN3_KLOG_H
