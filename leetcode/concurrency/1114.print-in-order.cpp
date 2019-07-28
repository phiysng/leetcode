class Semaphore {
public:
	Semaphore(int count_ = 0)
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

		while (count == 0) {
			cv.wait(lock);
		}
		count--;
	}

private:
	std::mutex mtx;
	std::condition_variable cv;
	int count;
};


class H2O {
public:
    H2O() {
       // h = new Semaphore(0);
       // o = new Semaphore(0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        h.notify();
        o.wait();
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        
    x.lock();
                o.notify();
    
        h.wait(); 
        
        o.notify();
        h.wait();   
        releaseOxygen();
        x.unlock();
    }
    
private:
    Semaphore h , o;
    mutex x;
};
