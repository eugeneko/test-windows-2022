#include <iostream>
#include <mutex>

#define TRACE_HERE (std::cerr << "Trace: " << __FILE__ << "(" << __LINE__ << ")" << std::endl)

int main()
{
    TRACE_HERE; std::mutex m;
    TRACE_HERE; std::lock_guard<std::mutex> l(m);
    TRACE_HERE; return 0;
}