#include <iostream>
#include <thread>

using namespace std;
void Thread(int id) {
    cout << "thread " << id << endl;
}

int main() {
    thread t1(Thread, 1);
    t1.join();
    thread t2(Thread, 2);
    t2.join();
    thread t3(Thread, 3);

    t3.join();

    return 0;
}
