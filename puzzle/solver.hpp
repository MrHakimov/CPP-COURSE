#pragma once

#include <queue>
#include "board.hpp"
#include <unordered_map>

class solver {
public:
    explicit solver(const board &someBoard);

    solver(const solver &other);

    solver &operator=(const solver &other);

    typename std::vector<board>::iterator begin();

    typename std::vector<board>::iterator end();

    size_t moves() const;

    ~solver() = default;

private:

    struct boardHash {
        size_t operator()(const board &someBoard) const;
    };

    struct comparator {
        bool operator()(const std::pair<size_t, board> &first, const std::pair<size_t, board> &second) const;
    };

    std::vector<std::pair<char, char>> conversions;

    board initBoard;

    board goal;

    std::vector<board> boards;

    std::unordered_map<board, board, boardHash> parent;

    void solve();

    void getParent();

    bool areIndexesCorrect(size_t x, size_t y) const;
};
