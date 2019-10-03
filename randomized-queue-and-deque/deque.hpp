#pragma once

#include <list>
#include <random>
#include <algorithm>

template<typename T>
class deque {
public:

    deque() = default;

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }

    class iterator {
    public:
        iterator() = default;

        explicit iterator(const typename std::list<T>::iterator &iter) : iter(iter) {
        }

        iterator(const iterator &other) : iter(other.iter) {
        }

        iterator &operator=(const iterator &other) {
            iter = other.iter;
            return *this;
        }

        iterator operator++(int) {
            iterator it(*this);
            ++iter;
            return it;
        }

        iterator operator--(int) {
            iterator it(*this);
            --iter;
            return it;
        }

        iterator &operator++() {
            ++iter;
            return *this;
        }

        iterator &operator--() {
            --iter;
            return *this;
        }

        iterator &operator+=(int n) {
            iter += n;
            return *this;
        }

        iterator &operator-=(int n) {
            iter -= n;
            return *this;
        }

        iterator operator+(int n) {
            iterator newIter(*this);
            newIter.iter += n;
            return newIter;
        }

        iterator operator-(int n) {
            iterator newIter(*this);
            newIter.iter -= n;
            return newIter;
        }

        bool operator==(const iterator &other) {
            return (iter == other.iter);
        }

        bool operator!=(const iterator &other) {
            return (iter != other.iter);
        }

        T &operator*() {
            return *iter;
        }

        ~iterator() = default;

    private:
        typename std::list<T>::iterator iter;
    };

    typename deque<T>::iterator begin() {
        iterator iter(elements.begin());
        return iter;
    }

    typename deque<T>::iterator end() {
        iterator iter(elements.end());
        return iter;
    }

    void push_front(const T &newElement) {
        elements.push_front(newElement);
    }

    void push_back(const T &newElement) {
        elements.push_back(newElement);
    }

    T &front() {
        return elements.front();
    }

    const T &front() const {
        return elements.front();
    }

    T &back() {
        return elements.back();
    }

    const T &back() const {
        return elements.back();
    }

    void pop_front() {
        if (empty()) {
            throw std::runtime_error("Deque is empty!");
        }

        elements.pop_front();
    }

    void pop_back() {
        if (empty()) {
            throw std::runtime_error("Deque is empty!");
        }

        elements.pop_back();
    }

    ~deque() = default;

private:
    std::list<T> elements;
};
