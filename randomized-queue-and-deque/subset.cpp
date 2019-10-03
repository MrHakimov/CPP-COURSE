#include <iostream>
#include "randomized_queue.hpp"

int main(int argc, char **argv) {
    randomized_queue<std::string> randomizedQueue;
    char *buffer;
    int k = std::strtol(argv[1], &buffer, 10);
    std::string s;
    while (std::getline(std::cin, s)) {
        randomizedQueue.enqueue(s);
    }

    for (int i = 0; i < k; i++) {
        std::cout << randomizedQueue.dequeue() << ' ';
    }
    return 0;
}
