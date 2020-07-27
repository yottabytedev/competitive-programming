#include <thread>             // std::thread, std::this_thread::yield
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable



class Foo {
    bool f,s;
    std::mutex mtx;
    std::condition_variable cv;
public:
    Foo() {
        f = s = false;
        
    }
    
    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        std::lock_guard lck(mtx);
        f = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[this]{return f;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        s = true;
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[this]{return s;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};


//	Runtime: 168 ms, faster than 32.44% of C++ online submissions for Print in Order.
//	Memory Usage: 7.1 MB, less than 84.70% of C++ online submissions for Print in Order.