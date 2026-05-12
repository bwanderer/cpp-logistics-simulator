# Logistics Simulator — C++

Two programs that simulate and optimize physical loading and packing operations, 
built using algorithmic logic without any external libraries.

## Programs

### Truck Trip Optimizer
Calculates the minimum number of truck trips needed to transport packages of 
100, 200, and 300 lbs without splitting packages or exceeding a 300 lb truck 
capacity. Uses integer division and a greedy pairing algorithm to minimize trips.

### Truck Loading Simulator
Simulates loading items onto trucks in real time. Accepts items of fixed weights 
(10, 20, or 30 lbs), fills trucks sequentially, and overflows to the next truck 
when capacity is reached. Visualizes each truck's load as a binary grid (1 = 
filled, 0 = empty).

## What it demonstrates

- Algorithm design (greedy optimization, bin packing logic)
- 2D arrays and binary state representation
- Input validation and error handling
- Nested loops and conditional control flow
- Modular code with helper functions

## How to run

```bash
g++ truck_trip_optimizer.cpp -o optimizer
./optimizer

g++ truck_loading_simulator.cpp -o simulator
./simulator
```

Requires a C++ compiler (g++ or clang++).

## Technologies

C++17 · Standard Library (`iostream`, `iomanip`)
