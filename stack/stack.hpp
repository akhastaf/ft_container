#ifndef STACK_HPP
# define STACK_HPP
# include "../vector/Vector.hpp"
namespace ft
{
    template <class T, class Container = Vector<T> >
    class Stack
    {
         public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;

            explicit Stack (const container_type& ctnr = container_type()) : _c(ctnr) {}
            bool empty() const { return this->_c.empty(); }
            size_type size() const { return this->_c.size(); }
            value_type& top() { return this->_c.back(); }
            const value_type& top() const { return this->_c.back(); }
            void push (const value_type& val) { this->_c.push_back(val); }
            void pop() { this->_c.pop_back(); }
            friend bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs);
            friend bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs);
            friend bool operator<  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs);
            friend bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs);
            friend bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs);
            friend bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs); 
        protected:
            container_type _c;
    };
    template <class T, class Container>
    bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
    {
        return (lhs._c == rhs._c);
    }

    template <class T, class Container>
    bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
    {
        return (lhs._c != rhs._c);
    }

    template <class T, class Container>
    bool operator<  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
    {
        return (lhs._c < rhs._c);
    }

    template <class T, class Container>
    bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
    {
        return (lhs._c <= rhs._c);
    }

    template <class T, class Container>
    bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
    {
        return (lhs._c > rhs._c);
    }

    template <class T, class Container>
    bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
    {
        return (lhs._c >= rhs._c);
    }
}

#endif
