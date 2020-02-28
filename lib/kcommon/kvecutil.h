//
// Created by KH on 2/27/2020.
//

#ifndef IGEN3_KVECUTIL_H
#define IGEN3_KVECUTIL_H

#include <vector>
#include <set>

namespace igen {


template<typename T>
void remove_elm_in_vector_no_order(std::vector<T> &v, size_t idx) {
    v[idx] = std::move(v.back());
    v.pop_back();
}

template<typename T>
void remove_elm_in_vector_no_order(std::vector<T> &v, typename std::vector<T>::iterator it) {
    *it = std::move(v.back());
    v.pop_back();
}

template<typename T>
std::set<T> to_set(const std::vector<T> &v) {
    return std::set<T>(v.begin(), v.end());
}

}

#endif //IGEN3_KVECUTIL_H
