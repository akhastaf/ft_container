#ifndef bidirectional_iterator_SET_HPP
# define bidirectional_iterator_SET_HPP
# include <iostream>
# include "../iterator/iterator_trais.hpp"
# include "RedBlackTree.hpp"
# include "../tools.hpp"

namespace ft
{
    
    template <class T>
    class bidirectional_iterator_set : public ft::iterator<std::bidirectional_iterator_tag, T>
    {
        public:
            typedef typename    ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
            typedef typename    ft::iterator<std::bidirectional_iterator_tag, T>::value_type        value_type;
            typedef typename    ft::iterator<std::bidirectional_iterator_tag, T>::difference_type	difference_type;
            typedef             T*                                                                  pointer;
            typedef             T&			                                                        reference;
            typedef             ft::RedBlackTree<T>			                                        tree;
            typedef Node<value_type>                                         node_element;
            typedef node_element*                                            node_pointer;
            // typedef typename    tree::node_pointer			                                        node_pointer;
            bidirectional_iterator_set() : _ptr(NULL), _endNode(NULL) {}
            bidirectional_iterator_set(node_pointer ptr, node_pointer endNode) : _ptr(ptr), _endNode(endNode) {}
            bidirectional_iterator_set(bidirectional_iterator_set const & it) : _ptr(it._ptr), _endNode(it._endNode) {}
            virtual ~bidirectional_iterator_set() {}
            
            
            bidirectional_iterator_set & operator= (bidirectional_iterator_set const & it) 
            {
                this->_ptr = it._ptr;
                this->_endNode = it._endNode;
                return *this;
            }
            operator bidirectional_iterator_set<const T>()
            {
                return bidirectional_iterator_set<const T>((Node<const T>*)this->_ptr, (Node<const T>*)this->_endNode); 
            }
            reference operator* () const
            {
                return (this->_ptr->value);
            }
            pointer operator-> ()
            {
                return &(this->operator*());
            }
            pointer operator-> () const
            {
                return &(this->operator*());
            }
            bidirectional_iterator_set operator++()
            {
               if (this->_ptr->parent && this->_ptr->parent == this->_ptr->left)
                    this->_ptr = this->_ptr->right;
                else if (this->_ptr->parent && this->_ptr->isleft && (!this->_ptr->left && !this->_ptr->right))
                    this->_ptr = this->_ptr->parent;
                else if (!this->_ptr->isleft && !this->_ptr->right)
                {
                    this->_ptr = tree::getParentPredecessor(this->_ptr);
                    if (!this->_ptr)
                        this->_ptr = this->_endNode;
                }
                else
                {
                    if (!tree::getSuccessor(this->_ptr))
                        this->_ptr = this->_ptr->parent;
                    else
                        this->_ptr = tree::getSuccessor(this->_ptr);
                }
                return bidirectional_iterator_set(this->_ptr, this->_endNode);
            }
            bidirectional_iterator_set operator++(int)
            {
                bidirectional_iterator_set tmp = *this;
                ++(*this);
                return tmp;
            }
            bidirectional_iterator_set operator--()
            {
                if (this->_ptr == this->_endNode)
                {
                    this->_ptr = tree::getMaximum(this->_ptr->parent);
                    return bidirectional_iterator_set(this->_ptr, this->_endNode);
                }
                else if (!this->_ptr->isleft && (!this->_ptr->right  && this->_ptr->left))
                    this->_ptr = tree::getPredecessor(this->_ptr);
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
                return bidirectional_iterator_set(this->_ptr, this->_endNode);
            }
            bidirectional_iterator_set operator--(int)
            {
                bidirectional_iterator_set tmp = *this;
                --(*this);
                return tmp;
            }
            template <class U>
            friend bool operator== (const bidirectional_iterator_set<U>& lhs, const bidirectional_iterator_set<U>& rhs);
            template <class U>
            friend bool operator!= (const bidirectional_iterator_set<U>& lhs, const bidirectional_iterator_set<U>& rhs);

        private:
            node_pointer _ptr;
            node_pointer _endNode;
    };
    template <class U>
    bool operator== (const bidirectional_iterator_set<U>& lhs, const bidirectional_iterator_set<U>& rhs)
    {
        return (lhs._ptr == rhs._ptr);
    }
    template <class U>
    bool operator!= (const bidirectional_iterator_set<U>& lhs, const bidirectional_iterator_set<U>& rhs)
    {
        return (lhs._ptr != rhs._ptr);
    }
}

#endif