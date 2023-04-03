#include "FileReader.h"

vector<string> FileReader::read(string filePath){ 
    ifstream inFile(filePath);
    if (!inFile) {
        throw ifstream::failure("Impossible to open the file "+filePath);
    }
    vector<string> rows;
    string line;
    while (getline(inFile,line)){
        rows.push_back(line);
    }
    inFile.close();
    return rows;
}

void FileReader::write(string filePath, vector<string> rows){
    ofstream outFile(filePath);
    if (!outFile) {
        throw ofstream::failure("Impossible to write to the file "+filePath);
    }
    for (int i=0;i<rows.size();i++){
        outFile<<rows[i]<<endl;
    }
    outFile.close();
}
