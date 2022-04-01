#pragma once
#include <vector>
using namespace std;

template<typename T1>
class Sorter {
public:
    void Run(vector<T1*>& list);
    void Run(vector<T1&>& list);
};
