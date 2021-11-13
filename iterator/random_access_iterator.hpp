#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
# include <iostream>
# include "iterator_trais.hpp"

namespace ft
{
    template <class T>
    class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef typename    ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename    ft::iterator<std::random_access_iterator_tag, T>::value_type        value_type;
    		typedef typename    ft::iterator<std::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef             T*                                                                  pointer;
    		typedef             T&			                                                               reference;
            random_access_iterator() : _ptr(nullptr) {};
            random_access_iterator(pointer ptr) : _ptr(ptr) {};
            random_access_iterator(random_access_iterator const & src) { *this = src; };
            virtual ~random_access_iterator() {};

            random_access_iterator & operator= (random_access_iterator const & src)
            {
                this->_ptr = src.base();
                return *this;
            }
            random_access_iterator & operator+= (difference_type n)
            {
                this->_ptr += n;
                return *this;
            }
            random_access_iterator & operator-= (difference_type n)
            {
                this->_ptr -= n;
                return *this;
            }

            bool operator== (random_access_iterator const & rhs) { return this->_ptr == rhs.base(); };
            bool operator!= (random_access_iterator const & rhs) { return this->_ptr != rhs.base(); };
            reference operator* () const { return *(this->_ptr); };
            pointer operator-> () { return &operator*(); };
            reference operator[] (difference_type n) { return this->_ptr[-n]; };
            random_access_iterator operator++ () 
            {
                return random_access_iterator(this->_ptr++);
            };
            random_access_iterator operator++ (int)
            {
                random_access_iterator tmp = *this;
                this->_ptr++;
                return tmp; 
            };
            random_access_iterator  operator-- () { return random_access_iterator(--(this->_ptr)); };
            random_access_iterator operator-- (int)
            {
                random_access_iterator tmp = *this;
                this->_ptr--;
                return tmp; 
            };
            random_access_iterator operator+ (difference_type n) const
            {
                random_access_iterator tmp = *this;
                tmp += n;
                return tmp;
            };
            random_access_iterator operator- (difference_type n) const
            {
                random_access_iterator tmp = *this;
                tmp -= n;
                return tmp;
            };
            difference_type operator- (random_access_iterator<T> const rhs)
            {
                return this->_ptr - rhs._ptr;
            }
            pointer base() const { return _ptr; };


        private:
            pointer _ptr;
    };
    template <class T>
    bool operator== (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class T>
    bool operator!= (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class T>
    bool operator<  (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class T>
    bool operator<= (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class T>
    bool operator>  (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class T>
    bool operator>= (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template<class T>
    random_access_iterator<T> operator+ (int n, random_access_iterator<T> const & rhs)
    {
        return random_access_iterator<T>(rhs + n);
    }
}

#endif