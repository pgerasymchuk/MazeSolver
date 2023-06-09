# MazeSolver - a C++ Library for solving the Shortest Path Problem

A C++ library for solving maze puzzles using **Dijkstra’s Algorithm** with an extensible design that can also support **A\*** (A‑Star) search.  
It reads maze definitions from text files, validates them, and computes the shortest path between two coordinates.  

## 🚀 Aim of the Project

The project demonstrates practical implementation of shortest‑path algorithms in grid environments.  
It provides a modular codebase that is easy to understand, extend, and integrate into larger systems.  


## 🛠 Implementation Details

The library is built around several key components working together:
- File input/output utilities for reading and writing maze files.  
- A parser to convert text representations into an internal matrix format.  
- Maze representation with validation, neighbor lookup, and visualization functions.  
- A solver implementing Dijkstra’s algorithm, using a custom priority queue for efficiency.  

The modular design makes it straightforward to replace or extend the solver with other algorithms such as A*.  


## 📊 Algorithm Comparison

### Dijkstra’s Algorithm
- Explores all nodes in increasing order of distance.  
- Guarantees the shortest path in uniform grids.  
- Complexity: **O(V log V + E)** with a binary heap.  

### A* Search
- Uses heuristics (e.g., Manhattan distance) to reduce unnecessary exploration.  
- Guarantees shortest path while typically exploring fewer nodes.  
- More efficient in large mazes.  

| Algorithm | Explored Nodes | Optimal Path Guarantee | Typical Speed |
|-----------|----------------|-------------------------|---------------|
| Dijkstra  | High (broad search) | ✅ Yes | Moderate |
| A*        | Lower (guided search) | ✅ Yes | Faster |


## ⚙️ Running Locally

### 1. Build
Use a C++17 compatible compiler. Example:

```bash
g++ -std=c++17 -o maze_solver main.cpp Cell.cpp FileReader.cpp Parser.cpp Maze.cpp MazeSolver.cpp PriorityQueue.cpp
```

### 2. Run
Provide the input and output file paths:

```bash
./maze_solver input.txt output.txt
```

Then enter the start and end coordinates when prompted:

```
Enter start coordinates (x y): 0 0
Enter end coordinates (x y): 4 6
```

The solved maze will be written to the output file.  


## 📝 Input / Output Format

- **Input file**: maze represented with `#` for walls and `.` for free space, separated by spaces.  
- **Output file**: same maze with the path marked using sequential characters (`0–9`, `a–z`, …).  

### Example

**Input**
```
# # # # #
# . . . #
# # . # #
# . . . #
# # # # #
```

**Output**
```
# # # # #
# 0 1 2 #
# # 3 # #
# 5 4 3 #
# # # # #
```


## 🌟 Highlights

- Custom priority queue for didactic performance control.  
- Clear separation of components (parsing, maze handling, solving).  
- Straightforward extensibility to add more algorithms.  
- Useful for testing, demonstrations, or as a building block in larger projects.  


## 🔮 Future Improvements

- Add **A*** implementation with heuristics.  
- Benchmark performance across algorithms.  
- Add visualization of the solving process.  
- Extend to weighted mazes with varying traversal costs.  
