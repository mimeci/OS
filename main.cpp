#include <thread>
#include "CriticalSection.h"
#include "semaphore.h"

using namespace std;
sem_t *full, *bos;

void function1(CriticalSection &crt){
    for (int i = 0; i < 100; ++i) {
        crt.reader(string("From t1: "), i);
    }
}

void function2(CriticalSection &crt){
    for (int i = 0; i < 100; ++i) {
        crt.writer(string("From t2: "), i);
    }
}

int main() {
    CriticalSection crt;

    bos = sem_open("/bos_sem", O_CREAT, 0644, 10);
    full = sem_open("/full_sem", O_CREAT, 0644, 0);
  // for (int i = 0; i < 100; ++i) {
  //     crt.shared_func(string("From main: "), i);
  //  }

    thread myThread2(function2, ref(crt));
    thread myThread(function1, ref(crt));
    myThread2.join();
    myThread.join();

    sem_unlink("/bos_sem");
    sem_unlink("/full_sem");

    return 0;
}



