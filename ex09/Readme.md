# Exercise Sheet 9

In this exercise sheet you will use POSIX threads and perform different types of memory management within them.


# Task 1

Create an application `membench T N S` which launches a configurable (program launch parameter `T`) number of threads. 
Each thread should perform a given number of memory allocations and deallocations (`N`) of a given size in bytes (`S`).

For example
```
./membench 8 10000 1024
```
would launch 8 threads, each of which performs 10000 allocations of 1 kiB each.


# Task 2

Implement a naive *best fit* memory allocator (see lecture slides) and use it in your application.
The allocator should provide its own versions of the `malloc` and `free` functions.

Create 2 versions, one which uses a global allocator (which of course needs to be locked when used), and one which uses a local allocator for each thread. For creating local instances of the allocator, you can use thread-local storage using `__thread` (see e.g. http://gcc.gnu.org/onlinedocs/gcc-7.3.0/gcc/Thread-Local.html for further information)

Compare their performance in "membench", with a few different numbers of threads and allocation sizes, and a number of allocations/deallocations that gives a reasonable total runtime (more than a second and less than a minute).
