#include <chrono>
#include <vector>
#include <random>
#include <iostream>
#include "solver.hpp"

using namespace std;

int main() {
    vector<vector<vector<size_t>>> tests = {
                                            {{1, 2, 3},
                                             {4, 5, 6},
                                             {7, 8, 0}},

                                            {{1, 2, 3},
                                             {4, 5, 6},
                                             {0, 7, 8}},

                                            {{1, 2, 3},
                                             {0, 5, 6},
                                             {4, 7, 8}},

                                            {{1, 2, 3, 4},
                                             {5, 6, 7, 8},
                                             {9, 10, 11, 12},
                                             {13, 14, 0, 15}},

                                            {{1, 2, 3, 4},
                                             {5, 6, 7, 8},
                                             {9, 10, 11, 12},
                                             {13, 14, 15, 0}},

                                            {{1, 2, 3, 4},
                                             {0, 5, 6, 7},
                                             {9, 10, 11, 8},
                                             {13, 14, 15, 12}},

                                            {{1, 2, 3, 0},
                                             {5, 6, 7, 4},
                                             {9, 10, 11, 8},
                                             {13, 14, 15, 12}},

                                            {{1, 2, 3, 4, 5},
                                             {6, 7, 8, 9, 10},
                                             {11, 12, 13, 14, 15},
                                             {16, 17, 18, 19, 20},
                                             {21, 22, 23, 24, 0}}
    };


    int testNumber = 1;
    for (const auto &board : tests) {
        auto start = chrono::steady_clock::now();
        cout << "Test #" << testNumber++ << endl;
        cout << "Main board : " << endl;
        for (const auto &v : board) {
            for (const auto &i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;

        class board currentBoard(board);

        if (!currentBoard.is_solvable()) {
            cout << "Board is unsolvable!" << endl;
            continue;
        }

        solver currentSolver(currentBoard);

        cout << "Number of moves: " << currentSolver.moves() - 1 << endl;
        for (const auto &iter : currentSolver) {
            cout << iter.to_string() << endl;
        }
        auto finish = chrono::steady_clock::now();
        auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(finish - start);
        cout << endl << "==" << endl << "Time: " << elapsed_ms.count() << " ms\n";
        cout << "================\n";
    }

    cout << "TESTS COMPLETED!";
}
