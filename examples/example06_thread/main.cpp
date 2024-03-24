#include <iostream>
#include <thread>
#include <chrono>

int counter = 0;

// Function to be executed by each thread
void printHello(int thread_index) {
    while(true) {
        std::cout << "Hello, World! from thread" << thread_index << " counter=" << counter << std::endl;
        ++counter;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
}

int main() {
    // Create two threads
    std::thread thread1(printHello, 0);
    std::thread thread2(printHello, 1);

    // Wait for both threads to finish
    thread1.detach();
    thread2.detach();
    
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    return 0;
}
