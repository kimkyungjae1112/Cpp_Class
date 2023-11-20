#include <iostream>
#include <thread>

using namespace std;

namespace Thread
{

    template <typename T>
    class timer_smartptr
    {
    private:

        T* ptr;
        thread t;
    public:



        // thread funtion
        void timer(int time)
        {
            this_thread::sleep_for(chrono::seconds(time));
            if (ptr != nullptr)
            {
                delete ptr;
                ptr = nullptr;
            }
        }



        timer_smartptr(T* p = 0, int time = 10) : ptr(p)
        {
            // set the thread

            t = thread(&timer_smartptr::timer, this, time);

        }

        ~timer_smartptr()
        {
            if (t.joinable())
            {
                t.join();
            }
            if (ptr != nullptr)
            {
                delete ptr;
                ptr = nullptr;
            }
        }

        T& operator*() { return *ptr; }
        T* operator->() { return ptr; }

        void join()
        {
            if (t.joinable())
            {
                t.join();
            }
        }

    };


    int main()
    {

        timer_smartptr<int> p1(new int, 10); // e.g., 10s

        p1.join(); // wait till the time is up! 

        cout << "Wow!" << endl;
        return 0;
    }
}