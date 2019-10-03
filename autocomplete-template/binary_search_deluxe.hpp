#pragma once

#include <vector>
#include "term.hpp"

class binary_search_deluxe {
public:
    binary_search_deluxe() = delete;

    static int first_index_of(const std::vector<term> &a, const term &key,
                              const std::function<bool(const term &left, const term &right)> &comparator);

    static int last_index_of(const std::vector<term> &a, const term &key,
                             const std::function<bool(const term &first, const term &second)> &comparator);

};
