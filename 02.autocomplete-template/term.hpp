#pragma once

#include <string>
#include <functional>

class term {
public:
    term();

    term(std::string str, unsigned weight);

    term(const term &otherTerm);

    term(term &&otherTerm) noexcept;

    friend bool operator==(const term &left, const term &right);

    friend bool operator!=(const term &left, const term &right);

    friend bool operator>(const term &left, const term &right);

    friend bool operator<(const term &left, const term &right);

    friend bool operator>=(const term &left, const term &right);

    friend bool operator<=(const term &left, const term &right);

    term &operator=(const term &otherTerm) = default;

    term &operator=(term &&otherTerm) noexcept;

    static std::function<bool(const term &left, const term &right)> by_reverse_weight_order();

    static std::function<bool(const term &left, const term &right)> by_prefix_weight_order(size_t r);

    std::string to_string() const;

    friend std::ostream &operator<<(std::ostream &output, term &currentTerm);

    const std::string &getData() const;

private:
    std::string data;
    unsigned weight;
};
