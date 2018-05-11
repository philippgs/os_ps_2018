# Exercise Sheet 6

In this exercise sheet you will use POSIX threads and test out different methods for mutual exclusion and synchronization.

# Task 1

Write a program which spawns 10 threads. 

* Each thread waits for a random time between 0 and 3 seconds, then creates a file called `threadN.txt` (where `N` is the thread number between 0 and 9) and writes its thread id (returned by `gettid`) to this file. Ensure that the file is closed in case a thread opens it and is subsequently interrupted (study the `pthread_cleanup` family of functions).
* After spawning all threads, the main program decides for each thread whether to randomly cancel it, with a chance of cancellation of 50%.
* Afterwards, the main program waits for all threads to exit. 

# Task 2

In this exercise you will implement a single producer multiple consumer pattern. 

Your program should spawn 5 threads, the *consumers*, which all try to read elements from a queue. Queued elements are of type `unsigned`.

> Note:  You can use e.g. the C++ `std::queue` (a short example demonstrating its usage is provided in [producer_consumer.cpp](producer_consumer.cpp)) or the basic C queue that is provided in [myqueue.h](myqueue.h) (a short example demonstrating its usage is provided in [producer_consumer.c](producer_consumer.c)).

* When a consumer thread successfully reads an element, it adds it to its local `sum`. When the element is 0, it prints out the sum and exits.

* The main thread acts as the *producer*. After spawning all 5 consumers, it feeds 10.000 `1` entries into the queue, followed by 5 `0` entries.

Access to the queue should be protected by using the `pthread_mutex` facilities.
