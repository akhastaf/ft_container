// out_of_range example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector

int main (void) {
  // std::vector<int> a(20, 100);
  // std::vector<int> b(a.begin(), a.end());
  // std::cout << b.size() << std::endl;
  // std::cout << b.capacity() << std::endl;

  // std::vector<int>::iterator it = a.end();
  // it--;
  // a.erase(a.begin(), a.end());
  // std::cout << a.size() << std::endl;
  // std::cout << a.capacity() << std::endl;

  // std::vector<int> a(6, 10);
  // std::vector<int> b(4, 100);

  // if (a < b)
  //   std::cout << "a is less than b" << std::endl;
  // if (a > b)
  //   std::cout << "b is less than a" << std::endl;
  // for(int i = 0; i < 10; i++)
  //   myvector.push_back(i);
  // myvector.pop_back();

  // std::cout << myvector[9] << std::endl;
  // for(int i = 0; i < myvector.size(); i++)
  //   std::cout << myvector[i] << std::endl;
  
  // std::cout << "myvetor : " << std::endl;
  // std::cout << myvector.size() << std::endl;
  // std::cout << myvector.capacity() << std::endl;
  

  // try
  // {
  //   myvector.reserve(myvector.max_size() + 1e3);
  // }
  // catch (std::exception &e)
  // {
  //   std::cout << e.what() << std::endl;
  // }
  // try
  // {
  //   myvector.resize(myvector.max_size() + 1e3, 10);
  // }
  // catch (std::exception &e)
  // {
  //   std::cout << e.what() << std::endl;
  // }



  // std::vector<int>::iterator it = myvector.begin();

  // it.

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


  // std::vector<int> a(10, 33);
  // std::vector<int> b;
  

  // b.insert(b.end(), a.begin(), a.end());
  // std::cout << b.size() << std::endl;
  // std::cout << b.capacity() << std::endl;
  // for (int i = 0; i < b.size(); i++)
  //   std::cout << b[i] << std::endl;
  // std::cout << std::distance(a.begin(), a.end()) << std::endl;

  // std::vector<int> c;
  // std::cout << c.begin().base() << std::endl;
  // std::cout
  std::vector<int> a;
  std::vector<int> b(10, 55);
  a.push_back(6);
  std::vector<int>::iterator ir = a.begin();
  ir++;
  a.insert(a.begin(), b.begin(), b.end());
  std::cout << "size: " << a.size() << std::endl;
  std::cout << "capcity: " << a.capacity() << std::endl;
  for (int i = 0; i < a.size(); i++)
      std::cout << a[i] << std::endl;
  
  return 0;
}
