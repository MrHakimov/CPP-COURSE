#include <iostream>
#include "autocomplete.hpp"

void echo(const std::vector<term> &a) {
    if (!a.empty()) {
        std::string s;
        for (const auto &dataNweight : a) {
            s += dataNweight.to_string() + "\n";
        }
        std::cout << s;
    }
}

void test_autocomplete() {
    std::cout << "Autocomplete tests:\n";
    std::cout << "-------------------\nMain data:\n";
    std::vector<term> a{
            {"graph",          5},
            {"grafity",       63},
            {"ron",           53},
            {"ronaldo",        2},
            {"ronaldinho",    64},
            {"ronald uizley",  8},
            {"ronda rousie",  23}
    };
    for (auto dataNweight : a) {
        std::cout << dataNweight << '\n';
    }
    autocomplete autocomplete(a);
    std::cout << "==\nNUMBER OF MATCHES\n";
    unsigned countMatches = autocomplete.number_of_matches("ron");
    std::cout << "number of words with prefix \'ron\': " << countMatches << ".\n";
    unsigned countZeroMatches = autocomplete.number_of_matches("none");
    std::cout << "number of words with prefix \'none\': " << countZeroMatches << ".\n";

    std::cout << "==\nALL MATCHES\n";
    std::cout << "all matches with prefix \'ron\':\n";
    echo(autocomplete.all_matches("ron"));

    std::cout << "TESTS COMPLETED\n";
}

int main() {
    test_autocomplete();
    return 0;
}
