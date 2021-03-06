#ifndef TOOLS_HPP
# define TOOLS_HPP
# include <type_traits>

namespace ft
{

    template<bool B, class T = void>
    struct enable_if {};
    template<class T>
    struct enable_if<true, T> { typedef T type; };

    template<class T, class U=void()>
    struct is_integral { static const bool value = false; };

    template<class T>
    struct is_integral<bool, T> { static const bool value = true; };
    template<class T>
    struct is_integral<char, T> { static const bool value = true; };
    template<class T>
    struct is_integral<char16_t, T> { static const bool value = true; };
    template<class T>
    struct is_integral<char32_t, T> { static const bool value = true; };
    template<class T>
    struct is_integral<wchar_t, T> { static const bool value = true; };
    template<class T>
    struct is_integral<signed char, T> { static const bool value = true; };
    template<class T>
    struct is_integral<short int, T> { static const bool value = true; };
    template<class T>
    struct is_integral<int, T> { static const bool value = true; };
    template<class T>
    struct is_integral<long int, T> { static const bool value = true; };
    template<class T>
    struct is_integral<long long int, T> { static const bool value = true; };
    template<class T>
    struct is_integral<unsigned char, T> { static const bool value = true; };
    template<class T>
    struct is_integral<unsigned short int, T> { static const bool value = true; };
    template<class T>
    struct is_integral<unsigned int, T> { static const bool value = true; };
    template<class T>
    struct is_integral<unsigned long int, T> { static const bool value = true; };
    template<class T>
    struct is_integral<unsigned long long int, T> { static const bool value = true; };
    
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first1 > *first2)
                return false;
            else if (*first1 < *first2)
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
            if (first2 == last2 || comp(*first2, *first1))
                return false;
            else if (comp(*first1, *first2))
                return true;
            first1++;
            first2++;
        }
        return (first2 != last2);
    }
    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2)
    {
        while (first1!=last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1; ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1!=last1)
        {
            if (!pred(*first1,*first2))
                return false;
            ++first1; ++first2;
        }
        return true;
    }
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        first_type first;
        second_type second;
        pair() : first(first_type()), second(second_type()) {}
        template<class U, class V>
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}
        pair& operator= (const pair& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return *this;
        }
    };
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first==rhs.first && lhs.second==rhs.second; }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs==rhs); }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); }
    
    template <class T1, class T2>
    std::ostream & operator<< (std::ostream & o, pair<T1,T2> const & p)
    {
        o << p.first << " " << p.second;
        return o; 
    }

    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y) );
    }
    template<class T>
    struct   Node
    {
        T   value;
        Node<T> *left;
        Node<T> *right;
        Node<T> *parent;
        bool black;
        bool isleft;
        Node() : value(T()), left(NULL), right(NULL), parent(NULL), black(false), isleft(true) {}
        Node(T cvalue) : value(cvalue), left(NULL), right(NULL), parent(NULL), black(false), isleft(true) {}
        ~Node() {}
    };
}

#endif