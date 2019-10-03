#include <queue>
#include <algorithm>
#include "solver.hpp"
#include <unordered_set>

solver::solver(const board &someBoard) {
    initBoard = someBoard;
    conversions = {{ 0,  1},
                   { 0, -1},
                   { 1,  0},
                   {-1,  0}};
    goal = board(someBoard.getGoalBoard());
    solve();
}

solver::solver(const solver &other) = default;

solver &solver::operator=(const solver &other) = default;

size_t solver::boardHash::operator()(const board &someBoard) const {
    size_t hash = 0;
    for (size_t i = 0; i < someBoard.size(); i++) {
        for (size_t j = 0; j < someBoard.size(); j++) {
            hash += (someBoard.size() * i + j) * someBoard[i][j];
        }
    }
    return hash;
}

bool
solver::comparator::operator()(const std::pair<size_t, board> &first, const std::pair<size_t, board> &second) const {
    return first.first > second.first;
}

void solver::getParent() {
    board currentBoard = goal;
    while (currentBoard != initBoard) {
        boards.push_back(currentBoard);
        currentBoard = parent[currentBoard];
    }
    boards.push_back(currentBoard);
    reverse(boards.begin(), boards.end());
}

bool solver::areIndexesCorrect(size_t x, size_t y) const {
    return (x != 0 && x < initBoard.size()) &&
           (y != 0 && y < initBoard.size());
}

// https://blog.goodaudience.com/solving-8-puzzle-using-a-algorithm-7b509c331288
void solver::solve() {
    if (!initBoard.is_solvable()) {
        return;
    }

    std::unordered_set<board, boardHash> visited;
    std::unordered_map<board, size_t, boardHash> distance;
    std::priority_queue<std::pair<size_t, board>, std::vector<std::pair<size_t, board>>, comparator> q;

    distance[initBoard] = 0;
    q.push({0, initBoard});
    while (!q.empty()) {
        const auto [currentDist, currentBoard] = q.top();
        if (currentBoard.is_goal()) {
            getParent();
            return;
        }
        q.pop();
        visited.insert(currentBoard);

        std::pair<size_t, size_t> zeroCoords = currentBoard.getZero();
        for (const auto [dx, dy] : conversions) {
            size_t x1 = zeroCoords.first + dx;
            size_t y1 = zeroCoords.second + dy;
            board changedBoard = currentBoard;

            if (areIndexesCorrect(x1, y1)) {
                std::vector<std::vector<size_t>> tmp = changedBoard.getBoard();
                std::swap(tmp[zeroCoords.first][zeroCoords.second], tmp[x1][y1]);
                changedBoard = board(tmp);

                size_t dist = currentDist + changedBoard.manhattan() + changedBoard.hamming();
                if (distance.find(changedBoard) == distance.end()) {
                    distance[changedBoard] = INT32_MAX;
                }

                if (dist < distance[changedBoard] || !visited.count(changedBoard)) {
                    parent[changedBoard] = currentBoard;
                    distance[changedBoard] = dist;
                    q.push({dist, changedBoard});
                }

                if (dist > distance[changedBoard] && visited.count(changedBoard)) {
                    continue;
                }
            }
        }
    }
}

size_t solver::moves() const {
    return boards.size();
}

typename std::vector<board>::iterator solver::begin() {
    return boards.begin();
}

typename std::vector<board>::iterator solver::end() {
    return boards.end();
}
