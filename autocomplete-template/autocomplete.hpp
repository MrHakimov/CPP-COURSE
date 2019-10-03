#pragma once

#include "binary_search_deluxe.hpp"

class autocomplete {
public:
    explicit autocomplete(std::vector<term> arr);

    std::vector<term> all_matches(const std::string &prefix) const;

    size_t number_of_matches(const std::string &prefix) const;

private:
    std::vector<term> data;
};
