#include "Maze.h"

Maze::Maze(vector<vector<char>> value){
    vector<string> errors = validateInputData(value);
    if (errors.empty()){
        height = value.size();
        width = value[0].size();
        for (int i=0;i<height;i++){
            vector<bool> row;
            for (int j=0;j<width;j++){
                row.push_back(value[i][j] == WALL);
            }
            data.push_back(row);
        }
    }
    else {
        throw errors;
    }
}

vector<string> Maze::validateInputData(vector<vector<char>> matr){
    vector<string> errors;
    int rowsNumber = matr.size();
    if (matr.empty()){
        throw invalid_argument("Input maze is empty!");
    }
    int rowLength = matr[0].size();
    for (int i=1;i<rowsNumber;i++){
        vector<char> row = matr[i];
        if (row.size() != rowLength){
            string errMessage = "Incorrect number of characters in line "+to_string(i);
            errors.push_back(errMessage);
        }
        for (int j=0;j<row.size();j++){
            vector<char>::iterator it = find(validChars.begin(),validChars.end(),row[j]);
            if (it == validChars.end()){
                string errMessage = string("Incorrect char '") + row[j] + string("' in line ")+to_string(i)+" on place "+to_string(j);
                errors.push_back(errMessage);
            } 
        }
    }
    return errors;
}

vector<int> Maze::getNeighbours(int vertex){
    vector<int> neighbours;
    if (vertex == -1){
        return neighbours;
    }
    pair<int,int> vertexCoords = getCoords(vertex);
    if (vertexCoords.first != 0){ //not in the first row
        int neighbour = vertex - data[0].size();
        pair<int,int> neighbourCoords = getCoords(neighbour);
        if (! data[neighbourCoords.first][neighbourCoords.second]){ //SPACE
            neighbours.push_back(neighbour);
        }
    }
    if (vertexCoords.first != data.size()-1){ //not in the last row
        int neighbour = vertex + data[0].size();
        pair<int,int> neighbourCoords = getCoords(neighbour);
        if (! data[neighbourCoords.first][neighbourCoords.second]){ //SPACE
            neighbours.push_back(neighbour);
        }
    }
    if (vertexCoords.second != 0){ //not in the first column
        int neighbour = vertex - 1;
        pair<int,int> neighbourCoords = getCoords(neighbour);
        if (! data[neighbourCoords.first][neighbourCoords.second]){ //SPACE
            neighbours.push_back(neighbour);
        }
    }
    if (vertexCoords.second != data[0].size()-1){ //not in the last column
        int neighbour = vertex + 1;
        pair<int,int> neighbourCoords = getCoords(neighbour);
        if (! data[neighbourCoords.first][neighbourCoords.second]){ //SPACE
            neighbours.push_back(neighbour);
        }
    }
    return neighbours;
} 


pair<int,int> Maze::getCoords(int vertex){
    return pair<int,int> (vertex/width, vertex % width);
}

vector<vector<char>> Maze::draw(){
    vector<vector<char>> matrix;
    for (int i=0;i<height;i++){
        vector<char> row;
        for (int j=0;j<width;j++){
            row.push_back(data[i][j] ? WALL : SPACE);
        }
        matrix.push_back(row);
    }
    return matrix;
}

vector<vector<char>> Maze::draw(vector<int> path){
    vector<vector<char>> matrix = draw();
    for (int i=0;i<path.size();i++){
        pair<int,int> coords = getCoords(path[i]);
        matrix[coords.first][coords.second] = PATH_SYMBOLS[i % PATH_SYMBOLS.size()];
    }
    return matrix;
}

int Maze::getWidth(){
    return width;
}

int Maze::getHeight(){
    return height;
}

bool Maze::isFreeCell(pair<int,int> coords){
    return !data[coords.first][coords.second];
}