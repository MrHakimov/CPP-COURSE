#include "binary_search_deluxe.hpp"

int binary_search_deluxe::first_index_of(const std::vector<term> &a, const term &key,
                                         const std::function<bool(const term &left,
                                                                  const term &right)> &comparator) {
    int leftBorder = -1;
    int rightBorder = a.size() - 1;
    while (rightBorder - leftBorder > 1) {
        int middle = (leftBorder + rightBorder) / 2;
        if (comparator(a[middle], key)) {
            leftBorder = middle;
        } else {
            rightBorder = middle;
        }
    }
    return rightBorder;
}

int binary_search_deluxe::last_index_of(const std::vector<term> &a, const term &key,
                                        const std::function<bool(const term &left,
                                                                 const term &right)> &comparator) {
    int leftBorder = 0;
    int rightBorder = a.size();
    while (rightBorder - leftBorder > 1) {
        int middle = (leftBorder + rightBorder) / 2;
        if (!comparator(key, a[middle])) {
            leftBorder = middle;
        } else {
            rightBorder = middle;
        }
    }
    return leftBorder;
}
