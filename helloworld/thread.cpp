#include "hello_header.hpp"

void hello()
{
  std::cout <<
    "Hello world, I'm a thread!"
    << std::endl;
}

int sample_thread()
{
    boost::thread thrd(&hello);
    thrd.join();
    return 0;
}
