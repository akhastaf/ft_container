#ifndef stack_HPP
# define stack_HPP
# include "../vector/vector.hpp"
namespace ft
{
    template <class T, class Container = vector<T> >
    class stack
    {
         public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;

            explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) {}
            bool empty() const { return this->_c.empty(); }
            size_type size() const { return this->_c.size(); }
            value_type& top() { return this->_c.back(); }
            const value_type& top() const { return this->_c.back(); }
            void push (const value_type& val) { this->_c.push_back(val); }
            void pop() { this->_c.pop_back(); }
            template <class U, class Container1>
            friend bool operator== (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs);
            template <class U, class Container1>
            friend bool operator!= (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs);
            template <class U, class Container1>
            friend bool operator<  (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs);
            template <class U, class Container1>
            friend bool operator<= (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs);
            template <class U, class Container1>
            friend bool operator>  (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs);
            template <class U, class Container1>
            friend bool operator>= (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs); 
        protected:
            container_type _c;
    };
    template <class U, class Container1>
    bool operator== (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs)
    {
        return (lhs._c == rhs._c);
    }

    template <class U, class Container1>
    bool operator!= (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs)
    {
        return (lhs._c != rhs._c);
    }

    template <class U, class Container1>
    bool operator<  (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs)
    {
        return (lhs._c < rhs._c);
    }

    template <class U, class Container1>
    bool operator<= (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs)
    {
        return (lhs._c <= rhs._c);
    }

    template <class U, class Container1>
    bool operator>  (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs)
    {
        return (lhs._c > rhs._c);
    }

    template <class U, class Container1>
    bool operator>= (const stack<U,Container1>& lhs, const stack<U,Container1>& rhs)
    {
        return (lhs._c >= rhs._c);
    }
}

#endif
