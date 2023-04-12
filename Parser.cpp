#include "Parser.h"

vector<vector<char>> Parser::parse(vector<string> rows){
    vector<vector<char>> matrix;
    for (int i=0;i<rows.size();i++){
        string line = rows[i];
        vector<char> lineVec;
        for (int j=0;j<line.length();j++){
            if (j % 2 == 0){ //symbol is not separating space 
                lineVec.push_back(line[j]);
            }
        }
        matrix.push_back(lineVec);
    }
    return matrix;
}

vector<string> Parser::serialize(vector<vector<char>> matrix){
    vector<string> rows;
    for (int i=0;i<matrix.size();i++){
        vector<char> lineVec = matrix[i];
        string row;
        for (int j=0;j<lineVec.size();j++){
            if (j == lineVec.size()-1) {
                row = row + lineVec[j];
            }
            else {
                row = row + lineVec[j] + ' ';
            }  
        }
        rows.push_back(row);
    }
    return rows;
}