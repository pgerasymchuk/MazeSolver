#include "MazeSolver.h"

MazeSolver::MazeSolver(Maze maze) : maze(maze) {}

vector<int> MazeSolver::findPath(pair<int,int> sourceCoords, pair<int,int> targetCoords){
    int width = maze.getWidth();
    int height = maze.getHeight();
    int length = width * height;
    int source = sourceCoords.first * width + sourceCoords.second;
    int target = targetCoords.first * width + targetCoords.second;
    vector<int> path;
    vector<int> dist(length,0);
    vector<int> prev(length,-1);
    PriorityQueue<Cell> pq;
    pq.push(Cell(source,0));
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
        if (uCell.distance == dist[u]){
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
                    pq.push(Cell(v,altDist));
                }
            }
        }
    } 
    return path;
}

vector<int> MazeSolver::solve(pair<int,int> sourceCoords, pair<int,int> targetCoords){
    if (isValidCoords(sourceCoords) && isValidCoords(targetCoords)){
        vector<int> path = findPath(sourceCoords,targetCoords);
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