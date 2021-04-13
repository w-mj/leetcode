#include "defines.h"

class DiningPhilosophers {
public:
    mutex mtx[5];
    condition_variable cv;
    int index;
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        unique_lock lock(mtx[philosopher]);
        cv.wait(lock, [&](){return index % 5 == philosopher;});
        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();
        index++;
        cv.notify_all();
    }
};