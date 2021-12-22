#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include <iostream>
# include "iterator_trais.hpp"
# include "../map/RedBlackTree.hpp"
# include "../tools.hpp"

namespace ft
{
    // template<class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
    // class RedBlackTree;
    
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
            bidirectional_iterator() : _ptr(NULL), _endNode(NULL) {}
            bidirectional_iterator(node_pointer ptr, node_pointer endNode) : _ptr(ptr), _endNode(endNode) {}
            bidirectional_iterator(bidirectional_iterator const & it) : _ptr(it._ptr) {}
            virtual ~bidirectional_iterator() {}
            
            operator bidirectional_iterator<const T>()
            {
                return bidirectional_iterator<const T>(this->_ptr, this->_endNode); 
            }
            
            bidirectional_iterator & operator= (bidirectional_iterator const & it) 
            {
                this->_ptr = it._ptr;
                this->_endNode = it._endNode;
                return *this;
            }
            reference operator* () const
            {
                return (this->_ptr->value);
            }
            pointer operator-> ()
            {
                return &(this->operator*());
            }
            bidirectional_iterator operator++()
            {
                if (this->_ptr->parent && this->_ptr->parent == this->_ptr->left)
                    this->_ptr = this->_ptr->right;
                else if (this->_ptr->isleft && (!this->_ptr->left || !this->_ptr->right))
                    this->_ptr = this->_ptr->parent;
                else if (!this->_ptr->isleft && !this->_ptr->right)
                {
                    this->_ptr = tree::getParentPredecessor(this->_ptr);
                    if (!this->_ptr)
                        this->_ptr = this->_endNode;
                }
                else
                    this->_ptr = tree::getSuccessor(this->_ptr);
                return bidirectional_iterator(this->_ptr, this->_endNode);
            }
            bidirectional_iterator operator++(int)
            {
                bidirectional_iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            bidirectional_iterator operator--()
            {
                if (this->_ptr == this->_endNode)
                {
                    this->_ptr = tree::getMaximum(this->_ptr->parent);
                    return bidirectional_iterator(this->_ptr, this->_endNode);
                }
                else if (!this->_ptr->isleft && (!this->_ptr->right || !this->_ptr->left))
                    this->_ptr = this->_ptr->parent;
                else if (this->_ptr->isleft && !this->_ptr->left)
                {
                    this->_ptr = tree::getParentSuccessor(this->_ptr);
                    if (!this->_ptr)
                        this->_ptr = this->_endNode;
                }
                else
                    this->_ptr = tree::getPredecessor(this->_ptr);
                return bidirectional_iterator(this->_ptr, this->_endNode);
            }
            bidirectional_iterator operator--(int)
            {
                bidirectional_iterator tmp = *this;
                --(*this);
                return tmp;
            }
            template <class U>
            friend bool operator== (const bidirectional_iterator<U>& lhs, const bidirectional_iterator<U>& rhs);
            template <class U>
            friend bool operator!= (const bidirectional_iterator<U>& lhs, const bidirectional_iterator<U>& rhs);

        private:
            node_pointer _ptr;
            node_pointer _endNode;
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