#include <utility>

#include <random>
#include "board.hpp"
#include <algorithm>

board::board() = default;

board::board(const board &other) = default;

board::board(std::vector<std::vector<size_t>> other) : currentBoard(std::move(other)) {
    fillGoalBoard();
    findZero();
}

board::board(int size) {
    currentBoard.resize(size, std::vector<size_t>(size));
    std::vector<size_t> someBoard;
    someBoard.resize(size * size);
    fillGoalBoard();
    for (size_t i = 0; i < size * size; i++) {
        someBoard[i] = i;
    }
    std::shuffle(someBoard.begin(), someBoard.end(), std::mt19937(std::random_device()()));
    for (int i = 0; i < size * size; i++) {
        size_t x = i / size;
        size_t y = i % size;
        currentBoard[x][y] = someBoard[i];
        if (!currentBoard[x][y]) {
            zero = std::make_pair(x, y);
        }
    }
}

size_t board::size() const {
    return currentBoard.size();
}

std::vector<std::vector<size_t>> board::getGoalBoard() const {
    return goal;
}

std::pair<size_t, size_t> board::getZero() const {
    return zero;
}

void board::fillGoalBoard() {
    size_t dimension = size();
    goal.assign(dimension, std::vector<size_t>(dimension));
    int tmp = 1;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            goal[i][j] = tmp;
            tmp++;
        }
    }
    goal[dimension - 1][dimension - 1] = 0;
}

void board::findZero() {
    for (int i = 0; i < currentBoard.size(); i++) {
        for (int j = 0; j < currentBoard.size(); j++) {
            if (currentBoard[i][j] == 0) {
                zero = std::make_pair(i, j);
                return;
            }
        }
    }
}

const std::vector<std::vector<size_t>> &board::getBoard() const {
    return currentBoard;
}

bool board::is_goal() const {
    return currentBoard == goal;
}

// https://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/
bool board::is_solvable() const {
    size_t inversionsCount = 0;

    std::vector <int> current;
    for (int i = 0; i < currentBoard.size(); i++) {
        for (int j = 0; j < currentBoard.size(); j++) {
            if (currentBoard[i][j] != 0) {
                current.push_back(currentBoard[i][j]);
            }
        }
    }

    for (int i = 0; i < current.size() - 1; i++) {
        for (int j = i + 1; j < current.size(); j++) {
            if (current[i] != 0 && current[j] != 0 && current[i] > current[j]) {
                inversionsCount++;
            }
        }
    }
    return inversionsCount % 2 == 0;
}

size_t board::hamming() const {
    size_t hammingDistance = 0;

    for (size_t i = 0; i < currentBoard.size(); i++) {
        for (size_t j = 0; j < currentBoard.size(); j++) {
            if (currentBoard[i][j] != goal[i][j]) {
                hammingDistance++;
            }
        }
    }

    return hammingDistance;
}

size_t board::manhattan() const {
    size_t manhattanDistance = 0;
    size_t dimension = size();
    for (size_t i = 0; i < dimension; i++) {
        for (size_t j = 0; j < dimension; j++) {
            int x = (currentBoard[i][j] - 1) / dimension;
            int y = (currentBoard[i][j] - 1) % dimension;
            if (!currentBoard[i][j]) {
                x = y = dimension - 1;
            }
            manhattanDistance += abs(static_cast<int>(i) - x) + abs(static_cast<int>(j) - y);
        }
    }

    return manhattanDistance;
}

std::string board::to_string() const {
    std::string result;
    for (size_t i = 0; i < currentBoard.size(); i++) {
        for (size_t j = 0; j < currentBoard.size(); j++) {
            result += std::to_string(currentBoard[i][j]) + ' ';
        }
        result.pop_back();
        result.push_back('\n');
    }
    return result;
}

board &board::operator=(const board &other) = default;

const std::vector<size_t> &board::operator[](size_t index) const {
    return currentBoard[index];
}

std::ostream &operator<<(std::ostream &out, const board &brd) {
    out << brd.to_string();
    return out;
}

bool operator==(const board &first, const board &second) {
    return first.currentBoard == second.currentBoard;
}

bool operator!=(const board &first, const board &second) {
    return !(first.currentBoard == second.currentBoard);
}

bool operator<(const board &first, const board &second) {
    return first.currentBoard < second.currentBoard;
}
