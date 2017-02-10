# Lab 5
-----
### Part 1 : Hello World
* Build and compiled
* test case alarm-multiple ran sucessfully
* print-something test case made source is `print-something.c` and entry point is `test_print-something` 
![execution](1.png)

### Part 2 : Using Threads
* Created thread which sorts a random array of integers using `thread_create()` all which can be observed in the self documented code in the source file `sort-random`.
* 
* Used List API to store and sort random values.
![execution](2.png)

### Part 3 : Understanding Threads
To use threads in pintos we have a predefined library in `src/threads/`. In this directory a file threads.c exists here definitions of many functions and structures implementing threads exists.

The first function of interest is `thread_create()` this makes a new thread and adds it to the processes list. This function even if it takes priority as a parameter it doesn't use it to schedule a thread. It's just a simple FIFO process scheduler.

A function which could pause the thread and let another thread execute is `thread_yield`. This is also used by `timer_sleep()` in devices/timer.c which is used in the alarm-multiple program.

`thread_exit()` as the name suggests exits from the thread without returning any value.

The thread library uses the list library in `libs/kernel/list.c`.