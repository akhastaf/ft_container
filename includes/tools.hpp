#ifndef TOOLS_HPP
# define TOOLS_HPP

namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (fisrt2 == last2 || *fisrt1 > *fisrt2)
                return false;
            else if (*first1 < *fisrt2)
                return true;
            first1++;
            first2++;
        }
        return (first2 != last2);
    }
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2,
                                    Compare comp)
    {
        while (first1 != last1)
        {
            if (fisrt2 == last2 || comp(*fisrt2, *fisrt1))
                return false;
            else if (comp(*first1, *fisrt2))
                return true;
            first1++;
            first2++;
        }
        return (first2 != last2);
    }
}

#endif