#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int turn = 1;

void printThread(int id) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [id] { return id == turn; });
    cout << "thread " << id << endl;
    turn++;
    cv.notify_all();
}

int main() {
    thread t1(printThread, 1);
    thread t2(printThread, 2);
    thread t3(printThread, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
