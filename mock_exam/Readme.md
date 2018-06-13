> This is a mock exam in order to demonstrate the type of assignments that could be given in the final lab exam. Note that the solutions for this mock exam will not be checked or graded.

# Mock Exam

General information: Talking, chatting, texting or any other form of live human-human communication is not allowed and may lead to a negative grade. However, you are allowed to use all other offline and online resources such as previous homework solutions, manpages, Stackoverflow, etc.

# Task

Your task is to implement mutual execlusion to shared memory via semaphores for a parent and a child process. For this purpose, you should write a program that does the following:

* The program should attach a **shared memory segment** capable of holding a **single integer** value and initialize it with the value `0`.
* The program should spawn a **child process** that is able to work simultaneously next to the parent process. Furthermore, the child process must have access to the **same shared memory segment**.
* The child process should **increment** the integer value in the shared memory segment **1001 times** and then exit.
* The parent process should **decrement** the integer value **1000 times** and afterwards **wait for the child** process to finish.
* Access to the shared memory segment should be **protected by a semaphore** (you are free to choose between POSIX and System V semaphores - pick whichever you are more comfortable with).
* After waiting for the child to finish, the parent process should **print the content** of the shared memory segment, which should be `1` at this point, and exit.

Note: Your program should hold a comment in the very first line on how to compile it. If it does not compile, you will loose points. Also, if something does not work as expected, provide comments in the source code explaining what you think the problem is. It might improve your grade.

Note: Any calls to `sleep` or similar timer functions are not allowed. Synchronization (e.g. waiting for children) must be achieved with the designated functions and not forced by some time delay.