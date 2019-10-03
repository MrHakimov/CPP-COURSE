#include <algorithm>
#include "autocomplete.hpp"

autocomplete::autocomplete(std::vector<term> arr) : data(std::move(arr)) {
}

std::vector<term> autocomplete::all_matches(const std::string &prefix) const {
    std::vector<term> result;
    int lowerBound = binary_search_deluxe::first_index_of(data, {prefix, 0},
            term::by_prefix_weight_order(prefix.length()));
    int upperBound = binary_search_deluxe::last_index_of(data, {prefix, 0},
            term::by_prefix_weight_order(prefix.length()));
    for (int i = lowerBound; i <= upperBound; i++) {
        result.push_back(data[i]);
    }
    std::sort(result.begin(), result.end(), term::by_reverse_weight_order());
    return result;
}

size_t autocomplete::number_of_matches(const std::string &prefix) const {
    int lowerBound = binary_search_deluxe::first_index_of(data, {prefix, 0},
            term::by_prefix_weight_order(prefix.length()));
    if (lowerBound == -1 || prefix != data[lowerBound].getData().substr(0, prefix.length())) {
        return 0;
    }
    int upperBound = binary_search_deluxe::last_index_of(data, {prefix, 0},
            term::by_prefix_weight_order(prefix.length()));
    return upperBound - lowerBound + 1;
}
