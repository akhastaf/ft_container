#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
#include "../iterator/iterator_trais.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename  iterator_traits<Iterator>::value_type value_type;
            typedef typename  iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer ;
            typedef typename  iterator_traits<Iterator>::reference reference;
            reverse_iterator() : _iter(iterator_type()) { }
            explicit reverse_iterator (iterator_type it) : _iter(--it) { }
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iter(rev_it.base()) { }
            operator reverse_iterator<const Iterator> ()
            {
                return reverse_iterator<const Iterator>(this->_iter);
            }
            reverse_iterator operator= (reverse_iterator const & it)
            {
                this->_iter = it._iter - 1;
                return *this;
            }
            iterator_type base() const 
            {
                iterator_type tmp = this->_iter;
                return (++tmp); 
            }
            reference operator*() const { return *(this->_iter); }
            reverse_iterator operator+ (difference_type n) const 
            {
                reverse_iterator tmp(this->_iter - (n - 1));
                return tmp;
            }
            reverse_iterator& operator++()
            {
                --this->_iter;
                return *this;
            }
            reverse_iterator  operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            reverse_iterator operator+= (difference_type n)
            {
                this->_iter -= n;
                return reverse_iterator(*this);
            }
            reverse_iterator operator- (difference_type n) const 
            {
                return reverse_iterator(this->_iter + (n + 1)); 
            }
            reverse_iterator operator--() 
            {
                ++this->_iter;
                return *this;
            }
            reverse_iterator  operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return tmp;
            }
            reverse_iterator operator-= (difference_type n) 
            {
                this->_iter += n;
                return reverse_iterator(*this);
            }
            pointer operator->() const { return &(operator*()); }
            reference operator[] (difference_type n) const { return this->_iter.base()[-n]; }
            template <class Iterator1>
            friend typename reverse_iterator<Iterator1>::difference_type operator- (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator1>& rhs);
        public:
            iterator_type _iter;
    };


    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator>
    reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
    {
        return reverse_iterator<Iterator>(rev_it + n);
    }
    template <class Iterator1>
    typename reverse_iterator<Iterator1>::difference_type operator- (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator1>& rhs)
    {
        return rhs.base() - lhs.base();
    }
}

#endif