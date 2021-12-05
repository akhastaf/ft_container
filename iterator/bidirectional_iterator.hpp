#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include <iostream>
# include "iterator_trais.hpp"
# include "../map/RedBlackTree.hpp"
# include "../tools.hpp"

namespace ft
{
    template <class T>
    class bidirectional_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
    {
        public:
            typedef typename    ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
            typedef typename    ft::iterator<std::bidirectional_iterator_tag, T>::value_type        value_type;
            typedef typename    ft::iterator<std::bidirectional_iterator_tag, T>::difference_type	difference_type;
            typedef             T*                                                                  pointer;
            typedef             T&			                                                        reference;
            typedef             ft::RedBlackTree<T>			                                        tree;
            typedef typename    tree::node_pointer			                                        node_pointer;
            bidirectional_iterator() : _ptr(nullptr) {}
            bidirectional_iterator(pointer ptr) : _ptr(ptr) {}
            bidirectional_iterator(bidirectional_iterator const & it) : _ptr(it._ptr) {}
            virtual ~bidirectional_iterator() {}
            bidirectional_iterator & operator= (bidirectional_iterator const & it) 
            {
                this->_ptr = it._ptr;
                return *this;
            }
            reference operator* ()
            {
                return *(this->_ptr->value);
            }
            pointer operator-> ()
            {
                return &(this->operator*());
            }
            // bidirectional_iterator operator++()
            // {
            //     node_pointer node_ptr = tree::getSuccessor(this->_ptr);
            //     if (node_ptr)
            //     {
            //         while (this->_ptr->parent != NULL)
            //             this->_ptr = this->_ptr->parent;
            //     }        
            // }
            bidirectional_iterator operator++(int)
            {
                bidirectional_iterator tmp = *this;
                ++tmp;
                return tmp;
            }
            // bidirectional_iterator operator--()
            // {
                
            // }
            bidirectional_iterator operator--(int)
            {
                bidirectional_iterator tmp = *this;
                --tmp;
                return tmp;
            }
            template <class U>
            friend bool operator== (const bidirectional_iterator<U>& lhs, const bidirectional_iterator<U>& rhs);
            template <class U>
            friend bool operator!= (const bidirectional_iterator<U>& lhs, const bidirectional_iterator<U>& rhs);

        private:
            //pointer _ptr;
            node_pointer _ptr;
    };
    template <class U>
    bool operator== (const bidirectional_iterator<U>& lhs, const bidirectional_iterator<U>& rhs)
    {
        return (lhs._ptr == rhs._ptr);
    }
    template <class U>
    bool operator!= (const bidirectional_iterator<U>& lhs, const bidirectional_iterator<U>& rhs)
    {
        return (lhs._ptr != rhs._ptr);
    }
}

#endif