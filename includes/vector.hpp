#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <memory>
# include <stdexcept>
# include <stdexcept>
# include "random_access_iterator.hpp"


namespace ft {
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {

        
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef ptrdiff_t difference_type;
            typedef size_t size_type;
            typedef ft::random_access_iterator<T> iterator;
            // typedef ft::random_access_iterator<T> const_iterator;
            // typedef ft::random_access_iterator<T> reverse_iterator;
            // typedef ft::random_access_iterator<T> const_reverse_iterator;

            explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _capacity(0), _array(NULL)  {}
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n), _array(this->_alloc.allocate(n)) {
                for (size_type i = 0; i < this->_size; i++)
                    this->_array[i] = val;
            }
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(std::distance(first, last)),
                _capacity(_size), _array(this->_alloc.allocate(this->_capacity))
            {
                for (size_type i = 0; first != last; first++)
                {
                    this->_array[i] = *first;
                    i++;
                }
            }
            vector (const vector& x)
            {
                this->_size = x.size();
                this->_capacity = this->_size;
                this->_alloc = x.get_allocator();
                this->_array = this->_alloc.allocate(this->_capacity);
                for (size_type i = 0; i < this->_size; i++)
                    this->_array[i] = x[i];
            }
            
            ~vector() 
            {
                if (this->_array)
                {
                    for (size_type i = 0; i < this->_size; i++)
                        this->_alloc.destroy(&this->_array[i]);
                    this->_alloc.deallocate(this->_array, this->_capacity);
                }
            }
            vector& operator= (const vector& x)
            {
                if (this != &x)
                {
                    if (this->_capacity >= x.size())
                        this->_size = x.size();
                    else
                    {
                        this->_size = x.size();
                        this->_alloc.deallocate(this->_array, this->_capacity);
                        this->_capacity = this->_size;
                        this->_array = this->_alloc.allocate(this->_capacity);
                    }
                    for (size_type i = 0; i < x.size(); i++)
                        this->_array[i] = x[i];
                }
                return *this;
            }
            

            // Iterators:
            iterator begin() { return (iterator(this->_array)); }
            //const_iterator begin() const;
            iterator end() { return (iterator(this->_array + this->_size)); }
            // const_iterator end() const;

            // Capacity :
            size_type size() const { return this->_size; }
            size_type max_size() const { return this->_alloc.max_size(); }
            size_type capacity() const { return this->_capacity; }
            bool empty() const { return this->_size == 0; }
            void resize (size_type n, value_type val = value_type())
            {
                try
                {
                    this->reserve(n);
                    if (this->_size > n)
                        for (size_type i = n; i < this->_size; i++)
                            this->_alloc.destroy(&this->_array[i]);
                    if (this->_size < n)
                        for (size_type i = this->_size; i < n; i++)
                            this->_array[i] = val;
                }
                catch (std::length_error &e)
                {
                    throw std::length_error("vector");
                }
                catch (std::bad_alloc &e)
                {
                    throw std::bad_alloc();
                }
                
            }
            void reserve( size_type new_cap )
            {
                pointer newArray;
                if (new_cap > this->max_size())
                    throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
                if (this->_capacity < new_cap)
                {
                    try
                    {
                        newArray = this->_alloc.allocate(new_cap);
                        this->_capacity = new_cap;
                        for (size_type i = 0; i < this->_size; i++)
                            newArray[i] = this->_array[i];
                        for (size_type i = 0; i < this->_size; i++)
                            this->_alloc.destroy(&this->_array[i]);
                        this->_alloc.deallocate(this->_array, this->_capacity);
                        this->_array  = newArray;
                    }
                    catch (std::bad_alloc &e)
                    {
                        throw std::bad_alloc();
                    }
                }
            }

            // Element access :
            reference operator[] (size_type n) { return this->_array[n]; }
            const_reference operator[] (size_type n) const { return this->_array[n]; }
            reference at (size_type n)
            {
                if (n < 0 || n > this->_size)
                    throw std::out_of_range("vector");
                return this->_array[n];
            }
            const_reference at (size_type n) const
            {
                if (n < 0 || n > this->_size)
                    throw std::out_of_range("vector");
                return this->_array[n];
            }
            reference front() { return this->_array[0]; }
            const_reference front() const { return this->_array[0]; }
            reference back() { return this->_array[this->_size]; }
            const_reference back() const { return this->_array[this->size]; }

            // Modifiers :
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last)
            {
                this->_size = std::distance(first, last);
                if (this->_capacity < this->_size)
                {
                    this->_alloc.deallocate(this->_array, this->_capacity);
                    this->_capacity = this->_size;
                    this->_array = this->_alloc.allocate(this->_capacity);
                }
                for (size_type i = 0; first != last; first++)
                {
                    this->_array[i] = *first;
                    i++;
                }
            }
            void assign (size_type n, const value_type& val)
            {
                this->_size = n;
                if (this->_capacity < n)
                {
                    this->_alloc.deallocate(this->_array, this->_capacity);
                    this->_capacity = this->_size;
                    this->_array = this->_alloc.allocate(this->_capacity);
                }
                for (size_type i = 0; i < this->_size; i++)
                    this->_array[i] = val;
            }
            void push_back (const value_type& val)
            {
                try
                {
                    if (this->_capacity < this->_size + 1)
                    {
                        if (!this->_capacity)
                            this->reserve(1);
                        else
                            this->reserve(this->_capacity * 2);
                    }
                    this->_size++;
                    this->_array[this->_size - 1] = val;
                }
                catch(const std::bad_alloc& e)
                {
                    throw std::bad_alloc();
                }
            }
            void pop_back()
            {
                if (this->_size)
                    this->_size--;
            }
            // iterator insert (iterator position, const value_type& val)
            // {
            //     value_type tmp = *position;
            //     try
            //     {
            //         this->reserve(std::distance(this->begin(), position) + 1);
            //     }
            //     catch(const std::bad_alloc& e)
            //     {
            //         throw std::bad_alloc();
            //     }
            //     *position = val;
            //     position++;
            //     for (iterator it = position; it != this->end(); it++)
            //         *it = 
            // }
            // void insert (iterator position, size_type n, const value_type& val);	
            // template <class InputIterator>
            // void insert (iterator position, InputIterator first, InputIterator last);
            // iterator erase (iterator position)
            // {
            //     try
            //     {
            //         this->reserve(std::distance(this->begin(), position));
            //     }
            //     catch(const std::bad_alloc& e)
            //     {
            //         throw std::bad_alloc();
            //     }
            //     //this->
                
            // }
            // iterator erase (iterator first, iterator last)
            // {
            //     while (first != last)
            //     {
            //         this->_alloc.destroy(first.base());
            //         first++;
            //         this->_size--;
            //     }
            //     if (!this->_size)
            //         this->_array = nullptr;
            //     return first;
            // }
            void clear()
            {
                for (size_type i = 0; i < this->_size; i++)
                    this->_alloc.destroy(&this->_array[i]);
                this->_size = 0;
            }
            // Allocator :
            allocator_type get_allocator() const { return this->_alloc; }
        private:
            allocator_type _alloc;
            size_type _size;
            size_type _capacity;
            pointer _array;
    };

    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() == rhs.size())
        {
            for (int i = 0; lhs.size() < i; i++)
            {
                if (lhs[i] != rhs[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (!ft::operator==(lhs, rhs))
            return true;
        return false;
    }

    // template <class T, class Alloc>
    // bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    // {

    // }

    // template <class T, class Alloc>
    // bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    // {

    // }

    // template <class T, class Alloc>
    // bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    // {

    // }

    // template <class T, class Alloc>
    // bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    // {

    // }
}




#endif
