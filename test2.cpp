// out_of_range example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector
#include <utility>         // std::vector
#include "tools.hpp"
// #include "./map/map.hpp"
#include <map>
#include <ctime>
#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>
# include <set>
# include "set/set.hpp"

// #define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
// #define TIME_FAC 20 // the ft::map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

// time_t get_time(void)
// {
//     struct timeval time_now;

//     gettimeofday(&time_now, NULL);
//     time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
//     return (msecs_time);
// }
// struct classcomp
// {
//     bool operator()(const char &lhs, const char &rhs) const
//     {
//         return lhs < rhs;
//     }
// };

// bool fncomp(char lhs, char rhs) { return lhs < rhs; }

// template <typename Iter1, typename Iter2>
// bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
// {
//     for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
//         if (first1->first != first2->first || first1->second != first2->second)
//             return false;
//     return true;
// }

int main (void) {
    
    std::set<int> s;
    ft::set<int> ft_s;

    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(10);
    for (std::set<int>::iterator it = s.begin(); it != s.end(); it++)
        std::cout << *it << std::endl;
    ft_s.insert(6);
    ft_s.insert(7);
    ft_s.insert(8);
    ft_s.insert(9);
    ft_s.insert(10);
    for (ft::set<int>::iterator it = ft_s.begin(); it != ft_s.end(); it++)
        std::cout << *it << std::endl;
  return 0;
}
