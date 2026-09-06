class DiningPhilosophers {
public:

    mutex m;
    condition_variable cv;

    bool fork[5] ={ false , false , false , false , false};

    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

		int left = philosopher;
        int right = (philosopher + 1) %5;

        unique_lock<mutex> lock(m);

        while(fork[left] || fork[right]){
            cv.wait(lock);
        }

        fork[left] = true;
        fork[right] = true;

        lock.unlock();

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        lock.lock();

        fork[left] = false;
        fork[right] = false;

        cv.notify_all();

    }
};