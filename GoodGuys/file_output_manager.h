#pragma once
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

class FileOutputManager {
public:
    FileOutputManager(const string& output_file_name)
        : output_file_name_(output_file_name), output_file_stream_(output_file_name) {
    }

    void WriteResultToFile(const string& result) {
        if (result != "") {
            output_file_stream_ << result;
        }
    }

private:
    ofstream output_file_stream_;
    string output_file_name_;
};


