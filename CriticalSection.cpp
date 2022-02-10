#include <unistd.h>
#include "CriticalSection.h"
#include "semaphore.h"
#include "sstream"

static mutex m1, m2;
extern sem_t *full, *bos;

CriticalSection::CriticalSection()
{

}

void CriticalSection::reader(const string id, int val)
{
    sem_wait(full);
    //m1.lock();
    //lock_guard<mutex> locker(m1);

    stringstream stream;
    stream << "Reader" << id << ": " << val << endl;
    cout << stream.str();

    //m1.unlock();
    sem_post(bos);


}

void CriticalSection::writer(const string id, int val)
{
    sem_wait(bos);
    //m1.lock();
    //lock_guard<mutex> locker(m1);

    stringstream stream;
    stream << "Writer "<< id << ": " << val << endl;
    cout << stream.str();

    //m1.unlock();
    sem_post(full);

}
