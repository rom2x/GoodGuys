#pragma once
#include <vector>
using namespace std;

template<typename T1>
class Sorter {
public:
    void run(vector<T1*>& list);
    void run(vector<T1&>& list);
};
