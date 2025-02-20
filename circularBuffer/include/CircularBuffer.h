#ifndef CIRCULARBUFFER_HPP
#define CIRCULARBUFFER_HPP

#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

#define MIN_BUFFER_SIZE 5
#define MAX_BUFFER_SIZE 25

template <typename T>
class CircularBuffer {
private:
    std::vector<T> buffer;  // Underlying storage
    size_t capacity;        // Maximum capacity of the buffer
    size_t head = 0;        // Index of the first element
    size_t tail = 0;        // Index where the next element will be inserted
    size_t size = 0;        // Current number of elements in the buffer

public:
    // Constructor to initialize the buffer with a minimum capacity
    CircularBuffer() : capacity(MIN_BUFFER_SIZE) {
        buffer.resize(capacity);
    }

    // Constructor to initialize the buffer with a given capacity
    CircularBuffer(size_t capacity_) : capacity(capacity_) {
        //Check the upper and lower bounds
        if (capacity < MIN_BUFFER_SIZE) {
            capacity = MIN_BUFFER_SIZE;
        }
        else if (capacity > MAX_BUFFER_SIZE) {
            capacity = MAX_BUFFER_SIZE;
        }

        buffer.resize(capacity);
    }

    // Check if the buffer is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Check if the buffer is full
    bool isFull() const {
        return size == capacity;
    }

    // Add an element to the buffer
    void enqueue(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Buffer is full");
        }
        buffer[tail] = value;
        tail = (tail + 1) % capacity; // Wrap around if necessary
        size++;
    }

    // Remove and return the oldest element from the buffer
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Buffer is empty");
        }
        T value = buffer[head];
        head = (head + 1) % capacity; // Wrap around if necessary
        size--;
        return value;
    }

    // Peek at the oldest element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Buffer is empty");
        }
        return buffer[head];
    }

    // Display the contents of the buffer
    void display() const {
        std::cout << "Buffer contents: ";
        for (size_t i = 0; i < size; i++) {
            std::cout << buffer[(head + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // CIRCULARBUFFER_HPP
