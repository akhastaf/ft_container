// out_of_range example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector
#include <utility>         // std::vector
#include "tools.hpp"
#include "./map/map.hpp"
#include "./map/RedBlackTree.hpp"
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

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 20 // the ft::map methods can be slower up to std::map methods * TIME_FAC (MAX 20)
typedef std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> iter_def;
typedef ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_iter_def;
typedef std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator> const_iter_def;
typedef ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator> ft_const_iter_def;

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}
struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

int main (void)
{
    ft::map<int, std::string> ft_m;
    for (size_t i = 0; i < 15; i++)
        ft_m.insert(ft::make_pair(i, "string2"));

    ft::map<int, std::string>::iterator tmp;
    ft::map<int, std::string>::iterator first = ft_m.begin();

    while (first != ft_m.end())
    {
        tmp = first++;
        ft_m.erase(tmp);
    }
  
    // ft_m.erase(ft_m.begin(), ft_m.end());
    // {
    //     bool cond(false);
    //     // erasing all the elements in the map;
    //     {
    //         time_t start, end, diff;
    //         /*------------------ std::maps ---------------------*/
    //         std::map<int, std::string> m1;
    //         ft::map<int, std::string> ft_m1;
    //         for (size_t i = 0; i < 1e5; i++)
    //         {
    //             m1.insert(std::make_pair(i, "string2"));
    //             ft_m1.insert(ft::make_pair(i, "string2"));
    //         }

    //         start = get_time();
    //         m1.erase(m1.begin(), m1.end());
    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
    //         /*-----------------------------------------------------*/
    //         /*------------------ ft::maps ---------------------*/
    //         // ualarm(diff * 1e3, 0);
    //         ft_m1.erase(ft_m1.begin(), ft_m1.end());
    //         // ualarm(0, 0);
    //         /*----------------------------------------------------*/
    //     }
    //     std::map<char, int> m;
    //     ft::map<char, int> ft_m;
    //     std::map<char, int>::iterator it;
    //     ft::map<char, int>::iterator ft_it;

    //     // insert some values:
    //     ft_m['a'] = 10;
    //     ft_m['b'] = 20;
    //     ft_m['c'] = 30;
    //     ft_m['d'] = 40;
    //     ft_m['e'] = 50;
    //     ft_m['f'] = 60;

    //     m['a'] = 10;
    //     m['b'] = 20;
    //     m['c'] = 30;
    //     m['d'] = 40;
    //     m['e'] = 50;
    //     m['f'] = 60;

    //     cond = m.size() == ft_m.size() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

    //     it = m.find('a');
    //     ft_it = ft_m.find('a');
    //     cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second);
    //     m.erase(it);       // erasing by iterator
    //     ft_m.erase(ft_it); // erasing by iterator

    //     cond = cond && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

    //     int ret = m.erase('b');       // erasing by key
    //     int ft_ret = ft_m.erase('b'); // erasing by key

    //     cond = cond && ret == ft_ret && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

    //     it = m.find('e');
    //     ft_it = ft_m.find('e');
    //     ft::map<char, int>::iterator ft_end = ft_m.end();
    //     cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second) && m.size() == ft_m.size();

    //     m.erase(it, m.end());          // erasing by range
    //     ft_m.erase(ft_it, ft_m.end()); // erasing by range

    //     cond = cond && m.empty() == ft_m.empty() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

    //     // /* ---------- Testing some edge cases ---------- */

    //     std::map<int, std::string> m2;
    //     ft::map<int, std::string> ft_m2;

    //     for (size_t i = 0; i < 1e5; i++)
    //     {
    //         m2.insert(std::make_pair(i, "string1"));
    //         ft_m2.insert(ft::make_pair(i, "string1"));
    //     }

    //     std::map<int, std::string>::reverse_iterator it2 = m2.rbegin();
    //     ft::map<int, std::string>::reverse_iterator ft_it2 = ft_m2.rbegin();

    //     m2.erase(m2.begin());
    //     ft_m2.erase(ft_m2.begin());

    //     cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

    //     m2.erase(it2->first);
    //     ft_m2.erase(ft_it2->first);

    //     cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

    //     std::map<int, std::string> m3;
    //     ft::map<int, std::string> ft_m3;
    //     std::vector<int> vec;
    //     std::vector<int> ft_vec;
    //     std::random_device randDev;
    //     std::mt19937 generator(randDev());
    //     std::uniform_int_distribution<int> distr(0, 1e8);

    //     for (size_t i = 0; i < 1e6; i++)
    //     {
    //         m3.insert(std::make_pair(i, "string1"));
    //         ft_m3.insert(ft::make_pair(i, "string1"));
    //     }
    //     EQUAL(cond);
    // }

  return 0;
}
