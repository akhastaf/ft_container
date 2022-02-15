// out_of_range example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector
#include <utility>         // std::vector
#include "tools.hpp"
#include "./map/map.hpp"

int main (void) {
  ft::map<int, int> ft_m;
  int myints[] = {12, 82, 37, 64, 15};
  for (size_t i = 0; i < 5; i++)
  {
      ft_m.insert(ft::make_pair(myints[i], i));
      ft_m.print2D();
  }
  // bool cond(false);
  // // for (size_t i = 0; i < 10; ++i)
  // //     ft_m.insert(ft::make_pair(i, "value"));
  // int res(0);
  // ft::map<int, int> m;
  // for (size_t i = 0; i < 5; ++i)
  // {
  //     m.insert(ft::make_pair(myints[i], i));
  //     m.print2D();
  // }
  // std::cout << "here" << std::endl;
  // for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
  //   std::cout << it->first << std::endl;
  //     // res += it->first;
  // cond = res == 210;
  return 0;
}
