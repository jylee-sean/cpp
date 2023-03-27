#include <chrono>
#include <string>
#include <iostream>
#include <thread>

typedef std::chrono::steady_clock sclock;

//@brief Timer measure time diff between start() and stop()
class Timer 
{
  public:
    virtual ~Timer() { }
    inline void start() { start_time = sclock::now(); }
    inline void stop()  { end_time = sclock::now(); }

    inline double elapsed_milli() const
    { return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count(); }

    inline double elapsed_sec() const
    { return elapsed_milli() / 1000.0; }

   private:
     sclock::time_point start_time;
     sclock::time_point end_time;
};

int main() 
{

    Timer timer;
    timer.start();
    for(int i = 0 ; i < 2; i++)
         std::this_thread::sleep_for(std::chrono::seconds(1));
    timer.stop();
    std::cout << timer.elapsed_milli() << " (ms)" << std::endl;
    std::cout << timer.elapsed_sec() << " (s)" << std::endl;

    return 0;

}