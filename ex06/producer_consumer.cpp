// compile with e.g. g++ -o producer_consumer producer_consumer.cpp -Wall -Wextra -pedantic

#include <stdlib.h> // provides EXIT_SUCCESS and EXIT_FAILURE

// Note: C++ standard library header files do not have the .h ending
#include <queue> // provides std::queue
#include <iostream> // provides printing with std::cout

// we need a queue that can hold unsigned integer elements
std::queue<unsigned> myQueue;

// print queue information
void printQueue() {
	// print the length of the queue and its front and back elements if available
	std::cout << "lengh: " << myQueue.size();
	if(!myQueue.empty()) {
		std::cout << ", front: " << myQueue.front() << ", back: " << myQueue.back();
	}
	// print a newline
	std::cout << std::endl;
}

// remove elements from the queue if present
void consume() {
	if(!myQueue.empty()) {
		// pop() removes a single element from the front end of the queue
		myQueue.pop();
	} else {
		std::cout << "Sorry, queue is empty!" << std::endl;
	}
}

// add some elements to the queue
void produce() {
	// push() adds a single element to the back of the queue
	myQueue.push(0);
	myQueue.push(42);
	myQueue.push(37);
}

int main() {

	// just playing around a bit to see what happens

	printQueue();

	produce();

	printQueue();

	consume();

	printQueue();

	consume();
	consume();

	printQueue();

	consume();

	return EXIT_SUCCESS;
}
