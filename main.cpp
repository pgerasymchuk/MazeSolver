#include <string>
#include <iostream>
#include <cstdlib>
#include "FileReader.h"
#include "Parser.h"
#include "MazeSolver.h"
#include "Maze.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3 && argc != 4) {
        cerr << "Usage: " << argv[0] 
             << " <input_file_path> <output_file_path> [dijkstra|astar]" << endl;
        return 1;
    }

    string inputFilePath = argv[1];
    string outputFilePath = argv[2];
    string algorithmName = argc == 4 ? argv[3] : "astar";
    if (algorithmName != "dijkstra" && algorithmName != "astar") {
        cerr << "Unknown algorithm: " << algorithmName << " (use dijkstra or astar)" << endl;
        return 1;
    }
    Algorithm algorithm = algorithmName == "astar" ? Algorithm::AStar : Algorithm::Dijkstra;

    pair<int, int> startCoords, endCoords;
    
    cout << "Enter start coordinates (x y): ";
    cin >> startCoords.first >> startCoords.second;

    cout << "Enter end coordinates (x y): ";
    cin >> endCoords.first >> endCoords.second;

    try {
        FileReader reader;
        Parser parser;
        Maze maze(parser.parse(reader.read(inputFilePath)));

        MazeSolver mazeSolver(maze);
        vector<int> path = mazeSolver.solve(startCoords, endCoords, algorithm);

        reader.write(outputFilePath, parser.serialize(maze.draw(path)));

        cout << "Maze solved with " << (algorithm == Algorithm::AStar ? "A*" : "Dijkstra")
             << ": path length " << path.size() - 1
             << ", expanded cells " << mazeSolver.getExpandedCells() << endl;
        cout << "Output written to " << outputFilePath << endl;
    }
    catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1;
    }
    catch (vector<string> errMessages) {
        for (const string& s : errMessages) {
            cerr << s << endl;
        }
        return 1;
    }

    return 0;
}
