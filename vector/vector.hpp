#ifndef Vector_HPP
# define Vector_HPP
# include <iostream>
# include <memory>
# include <stdexcept>
# include <stdexcept>
# include <algorithm>
#include <iterator>
# include "../iterator/random_access_iterator.hpp"
# include "../iterator/reverse_iterator.hpp"
# include "../tools.hpp"

namespace ft {
    template <class T, class Alloc = std::allocator<T> >
    class Vector
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
            typedef ft::random_access_iterator<const T> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

            explicit Vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _capacity(0), _array(NULL)  {}
            explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n) {
                std::cout << this->_size << std::endl;
                this->_array = this->_alloc.allocate(this->_size);
                for (size_type i = 0; i < this->_size; i++)
                    this->_alloc.construct(this->_array + i, val);
            }
            template <class InputIterator>
            Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()) : _alloc(alloc), _size(std::distance(first, last)),
                _capacity(_size), _array(this->_alloc.allocate(this->_capacity))
            {
                for (size_type i = 0; first != last; first++)
                {
                    this->_array[i] = *first;
                    i++;
                }
            }
            Vector (const Vector & x)
            {
                this->_size = x.size();
                this->_capacity = this->_size;
                this->_alloc = x.get_allocator();
                this->_array = this->_alloc.allocate(this->_capacity);
                for (size_type i = 0; i < this->_size; i++)
                    this->_alloc.construct(this->_array + i, x[i]);
            }
            
            ~Vector() 
            {
                if (this->_array)
                {
                    for (size_type i = 0; i < this->_size; i++)
                        this->_alloc.destroy(&this->_array[i]);
                    this->_alloc.deallocate(this->_array, this->_capacity);
                }
            }
            Vector& operator= (const Vector& x)
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
                        this->_alloc.construct(this->_array + i, x[i]);
                }
                return *this;
            }
            

            // Iterators:
            iterator begin() { return (iterator(this->_array)); }
            const_iterator begin() const { return const_iterator(this->_array); }
            iterator end() { return (iterator(this->_array + this->_size)); }
            const_iterator end() const { return const_iterator(this->_array + this->_size); }
            reverse_iterator rbegin() { return reverse_iterator(--(this->end())); }
            //const_reverse_iterator rbegin() const { return reverse_iterator(this->end()--); }
            reverse_iterator rend() { return reverse_iterator(--(this->begin())); }
            //const_reverse_iterator rend() const  { return reverse_iterator(this->begin()--); }

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
                    {
                        for (size_type i = n; i < this->_size; i++)
                            this->_alloc.destroy(&this->_array[i]);
                    }
                    if (this->_size < n)
                    {
                        for (size_type i = this->_size; i < n; i++)
                            this->_alloc.construct(this->_array + i, val);
                    }
                }
                catch (std::length_error &e)
                {
                    throw std::length_error("Vector");
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
                        for (size_type i = 0; i < this->_size; i++)
                            this->_alloc.construct(newArray + i, this->_array[i]);
                        for (size_type i = 0; i < this->_size; i++)
                            this->_alloc.destroy(this->_array + i);
                        this->_alloc.deallocate(this->_array, this->_capacity);
                        this->_capacity = new_cap;
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
                    throw std::out_of_range("Vector");
                return this->_array[n];
            }
            const_reference at (size_type n) const
            {
                if (n < 0 || n > this->_size)
                    throw std::out_of_range("Vector");
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
                    this->_alloc.construct(this->_array + i, *first);
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
                    this->_alloc.construct(this->_array + i, val);
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
                    this->_alloc.construct(this->_array + (this->_size - 1), val);
                }
                catch(const std::bad_alloc& e)
                {
                    throw std::bad_alloc();
                }
            }
            void pop_back()
            {
                if (this->_size)
                {
                    this->_size--;
                    this->destroy(this->_array + this->_size);
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                difference_type d = std::distance(this->begin(), position);
                if (this->_size + 1 > this->_capacity)
                {
                    if (!this->_capacity)
                        this->reserve(1);
                    else
                        this->reserve(this->_capacity * 2);
                }
                this->_size++;
                for (size_type i = this->_size; i >= d ;i--)
                    this->_array[i - 1] = this->_array[i];
                this->_alloc.construct(this->_array + d, val);
                return (iterator(this->_array + d));
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                difference_type d = std::distance(this->begin(), position);
                std::cout << this->_capacity << std::endl;
                if (this->_size + n > this->_capacity)
                    this->reserve(this->_size + n);
                for (int i = this->_size - 1; d <= i; i--)
                    this->_array[i + n] = this->_array[i];
                for (size_type i = d; i < n + d; i++)
                    this->_alloc.construct(this->_array + i, val);
                this->_size += n;
            }

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
            {
                difference_type d = std::distance(this->begin(), position);
                difference_type n = std::distance(first, last);
                if (this->_size + n > this->_capacity)
                    this->reserve(this->_size + n);
                for (size_type i = d; i < this->_size + n; i++)
                    this->_array[i + n] = this->_array[i];
                for (size_type i = d; first != last; first++)
                {
                    this->_alloc.construct(this->_array + i, *first);
                    i++;
                }
                this->_size += n;
            }
            iterator erase (iterator position)
            {
                difference_type d = std::distance(this->begin(), position);
                for (size_type i = d; i < this->_size; i++)
                    this->_array[i] = this->_array[i + 1];
                this->_alloc.destroy((this->_array - 1) + d);
                this->_size--;
                return (iterator(this->_array + d));
            }
            iterator erase (iterator first, iterator last)
            {
                difference_type d = std::distance(this->begin(), first);
                difference_type n = std::distance(first, last);

                for (int i = d; i < this->_size; i++)
                    this->_array[i] = this->_array[i + n];
                for (int i = d; i < n; i++)
                    this->_alloc.destroy(this->_array + i);
                this->_size -= n;
                return (iterator(this->_array + d));
            }
            void swap (Vector& x)
            {
                size_type tmp = x._size;
                x._size = this->_size;
                this->_size = tmp;
                tmp = x._capacity;
                x._capacity = this->_capacity;
                this->_capacity = tmp;
                pointer data = x._array;
                x._array = this->_array;
                this->_array = data;
            }
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
    bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        if (lhs.size() == rhs.size())
        {
            return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
        }
        return false;
    }

    template <class T, class Alloc>
    bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        if (!ft::operator==(lhs, rhs))
            return true;
        return false;
    }

    template <class T, class Alloc>
    bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        return !ft::operator<(rhs, lhs);
    }

    template <class T, class Alloc>
    bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        return ft::operator<(rhs, lhs);
    }

    template <class T, class Alloc>
    bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        return !ft::operator<(lhs, rhs);
    }
}

#endif
