#include "hello_header.hpp"

void Sample2_Shared()
{
  // (A) create a new CSample instance with one reference
  boost::shared_ptr<Sample> mySample(new Sample);
  std::cout << "The Sample now has references:" << mySample.use_count() << "\n"; // should be 1

  // (B) assign a second pointer to it:
  boost::shared_ptr<Sample> mySample2 = mySample; // should be 2 refs by now
  std::cout << "The Sample now has references:" << mySample.use_count() << "\n";

  // (C) set the first pointer to NULL
  mySample.reset();
  std::cout << "The Sample now has references: " << mySample2.use_count() << "\n";  // 1

  // the object allocated in (1) is deleted automatically
  // when mySample2 goes out of scope
}
