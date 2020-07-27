class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool f = false, b = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck,[this]{return b;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            f = true;
            b = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck,[this]{return f;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            b = true;
            f = false;
            cv.notify_one();
        }
    }
};

//	Runtime: 344 ms, faster than 40.96% of C++ online submissions for Print FooBar Alternately.
//	Memory Usage: 8.3 MB, less than 40.00% of C++ online submissions for Print FooBar Alternately.