class Semaphore {
public:
    Semaphore (int count_ = 0)
        : count(count_) {}

    inline void notify()
    {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        cv.notify_one();
    }

    inline void wait()
    {
        std::unique_lock<std::mutex> lock(mtx);

        while(count == 0){
            cv.wait(lock);
        }
        count--;
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        s1 = new Semaphore(0);
        s2 = new Semaphore(1);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            s2->wait();
        	printFoo();
            s1->notify();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            s1->wait();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            s2->notify();
        }
    }
private:
    Semaphore *s1,*s2;
};
