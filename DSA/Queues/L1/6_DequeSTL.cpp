#include <iostream>  // for std::cout and std::endl
#include <deque>     // for std::deque

int main() {
    // Create a deque of integers
    std::deque<int> dq;

    // Adding elements to the end of the deque
    dq.push_back(10);  // deque: 10
    dq.push_back(20);  // deque: 10, 20
    dq.push_back(30);  // deque: 10, 20, 30

    // Adding elements to the front of the deque
    dq.push_front(5);  // deque: 5, 10, 20, 30
    dq.push_front(2);  // deque: 2, 5, 10, 20, 30

    // Displaying the elements of the deque
    std::cout << "Deque elements: ";
    for (int elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Accessing elements
    std::cout << "Element at index 2: " << dq[2] << std::endl; // should output 10

    // Removing elements from the front and back
    dq.pop_front(); // deque: 5, 10, 20, 30
    dq.pop_back();  // deque: 5, 10, 20

    // Displaying the elements of the deque after popping
    std::cout << "Deque elements after popping: ";
    for (int elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Checking the size of the deque
    std::cout << "Size of deque: " << dq.size() << std::endl;

    // Clearing all elements in the deque
    dq.clear();
    std::cout << "Size of deque after clearing: " << dq.size() << std::endl;

    return 0;
}
