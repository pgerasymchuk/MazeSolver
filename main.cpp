#include <string>
#include <iostream>
#include "FileReader.h"
#include "Parser.h"
#include "MazeSolver.h"
#include "Maze.h"
using namespace std;

int main() {
    string inputFilePath = "data/input.txt";
    string outputFilePath = "data/output.txt";
    pair<int,int> startCoords, endCoords;
    cout<<"Enter start coordinates: "; cin>>startCoords.first>>startCoords.second;
    cout<<"Enter end coordinates: "; cin>>endCoords.first>>endCoords.second;
    try {
        FileReader reader;
        Parser parser;
        Maze maze(parser.parse(reader.read(inputFilePath)));
        MazeSolver mazeSolver(maze);
        vector<int> path = mazeSolver.solve(startCoords, endCoords);
        reader.write(outputFilePath, parser.serialize(maze.draw(path)));
    }
    catch (exception& e){
        cout<<e.what()<<endl;
    }
    catch (vector<string> errMessages) {
        for (string s : errMessages){
            cout<<s<<endl;
        }
    }
}