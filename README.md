# D/D/1 Queueing System Simulation in C

## Project Overview

This project implements a discrete-event simulation of a D/D/1 single-server queueing system using the C programming language.

The simulation models the arrival of clients, their waiting time, service process, and departure from the system.

## System Description

The D/D/1 model represents a queueing system with:

- **D (Deterministic Arrivals):** Clients arrive at fixed time intervals.
- **D (Deterministic Service):** Each client requires a fixed service time.
- **1 (Single Server):** Only one server is available to serve clients.

## Features

- Client management using a FIFO queue.
- Event scheduling and processing.
- Arrival, service-start, and departure events.
- Discrete-event simulation.
- Performance statistics calculation.

## Performance Metrics

The simulation calculates:

- **Mean Response Time:** Average time a client spends in the system.
- **Mean Waiting Time:** Average time a client waits before service.
- **Throughput:** Number of clients served per unit of simulation time.

## Project Structure

```text
.
├── events/
├── Global_vars/
├── simulation/
├── statistics/
└── main.c
```

## Simulation Parameters

| Parameter | Value |
|---|---:|
| Interarrival Time | 6 seconds |
| Service Time | 5 seconds |
| Number of Servers | 1 |

## Compilation and Execution

Compile the project using GCC:

```bash
gcc -g -Wall -Wextra main.c events/events.c Global_vars/system.c simulation/simulation.c statistics/statistic.c -o main
```

Run the simulation:

```bash
./main
```

## Technologies

- C Programming Language
- GCC Compiler
- Linux

## Academic Context

Developed as part of a university practical assignment on queueing systems and discrete-event simulation.


GitHub: [@OffcGrid](https://github.com/OffcGrid)
