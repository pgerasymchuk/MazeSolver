#ifndef LAB3_FILE_READER_H
#define LAB3_FILE_READER_H

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

class FileReader {
  public:
    vector<string> read(string);
    void write(string, vector<string>);
};


#endif