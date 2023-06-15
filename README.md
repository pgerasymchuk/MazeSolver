# 🧭 MazeSolver — Dijkstra and A* in C++

A small C++ library and command-line tool that finds the shortest path through a grid maze. It reads a maze from a text file, validates it, solves it with **Dijkstra's algorithm** or **A\*** and writes the maze back with the path drawn on it.

## 🛠 How it works

- **`FileReader`** reads and writes the maze files, **`Parser`** turns the text into a character matrix and back.
- **`Maze`** validates the input (rectangular shape, allowed symbols), stores walls as a boolean grid and returns the free neighbours of a cell (4-connected).
- **`MazeSolver`** runs the search. Every cell is a graph vertex and every move costs 1.
- **`PriorityQueue`** is my own binary-heap template used by both algorithms.

### Dijkstra vs A*

Both algorithms share one implementation and differ only in the priority of a cell in the queue:

| Algorithm | Priority | Result |
|---|---|---|
| Dijkstra | `g(n)` — distance from the start | shortest path, explores evenly in all directions |
| A* | `g(n) + h(n)`, `h` = Manhattan distance to the target | shortest path, explores towards the target |

The Manhattan distance never overestimates the remaining cost on a 4-connected grid, so A* still returns an optimal path. When two cells have the same estimate, A* takes the one closer to the target, which keeps it from spreading out in open areas. Outdated queue entries are skipped instead of using a decrease-key operation.

### 📊 Comparison

Number of cells expanded before the target is reached (both find paths of the same length):

| Maze | Path length | Dijkstra | A* |
|---|---|---|---|
| `data/input.txt` (8×8) | 13 | 19 | 16 |
| `data/large_input.txt` (21×21, corridors) | 62 | 264 | 203 |
| `data/open_input.txt` (21×21, empty room) | 36 | 361 | 37 |

## ⚙️ Build and run

```bash
g++ -std=c++17 -O2 -o maze_solver main.cpp Cell.cpp FileReader.cpp Parser.cpp Maze.cpp MazeSolver.cpp
./maze_solver data/large_input.txt output.txt astar
```

The third argument is `astar` (default) or `dijkstra`. The program asks for the start and end cells as `row column` (0-based):

```
Enter start coordinates (x y): 1 1
Enter end coordinates (x y): 19 19
Maze solved with A*: path length 62, expanded cells 203
Output written to output.txt
```

## 📝 File format

`X` is a wall, a space is a free cell, symbols in a row are separated by single spaces. In the output the path is marked with `0–9`, `a–z`, `A–Z` (the sequence repeats on long paths).

```
input.txt                  output.txt (start 6 1, end 5 5)
X X X X X X X X            X X X X X X X X
X       X X   X            X 5 6 7 X X   X
X   X   X X   X            X 4 X 8 X X   X
X   X         X            X 3 X 9 a b   X
X   X   X   X X            X 2 X   X c X X
X   X   X   X X            X 1 X   X d X X
X   X       X X            X 0 X       X X
X X X X X X X X            X X X X X X X X
```

## 🛠️ Tech stack

C++17 · STL · custom binary heap · no external dependencies
