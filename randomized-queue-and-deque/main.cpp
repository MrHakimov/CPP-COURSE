#include <iostream>
#include "deque.hpp"
#include "randomized_queue.hpp"

bool areAllTestsPassed = true;

#define EXPECT(result, message) \
    do { \
        if (!(result)) { \
            areAllTestsPassed = false; \
            std::cerr << __FILE__ << ":" << __LINE__ << " " << message << std::endl; \
            return; \
        } \
    } while (false)

void testEmpty() {
    randomized_queue<std::string> randomizedQueue;
    EXPECT(randomizedQueue.empty(), "Randomized queue would be empty!");

    deque<std::string> deque;
    EXPECT(deque.empty(), "Deque would be empty!");
}

void testSize() {
    randomized_queue<std::string> stringQueue;
    for (size_t i = 1; i <= 25; i++) {
        stringQueue.enqueue(std::to_string(i));
    }
    EXPECT(stringQueue.size() == 25, "Size of queue of string-type is incorrect!");

    randomized_queue<int> intQueue;
    for (int i = -5; i < 5; i++) {
        intQueue.enqueue(i);
    }
    EXPECT(intQueue.size() == 10, "Size of queue of integer-type is incorrect!");

    randomized_queue<std::vector<char>> vectorQueue;
    for (size_t i = 97; i < 123; i++) {
        vectorQueue.enqueue({(char) i});
    }
    EXPECT(vectorQueue.size() == 26, "Size of queue of vectors if incorrect!");

    deque<std::string> stringDeque;
    for (size_t i = 1; i <= 25; i++) {
        stringDeque.push_back(std::to_string(i));
    }
    EXPECT(stringDeque.size() == 25, "Size of deque of string-type is incorrect!");

    stringDeque = deque<std::string>();
    for (size_t i = 1; i <= 25; i++) {
        stringDeque.push_front(std::to_string(i));
    }
    EXPECT(stringDeque.size() == 25, "Size of deque of string-type is incorrect!");

    deque<int> intDeque;
    for (int i = -5; i < 5; i++) {
        intDeque.push_back(i);
    }
    EXPECT(intDeque.size() == 10, "Size of deque of integer-type is incorrect!");

    intDeque = deque<int>();
    for (int i = -5; i < 5; i++) {
        intDeque.push_front(i);
    }
    EXPECT(intDeque.size() == 10, "Size of deque of integer-type is incorrect!");

    deque<std::vector<char>> vectorDeque;
    for (size_t i = 97; i < 123; i++) {
        vectorDeque.push_back({(char) i});
    }
    EXPECT(vectorDeque.size() == 26, "Size of deque of vectors if incorrect!");

    vectorDeque = deque<std::vector<char>>();
    for (size_t i = 97; i < 123; i++) {
        vectorDeque.push_back({(char) i});
    }
    EXPECT(vectorDeque.size() == 26, "Size of deque of vectors if incorrect!");
}

void testSample() {
    randomized_queue<bool> queue;
    for (size_t i = 0; i < 15; i++) {
        queue.enqueue(i % 3 == 0);
    }

    int queueSize = queue.size();
    bool element = queue.sample();
    EXPECT(element == 0 || element == 1, "Returned element should have boolean-type!");
    EXPECT(queueSize == queue.size(), "Size of queue should not change after \"sample\"-operation!");

    deque<bool> deque;
    for (size_t i = 0; i < 15; i++) {
        deque.push_back(i % 3 == 0);
    }

    int dequeSize = deque.size();
    element = deque.front();
    EXPECT(element == 0 || element == 1, "Returned element should have boolean-type!");
    element = deque.back();
    EXPECT(element == 0 || element == 1, "Returned element should have boolean-type!");
    EXPECT(dequeSize == deque.size(), "Size of deque should not change after \"sample\"-operation!");

    deque = ::deque < bool > ();
    for (size_t i = 0; i < 15; i++) {
        deque.push_front(i % 3 == 0);
    }

    dequeSize = queue.size();
    element = deque.front();
    EXPECT(element == 0 || element == 1, "Returned element should have boolean-type!");
    element = deque.back();
    EXPECT(element == 0 || element == 1, "Returned element should have boolean-type!");
    EXPECT(dequeSize == deque.size(), "Size of deque should not change after \"sample\"-operation!");
}

void testEnqueue() {
    randomized_queue<char> randomizedQueue;

    for (size_t i = 0; i < 1000; i++) {
        randomizedQueue.enqueue(i + 1);
    }

    EXPECT(randomizedQueue.size() == 1000, "Queue size should be equal to 1000!");

    int counter = 0;
    for (auto _ : randomizedQueue) {
        counter++;
    }
    EXPECT(counter == 1000, "Queue size should not be changed after iteration on it!");

    counter = 0;
    auto iter = randomizedQueue.begin();
    while (iter != randomizedQueue.end()) {
        counter++;
        iter++;
    }
    EXPECT(counter == 1000, "Queue size should not be changed after iteration on it!");

    counter = 0;
    iter = randomizedQueue.begin();
    while (iter != randomizedQueue.end()) {
        counter++;
        ++iter;
    }
    EXPECT(counter == 1000, "Queue size should not be changed after iteration on it!");

    deque<char> deque;

    for (size_t i = 0; i < 1000; i++) {
        deque.push_back(i + 1);
    }

    EXPECT(deque.size() == 1000, "Queue size should be equal to 1000!");

    counter = 0;
    for (auto _ : deque) {
        counter++;
    }
    EXPECT(counter == 1000, "Deque size should not be changed after iteration on it!");

    counter = 0;
    auto dequeIter = deque.begin();
    while (dequeIter != deque.end()) {
        counter++;
        dequeIter++;
    }
    EXPECT(counter == 1000, "Deque size should not be changed after dequeIteration on it!");

    counter = 0;
    dequeIter = deque.begin();
    while (dequeIter != deque.end()) {
        counter++;
        ++dequeIter;
    }
    EXPECT(counter == 1000, "Deque size should not be changed after dequeIteration on it!");

    deque = ::deque < char > ();

    for (size_t i = 0; i < 1000; i++) {
        deque.push_front(i + 1);
    }

    EXPECT(deque.size() == 1000, "Queue size should be equal to 1000!");

    counter = 0;
    for (auto _ : deque) {
        counter++;
    }
    EXPECT(counter == 1000, "Deque size should not be changed after iteration on it!");

    counter = 0;
    dequeIter = deque.begin();
    while (dequeIter != deque.end()) {
        counter++;
        dequeIter++;
    }
    EXPECT(counter == 1000, "Deque size should not be changed after dequeIteration on it!");

    counter = 0;
    dequeIter = deque.begin();
    while (dequeIter != deque.end()) {
        counter++;
        ++dequeIter;
    }
    EXPECT(counter == 1000, "Deque size should not be changed after dequeIteration on it!");
}

void testDequeue() {
    randomized_queue<int> queue;
    unsigned int forAdd = 101;
    for (size_t i = 0; i < forAdd; i++) {
        queue.enqueue(10000);
    }

    unsigned int forDelete = queue.size();
    for (size_t i = 0; i < forDelete; i++) {
        queue.dequeue();
    }
    EXPECT(queue.size() == forAdd - forDelete, "Size became incorrect after 'dequeue's!");

    queue = randomized_queue<int>();
    forAdd = 101;
    for (size_t i = 0; i < forAdd; i++) {
        queue.enqueue(10000);
    }

    forDelete = queue.size() - 18;
    for (size_t i = 0; i < forDelete; i++) {
        queue.dequeue();
    }
    EXPECT(queue.size() == forAdd - forDelete, "Size became incorrect after 'dequeue's!");

    deque<int> deque;
    forAdd = 101;
    for (size_t i = 0; i < forAdd; i++) {
        deque.push_back(10000);
    }

    forDelete = deque.size();
    for (size_t i = 0; i < forDelete; i++) {
        deque.pop_back();
    }
    EXPECT(deque.size() == forAdd - forDelete, "Size became incorrect after 'dedeque's!");

    deque = ::deque < int > ();
    forAdd = 101;
    for (size_t i = 0; i < forAdd; i++) {
        deque.push_back(10000);
    }

    forDelete = deque.size() - 18;
    for (size_t i = 0; i < forDelete; i++) {
        deque.pop_front();
    }
    EXPECT(deque.size() == forAdd - forDelete, "Size became incorrect after 'pop's!");
}

void testIterators() {
    randomized_queue<std::string> randomizedQueue;
    for (size_t i = 0; i < 123; i++) {
        randomizedQueue.enqueue(std::to_string(i));
    }

    auto iter = randomizedQueue.begin();
    std::vector<std::string> v1;
    for (const auto &element : randomizedQueue) {
        v1.push_back(element);
    }

    std::vector<std::string> v2;
    for (const auto &element : randomizedQueue) {
        v2.push_back(element);
    }

    EXPECT(v1 == v2, "The same iterators should return same sequences!");

    deque<std::string> deque;
    for (size_t i = 0; i < 123; i++) {
        deque.push_front(std::to_string(i));
    }

    auto dequeIter = deque.begin();
    v1 = std::vector<std::string>();
    for (const auto &element : deque) {
        v1.push_back(element);
    }

    v2 = std::vector<std::string>();
    for (const auto &element : deque) {
        v2.push_back(element);
    }

    EXPECT(v1 == v2, "The same iterators should return same sequences!");
}

int main() {
    testEmpty();
    testSize();
    testSample();
    testEnqueue();
    testDequeue();
    testIterators();

    if (areAllTestsPassed) {
        std::cout << "Tests completed successfully!" << std::endl;
    } else {
        std::cout << "Tests FAILED!" << std::endl;
    }
}
