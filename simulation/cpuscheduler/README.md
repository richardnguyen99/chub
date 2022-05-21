# CPU Scheduling

> CPU scheduling is the basis of multiprogrammed operating systems. By switching the CPU among processes, the operating system can make the computer more productive <br><br><span>&mdash;&nbsp;Operating System Concepts, 9th edition - Chapter 6</span>

## Objectives

- Introduction to **process scheduling**
- Replicate various CPU-scheduling algorithms
- Analyze criteria for selecting a CPU-scheduling algorithm

## Introduction

This project introduces some common CPU-scheduling algorithms and some simulations to demonstrate how they work

### Design

Driver `scheduler.c` contains the main program to execute the scheduling simulation. The driver takes at least two arguments, _file_ that contains a list of process, including essential information, and one selected _CPU-scheduling algorithm_.

The driver also provides some other options to interact with the algorithms if applicable. The function employs `getopt.h` to

### First-come, First-serve (FCFS) scheduling

**First-come, First-serve** is the simplest scheduling algorithm. As the name suggested, the process that requests the CPU first is allocated the CPU first.

Given a FIFO (first-in, first-out) queue, the FCFS scheduling algorithm will allocate CPU to the first process in the queue. The process moves to running state then is removed from the queue.

Example:

    # Ready queue
    1 24
    2 3
    3 3
    4 7
    1 16
    2 13

    # Output
    Process 1 is running: 24 seconds
    Process 2 is running: 3 seconds
    Process 3 is running: 3 seconds
    Process 4 is running: 7 seconds
    Process 1 is running: 16 seconds
    Process 2 is running: 13 seconds

    Avg. waiting time: 7 seconds

## Run

1. Build and run

```sh
make
./scheduler [OPTIONS] [FILES]

# optional
make clean
```

2. For more options

```sh
./scheduler --help
```
