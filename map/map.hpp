#ifndef MAP_HPP
# define MAP_HPP
#include <iostream>
# include <memory>
# include <stdexcept>
# include <algorithm>
# include "../iterator/reverse_iterator.hpp"
# include "RedBlackTree.hpp"
#include "../tools.hpp"

namespace   ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
    class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef pair<const key_type,mapped_type> value_type;
            typedef Compare key_compare;
            typedef class value_compare : std::binary_function<value_type,value_type,bool>
            {   
                friend class Map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            }    value_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename ft::bidirectional_iterator<value_type> iterator;
            typedef typename ft::bidirectional_iterator<const value_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef ft::RedBlackTree<value_type, key_compare, allocator_type>   tree;
            typedef ptrdiff_t                                                difference_type;
            typedef size_t                                                   size_type;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(tree()), _key_comp(comp), _alloc(alloc)
            {

            }
            // template <class InputIterator>
            // map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            // map (const map& x);
            ~map() { }
            // map& operator= (const map& x) {}

            // Iterator
            iterator begin() { return this->_tree.begin(); }
            // const_iterator begin() const { return this->_tree.begin(); }
            iterator end() { return this->_tree.end(); }
            // const_iterator end() const { return this->_tree.end(); }
            // reverse_iterator rbegin() { return this->_tree.rbegin(); }
            // const_reverse_iterator rbegin() const { return this->_tree.rbegin(); }
            // reverse_iterator rend() { return this->_tree.rend(); }
            // const_reverse_iterator rend() const { return this->_tree.rend(); }

            // Capacity
            bool empty() const { return this->_tree.empty(); }
            size_type size() const { return this->_tree.size(); }
            size_type max_size() const { return this->_tree.max_size(); }
            
            // Element access
            // mapped_type& operator[] (const key_type& k) {}

            // Modifiers
            pair<iterator,bool> insert (const value_type& val) { return this->_tree.insert(val); }
            iterator insert (iterator position, const value_type& val) 
            {
                (void)position;
                return (this->insert(val)).first;
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                for (; first != last; first++)
                    this->insert(*first);
            }
            void erase (iterator position) { this->_tree.remove(position->first); }
            size_type erase (const key_type& k) { return this->_tree.remove(k);  }
            void erase (iterator first, iterator last) 
            {
                for (; first != last; first++)
                    this->erase(first->first);
            }
            // void swap (map& x) {}
            void clear() { this->_tree.clear(); }

            // Observers
            key_compare key_comp() const { return this->_key_comp; }
            value_compare value_comp() const { return value_compare(); }

            // Operations
            iterator find (const key_type& k) { return this->_tree.ifind(k); }
            const_iterator find (const key_type& k) const { return this->_tree.ifind(k); }
            size_type count (const key_type& k) const { return this->_tree.contains(k); }
            iterator lower_bound (const key_type& k) { return this->_tree.lower_bound(k); }
            const_iterator lower_bound (const key_type& k) const { return this->_tree.lower_bound(k); }
            iterator upper_bound (const key_type& k) { return this->_tree.upper_bound(k); }
            const_iterator upper_bound (const key_type& k) const { return this->_tree.upper_bound(k); }
            void    check_balance() { this->_tree.balckNode(); }
            void    print2D() { this->_tree.print2D(); }
        private:
            tree _tree;
            key_compare _key_comp;
            //value_compare _value_comp;
            allocator_type _alloc;
    };
}

#endif