class Foo {
public:

    mutex m;
    condition_variable cv;
    int turn;

    Foo() {
        turn = 0;
    }

    void first(function<void()> printFirst) {
        
        printFirst();

        {
            lock_guard<mutex> lock(m);
            turn = 1;
        }

        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        unique_lock<mutex> lock(m);

        while(turn != 1) {
            cv.wait(lock);
        }

        printSecond();

        turn = 2;

        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {

        unique_lock<mutex> lock(m);

        while(turn != 2) {
            cv.wait(lock);
        }

        printThird();
    }
};