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

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 20 // the ft::map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

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
        if (*first1 != *first2)
            return false;
    return true;
}

int main (void) {
    
   {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::sets ---------------------*/
            std::set<int> m1;
            ft::set<int> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(i);
                ft_m1.insert(i);
            }

            start = get_time();
            m1.size();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::sets ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.size();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::sets ---------------------*/
        std::set<std::string> m1; // fill constructor
        ft::set<std::string> ft_m1;
        std::string s[5] = {"hello", "string", "value", "size", "test"};
        for (size_t i = 0; i < 5; i++)
        {
            m1.insert(s[i]);
            ft_m1.insert(s[i]);
        }

        std::set<std::string> m2;                         // empty constructor
        std::set<std::string> m3(m1.begin(), m1.end());   // range constructor with normal iterators
        std::set<std::string> m4(m3);                     // copy constructor
        std::set<std::string> m5(m1.rbegin(), m1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::sets ---------------------*/
        ft::set<std::string> ft_m2;
        ft::set<std::string> ft_m3(ft_m1.begin(), ft_m1.end());
        ft::set<std::string> ft_m4(ft_m3);
        ft::set<std::string> ft_m5(ft_m1.rbegin(), ft_m1.rend());
        /*----------------------------------------------------*/

        // ft_m1.print2D();
        // ft::set<std::string>::iterator itend = ft_m1.end();
        // std::cout << *itend << std::endl; 
        // --itend;
        // std::cout << *itend << std::endl; 
        // --itend;
        // std::cout << *itend << std::endl; 
        // --itend;
        // std::cout << *itend << std::endl; 
        //ft_m5.print2D();
        bool cond = (m1.begin()->size() == ft_m1.begin()->size()) && (m3.begin()->size() == ft_m3.begin()->size())
        && (m4.begin()->size() == ft_m4.begin()->size()) && (m5.begin()->size() == ft_m5.begin()->size());
        // EQUAL(cond);
        std::cout << "ft_m1 : " << ft_m1.size() << " m1 : " << m1.size() << std::endl;
        std::cout << "ft_m2 : " << ft_m2.size() << " m2 : " << m2.size() << std::endl;
        std::cout << "ft_m3 : " << ft_m3.size() << " m3 : " << m3.size() << std::endl;
        std::cout << "ft_m5 : " << ft_m5.size() << " m5 : " << m5.size() << std::endl;
        std::cout << "ft_m4 : " << ft_m4.size() << " m4 : " << m4.size() << std::endl;
        EQUAL(cond && (m1.size() == ft_m1.size() && m2.size() == ft_m2.size() && m3.size() == ft_m3.size() && m5.size() == ft_m5.size() && m4.size() == ft_m4.size()));
    }
  return 0;
}
