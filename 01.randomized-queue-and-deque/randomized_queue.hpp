#pragma once

#include <vector>
#include <random>
#include <algorithm>

template<typename T>
class randomized_queue {
public:

    randomized_queue() = default;

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }

    class iterator {
    public:
        iterator() = default;

        iterator(typename std::vector<T>::iterator iter, size_t index, size_t iterSize) :
                iter(iter), index(index), iterSize(iterSize) {
            generatePermutation();
        }

        iterator(const iterator &other) : iter(other.iter), permutation(other.permutation),
                                          index(index), iterSize(other.iterSize) {
        }

        iterator &operator=(const iterator &other) = default;

        iterator operator++(int) {
            iterator it(*this);
            index++;
            return it;
        }

        iterator operator--(int) {
            iterator it(*this);
            index--;
            return it;
        }

        iterator &operator++() {
            ++index;
            return *this;
        }

        iterator &operator--() {
            --index;
            return *this;
        }

        bool operator==(const iterator &other) {
            return (iter + permutation[index] == other.iter + other.permutation[other.index]);
        }

        bool operator!=(const iterator &other) {
            return (iter + permutation[index] != other.iter + other.permutation[other.index]);
        }

        T &operator*() {
            return *(iter + permutation[index]);
        }

        ~iterator() = default;

    private:
        size_t index;

        typename std::vector<T>::iterator iter;

        std::vector<size_t> permutation;

        size_t iterSize;

        void generatePermutation() {
            std::mt19937 generate{std::random_device()()};

            permutation.resize(iterSize);
            for (size_t i = 0; i < iterSize; i++) {
                permutation[i] = i;
            }
            std::shuffle(permutation.begin(), permutation.end(), generate);
            permutation.push_back(iterSize);
        }
    };

    typename randomized_queue<T>::iterator begin() {
        iterator iter(elements.begin(), 0, elements.size());
        return iter;
    }

    typename randomized_queue<T>::iterator end() {
        iterator iter(elements.begin(), elements.size(), elements.size());
        return iter;
    }

    void enqueue(const T &newElement) {
        elements.push_back(newElement);
    }

    T sample() {
        if (empty()) {
            throw std::runtime_error("Queue is empty!");
        }

        int randomIndex = getRandomIndex();
        return elements[randomIndex];
    }

    T dequeue() {
        if (empty()) {
            throw std::runtime_error("Queue is empty!");
        }

        size_t randomIndex = getRandomIndex();
        T returnValue = elements[randomIndex];
        std::swap(elements[randomIndex], elements.back());
        elements.pop_back();

        return returnValue;
    }

    ~randomized_queue() = default;

private:
    std::vector<T> elements;

    size_t getRandomIndex() {
        std::mt19937 generate{std::random_device()()};
        std::uniform_int_distribution<> getRandomNumber(0, elements.size() - 1);

        int randomIndex = getRandomNumber(generate);
        return randomIndex;
    }
};
