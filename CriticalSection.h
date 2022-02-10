#ifndef OS_CRITICALSECTION_H
#define OS_CRITICALSECTION_H
#include <iostream>
#include <fstream>
#include <mutex>


using namespace std;


class CriticalSection {
public:

    fstream f;
    CriticalSection();
    static void reader(string id, int val);
    static void writer(string id, int val);
};


#endif //OS_CRITICALSECTION_H
