#include "MazeSolver.h"

MazeSolver::MazeSolver(Maze maze) : maze(maze) {}

// Manhattan distance between two cells: the exact cost of a path without walls,
// so it never overestimates and A* still returns the shortest path
int MazeSolver::heuristic(int vertex, int target){
    int width = maze.getWidth();
    return abs(vertex / width - target / width) + abs(vertex % width - target % width);
}

vector<int> MazeSolver::findPath(pair<int,int> sourceCoords, pair<int,int> targetCoords, Algorithm algorithm){
    int width = maze.getWidth();
    int height = maze.getHeight();
    int length = width * height;
    int source = sourceCoords.first * width + sourceCoords.second;
    int target = targetCoords.first * width + targetCoords.second;
    vector<int> path;
    vector<int> dist(length,0);
    vector<int> prev(length,-1);
    // Dijkstra orders cells by distance from the source,
    // A* by distance from the source plus the estimated distance to the target;
    // on equal estimates A* prefers the cell closer to the target
    auto priority = [&](int v, int distance) -> long long {
        if (algorithm == Algorithm::Dijkstra){
            return distance;
        }
        int h = heuristic(v, target);
        return (long long)(distance + h) * length + h;
    };
    expandedCells = 0;
    PriorityQueue<Cell> pq;
    pq.push(Cell(source,priority(source,0)));
    dist[source] = 0;
    for (int i=0;i<length;i++){
        if (i != source){
            dist[i] = INF;
        }
    }
    while (! pq.empty()){
        Cell uCell = pq.top();
        pq.pop();
        int u = uCell.vertex;
        if (uCell.distance == priority(u,dist[u])){ //skip outdated queue entries
            expandedCells++;
            if (u == target){
                while(u != -1){
                    path.push_back(u);
                    u = prev[u];
                }
                reverse(path.begin(), path.end());
                return path;
            }
            vector<int> uNeighbours = maze.getNeighbours(u);
            for (int v : uNeighbours){
                int altDist = dist[u] + 1;
                if (altDist < dist[v]){
                    dist[v] = altDist;
                    prev[v] = u;
                    pq.push(Cell(v,priority(v,altDist)));
                }
            }
        }
    } 
    return path;
}

vector<int> MazeSolver::solve(pair<int,int> sourceCoords, pair<int,int> targetCoords, Algorithm algorithm){
    if (isValidCoords(sourceCoords) && isValidCoords(targetCoords)){
        vector<int> path = findPath(sourceCoords,targetCoords,algorithm);
        if (path.empty()){
            throw runtime_error("No path exists between source and target!");
        }
        return path;
    }
    else {
        throw runtime_error("Coordinates are not correct!");
    }
}


bool MazeSolver::isValidCoords(pair<int,int> coords){
    if (coords.first<0 || coords.first>=maze.getHeight() || coords.second<0 || coords.second>=maze.getWidth() || !maze.isFreeCell(coords)){
        return 0;
    }
    return 1;
}

int MazeSolver::getExpandedCells(){
    return expandedCells;
}
