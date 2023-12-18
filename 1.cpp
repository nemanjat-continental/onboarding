#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void foo1(int& x) {
    std::lock_guard<std::mutex> guard(mtx);
    for (int i = 0; i < 100000; i++) {
        x++;
    }
}

void foo2(int& x) {
    std::lock_guard<std::mutex> guard(mtx);
    for (int i = 0; i < 100000; i++) {
        x++;
    }
}

int main() {
    int x = 0;

    std::thread t1(foo1, std::ref(x));
    std::thread t2(foo2, std::ref(x));

    t1.join();
    t2.join();

    std::cout << x << std::endl;

    return 0;
}