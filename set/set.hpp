#ifndef SET_HPP
# define SET_HPP
# include <iostream>
# include <memory>
# include <stdexcept>
# include <algorithm>
# include "../iterator/reverse_iterator.hpp"
# include "bidirectional_iterator_set.hpp"
# include "../tools.hpp"
# include "../vector/vector.hpp"


namespace ft
{
    template < class T,                        // set::key_type/value_type
           class Compare = std::less<T>,        // set::key_compare/value_compare
           class Alloc = std::allocator<T>      // set::allocator_type
           >
    class set
    {
        public:
            typedef T                                                           key_type;        
            typedef T                                                           value_type;        
            typedef Compare                                                     key_compare;        
            typedef std::less<value_type>                                       value_compare;        
            typedef Alloc                                                       allocator_type;        
            typedef typename allocator_type::reference                          reference;        
            typedef typename allocator_type::const_reference                    const_reference;        
            typedef typename allocator_type::pointer                            pointer;        
            typedef typename allocator_type::const_pointer                      const_pointer;        
            typedef ft::bidirectional_iterator_set<value_type>                  iterator;        
            typedef ft::bidirectional_iterator_set<const value_type>            const_iterator;        
            typedef ft::reverse_iterator<iterator>                              reverse_iterator;        
            typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;        
            typedef ptrdiff_t                                                   difference_type;        
            typedef size_t                                                      size_type;
            typedef ft::RedBlackTree<value_type, allocator_type, key_compare>   tree;



            explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _tree(tree()), _key_compare(comp) {}
            template <class InputIterator>
            set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _tree(tree()), _key_compare(comp)
            {
                for (; first != last; ++first)
                    insert(*first);
            }
            set (const set& x) : _alloc(x.get_allocator()), _tree(tree()), _key_compare(x.key_comp())
            {
                const_iterator it = x.begin();
                for (; it != x.end(); it++)
                    insert(*it);
            }
            ~set() {}
            set& operator= (const set& x)
            {
                _tree.clear();
                _alloc = x.get_allocator();
                _key_compare = x.key_comp();
                _tree._endNode = x._tree._endNode;
                this->insert(x.begin(), x.end());
                return *this;
            }
            
            // Iterators
            iterator begin() { return this->_tree.begin(); }
            const_iterator begin() const { return this->_tree.begin(); }
            iterator end() { return this->_tree.end(); }
            const_iterator end() const { return this->_tree.end(); }
            reverse_iterator rbegin() { return this->_tree.rbegin(); }
            const_reverse_iterator rbegin() const { return this->_tree.rbegin(); }
            reverse_iterator rend() { return this->_tree.rend(); }
            const_reverse_iterator rend() const { return this->_tree.rend(); }

            // Capacity
            bool empty() const { return _tree.empty();}
            size_type size() const { return _tree.size();}
            size_type max_size() const { return _tree.max_size();}

            // Modifiers
            ft::pair<iterator,bool> insert (const value_type& val) { return _tree.insert(val); }
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                return _tree.insert(val).first;
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                 for (; first != last; first++)
                    this->insert(*first);
            }
            void erase (iterator position)  { _tree.remove(*position); }
            size_type erase (const value_type& val) { return _tree.remove(val);  }
            void erase (iterator first, iterator last)
            {
                ft::vector <key_type> key_to_remove;
				while (first != last)
				{
					key_to_remove.push_back(*first);
                    first++;
				}
				for (size_t i = 0; i < key_to_remove.size(); i++)
                    erase(key_to_remove[i]);
            }
            void swap (set& x)
            {
                std::swap(x._tree._endNode, this->_tree._endNode);
				std::swap(x._tree._root, this->_tree._root);
				std::swap(x._tree._alloc_node, this->_tree._alloc_node);
				std::swap(x._tree._alloc, this->_tree._alloc);
				std::swap(x._tree._size, this->_tree._size);
				
				std::swap(x._key_compare, this->_key_compare);
				std::swap(x._alloc, this->_alloc);
            }
            void clear() { _tree.clear(); }

            // Obeservers
            key_compare key_comp() const { return _key_compare; }
            value_compare value_comp() const { return value_compare(); }

            // Operations
            iterator find (const value_type& val) const { return _tree.ifind(val); }
            size_type count (const value_type& val) const { return _tree.contains(val); }
            iterator lower_bound (const value_type& val) const { return _tree.lower_bound(val); }
            iterator upper_bound (const value_type& val) const { return _tree.upper_bound(val); }
            ft::pair<iterator,iterator> equal_range (const value_type& val) const { return ft::make_pair(lower_bound(val), upper_bound(val)); }

            // Alocator
            allocator_type get_allocator() const { return _alloc; }
            void    print2D() { _tree.print2D(); } 

        private:
            allocator_type _alloc;
            tree           _tree;
            key_compare    _key_compare;

    };
    template <class T_, class Compare_, class Alloc_>
    bool operator== ( const ft::set<T_,Compare_,Alloc_>& lhs, const ft::set<T_,Compare_,Alloc_>& rhs ){
        if (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
            return (true);
        return (false);
    }
    
    template <class T_, class Compare_, class Alloc_>
    bool operator!= ( const ft::set<T_,Compare_,Alloc_>& lhs, const ft::set<T_,Compare_,Alloc_>& rhs ){
        return !(lhs == rhs);
    }
    
    template <class T_, class Compare_, class Alloc_>
    bool operator<  ( const ft::set<T_,Compare_,Alloc_>& lhs, const ft::set<T_,Compare_,Alloc_>& rhs ){
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    
    template <class T_, class Compare_, class Alloc_>
    bool operator<= ( const ft::set<T_,Compare_,Alloc_>& lhs, const ft::set<T_,Compare_,Alloc_>& rhs ){
        return !(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));

    }
    
    template <class T_, class Compare_, class Alloc_>
    bool operator>  ( const ft::set<T_,Compare_,Alloc_>& lhs, const ft::set<T_,Compare_,Alloc_>& rhs ){
        return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }
    
    template <class T_, class Compare_, class Alloc_>
    bool operator>= ( const ft::set<T_,Compare_,Alloc_>& lhs, const ft::set<T_,Compare_,Alloc_>& rhs ){
        return !(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

}



#endif