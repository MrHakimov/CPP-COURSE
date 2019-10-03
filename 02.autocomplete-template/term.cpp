#include <utility>

#include <utility>
#include "term.hpp"

term::term() {
    data = "";
    weight = 0;
}

term::term(std::string str, unsigned weight) : data(std::move(str)), weight(weight) {
}

term::term(const term &otherTerm) {
    data = otherTerm.data;
    weight = otherTerm.weight;
}

term::term(term &&otherTerm) noexcept {
    std::swap(data, otherTerm.data);
    weight = otherTerm.weight;
}

term &term::operator=(term &&otherTerm) noexcept {
    std::swap(data, otherTerm.data);
    weight = otherTerm.weight;
    return *this;
}

std::string term::to_string() const {
    return data + " " + std::to_string(weight);
}

const std::string &term::getData() const {
    return data;
}

bool operator==(const term &left, const term &right) {
    return (left.data == right.data) && (left.weight == right.weight);
}

bool operator!=(const term &left, const term &right) {
    return !(left == right);
}

bool operator>(const term &left, const term &right) {
    return left.data > right.data ||
           (left.data == right.data && left.weight > right.weight);
}

bool operator<(const term &left, const term &right) {
    return !((left > right) || (left == right));
}

bool operator>=(const term &left, const term &right) {
    return !(left < right);
}

bool operator<=(const term &left, const term &right) {
    return !(left > right);
}

std::function<bool(const term &left, const term &right)> term::by_prefix_weight_order(size_t r) {
    return [r](const term &left, const term &right) {
        size_t prefLen = std::min(std::min(r, left.data.length()), right.data.length());
        return left.data.substr(0, prefLen) < right.data.substr(0, prefLen);
    };
}

std::function<bool(const term &left, const term &right)> term::by_reverse_weight_order() {
    return [](const term &left, const term &right) {
        return left.weight > right.weight;
    };
}

std::ostream &operator<<(std::ostream &output, term &term) {
    output << term.to_string();
    return output;
}
