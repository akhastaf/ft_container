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
            typedef iterator_category 	iterator_traits<Iterator>::iterator_category;
            typedef value_type iterator_traits<Iterator>::value_type;
            typedef difference_type iterator_traits<Iterator>::difference_type;
            typedef pointer iterator_traits<Iterator>::pointer;
            typedef reference iterator_traits<Iterator>::reference;

            reverse_iterator() : _iter(iterator_type()) { }
            explicit reverse_iterator (iterator_type it) : _iter(it) { }
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iter(rev_it) { }
            iterator_type base() const { return iterator_type(this->_iter + 1); }
            reference operator*() const { return *(this->_iter); }
            reverse_iterator operator+ (difference_type n) const { return reverse_iterator(this->_iter - n); }
            reverse_iterator& operator++() { return reverse_iterator(this->_iter--); }
            reverse_iterator  operator++(int)
            {
                reverse_iterator tmp = *this;
                (*this)++;
                return tmp;
            }
            //reverse_iterator& operator+= (difference_type n) { return reverse_iterator(this->_iter  this->_iter + n); }
            reverse_iterator operator- (difference_type n) const { return reverse_iterator(this->_iter + n); }
            reverse_iterator& operator--() { return reverse_iterator(this->_iter++); }
            reverse_iterator  operator--(int)
            {
                reverse_iterator tmp = *this;
                (*this)--;
                return tmp;
            }
            //reverse_iterator& operator-= (difference_type n) { return reverse_iterator(this->_iter + this->_iter + n); }
            pointer operator->() const { return &(operator*()); }

        private:
            iterator_type _iter;
    };
}

#endif