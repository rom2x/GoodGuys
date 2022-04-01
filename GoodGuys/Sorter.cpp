#include <vector>
#include "Sorter.h"

template<typename T1>
void Sorter<T1>:: Run(vector<T1*>& list)
{
    for (int i = 0; i < list.size(); i++) {
        for (int b = 0; b < list.size() - i - 1; b++) {
            if (*list[b] > *list[b + 1]) {
                T1* temp = list[b];
                list[b] = list[b + 1];
                list[b + 1] = temp;
            }
        }
    }
}

template<typename T1>
void Sorter<T1> :: Run(vector<T1&>& list)
{
    for (int i = 0; i < list.size(); i++) {
        for (int b = 0; b < list.size() - i - 1; b++) {
            if (list[b] > list[b + 1]) {
                T1 temp = list[b];
                list[b] = list[b + 1];
                list[b + 1] = temp;
            }
        }
    }
}
