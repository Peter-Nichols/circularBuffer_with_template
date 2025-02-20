
#include <iostream>

#include "CircularBuffer.h"

int main(int rgc, char* argv[])
{
    // Create a circular buffer with a capacity of 5 for integers
    CircularBuffer<int> intBuffer(5);

    // Enqueue elements
    intBuffer.enqueue(10);
    intBuffer.enqueue(20);
    intBuffer.enqueue(30);
    intBuffer.display(); // Output: Buffer contents: 10 20 30

    // Dequeue an element
    std::cout << "Dequeued: " << intBuffer.dequeue() << std::endl; // Output: Dequeued: 10
    intBuffer.display(); // Output: Buffer contents: 20 30

    // Enqueue more elements
    intBuffer.enqueue(40);
    intBuffer.enqueue(50);
    intBuffer.enqueue(60);
    intBuffer.display(); // Output: Buffer contents: 20 30 40 50 60

    // Try to enqueue when the buffer is full
    try {
        intBuffer.enqueue(70);
    } catch (const std::overflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl; // Output: Error: Buffer is full
    }

    // Dequeue all elements
    while (!intBuffer.isEmpty()) {
        std::cout << "Dequeued: " << intBuffer.dequeue() << std::endl;
    }

    // Try to dequeue when the buffer is empty
    try {
        intBuffer.dequeue();
    } catch (const std::underflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl; // Output: Error: Buffer is empty
    }

    // Create a circular buffer with a capacity of 5 for double
    CircularBuffer<double> doubleBuffer(5);

    // Enqueue elements
    doubleBuffer.enqueue(100.5);
    doubleBuffer.enqueue(100.6);
    doubleBuffer.enqueue(100.7);
    doubleBuffer.display(); // Output: Buffer contents: 100.5 100.6 100.7

    // Dequeue an element
    std::cout << "Dequeued: " << doubleBuffer.dequeue() << std::endl; // Output: Dequeued: 100.5
    doubleBuffer.display(); // Output: Buffer contents: 100.5 100.6

    // Enqueue more elements
    doubleBuffer.enqueue(100.8);
    doubleBuffer.enqueue(100.9);
    doubleBuffer.enqueue(101.1);
    doubleBuffer.display(); // Output: Buffer contents: 20 30 40 50 60

    // Create a circular buffer with a capacity of 3 for strings
    CircularBuffer<std::string> stringBuffer(3);

    // Enqueue elements
    stringBuffer.enqueue("Hello");
    stringBuffer.enqueue("World");
    stringBuffer.enqueue("!");
    stringBuffer.display(); // Output: Buffer contents: Hello World !

    // Dequeue an element
    std::cout << "Dequeued: " << stringBuffer.dequeue() << std::endl; // Output: Dequeued: Hello
    stringBuffer.display(); // Output: Buffer contents: World !

    return 0;
}
