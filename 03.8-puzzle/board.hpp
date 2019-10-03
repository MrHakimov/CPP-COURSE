#pragma once

#include <string>
#include <vector>

class board {
public:
    board();

    board(const board &other);

    explicit board(std::vector<std::vector<size_t>> other);

    explicit board(int size);

    size_t size() const;

    bool is_goal() const;

    bool is_solvable() const;

    std::string to_string() const;

    size_t manhattan() const;

    size_t hamming() const;

    std::vector<std::vector<size_t>> getGoalBoard() const;

    std::pair<size_t, size_t> getZero() const;

    const std::vector<std::vector<size_t>> &getBoard() const;

    friend bool operator!=(const board &, const board &);

    friend bool operator==(const board &, const board &);

    friend bool operator<(const board &, const board &);

    friend std::ostream &operator<<(std::ostream &, const board &);

    const std::vector<size_t> &operator[](size_t index) const;

    board &operator=(const board &other);

    ~board() = default;

private:
    std::vector<std::vector<size_t>> currentBoard;

    std::vector<std::vector<size_t>> goal;

    std::pair<size_t, size_t> zero;

    void fillGoalBoard();

    void findZero();
};
