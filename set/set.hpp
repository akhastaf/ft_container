#ifndef SET_HPP
# define SET_HPP
#include <iostream>
# include <memory>
# include <stdexcept>
# include <algorithm>
# include "../iterator/reverse_iterator.hpp"
# include "RedBlackTree.hpp"
#include "../tools.hpp"


namespace ft
{
    template < class T,                        // set::key_type/value_type
           class Compare = std::less<T>,        // set::key_compare/value_compare
           class Alloc = std::allocator<T>      // set::allocator_type
           >
    class set
    {
        
    };

} // namespace ft



#endif