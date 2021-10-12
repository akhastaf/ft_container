// out_of_range example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector

int main (void) {
  std::vector<int> myvector;

  for(int i = 0; i < 10; i++)
    myvector.push_back(i);
  myvector.pop_back();

  std::cout << myvector[9] << std::endl;
  for(int i = 0; i < myvector.size(); i++)
    std::cout << myvector[i] << std::endl;
  
  std::cout << "myvetor : " << std::endl;
  std::cout << myvector.size() << std::endl;
  std::cout << myvector.capacity() << std::endl;
  
  // for(int i = 0; i < 8; i++)
  //   myvector.push_back(i);
  
  // std::cout << myvector.size() << std::endl;
  // std::cout << myvector.capacity() << std::endl;
  // // std::cout << "myvetor1 : " << std::endl;
  // // std::cout << myvector1.size() << std::endl;
  // // std::cout << myvector1.capacity() << std::endl;
  
  // std::vector<int> myvector1(myvector);

  // std::cout << "myvetor : " << std::endl;
  // std::cout << myvector.size() << std::endl;
  // std::cout << myvector.capacity() << std::endl;
  // std::cout << "myvetor1 : " << std::endl;
  // std::cout << myvector1.size() << std::endl;
  // std::cout << myvector1.capacity() << std::endl;

  // for (int i = 0; i < myvector1.capacity(); i++)
  //   std::cout << myvector1[i] << std::endl;

  // std::cout << "myvetor : " << std::endl;
  // std::cout << myvector.size() << std::endl;
  // std::cout << myvector.capacity() << std::endl;

  // myvector.assign(4, 5);

  // std::cout << "myvetor : " << std::endl;
  // std::cout << myvector.size() << std::endl;
  // std::cout << myvector.capacity() << std::endl;
  
  // for (int i = 0; i < myvector.size(); i++)
  //   std::cout << myvector[i] << std::endl;
  
  return 0;
}