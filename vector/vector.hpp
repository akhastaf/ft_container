#ifndef VECTOR_HPP
# define VECTOR_HPP
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
            typedef typename ft::random_access_iterator<value_type> iterator;
            typedef typename ft::random_access_iterator<const value_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

            explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _capacity(0), _array(NULL)  {}
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
                _alloc =alloc;
                _size = n;
                _capacity = n;
                _array = _alloc.allocate(_size);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(_array + i, val);
            }
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()) : _alloc(alloc), _size(abs(std::distance(first, last))),
                _capacity(_size), _array(_alloc.allocate(_capacity))
            {
                // difference_type d = abs(std::distance(first, last));
                // if (InputIterator::iterator_category == std::input_iterator_tag)
                // {
                //     clear();
                //     for (; first != last; first++)
                //         push_back(*first);
                //     return;
                // }
                for (size_type i = 0; first != last; first++)
                {
                    _alloc.construct(_array + i, *first);
                    i++;
                }
            }
            vector (const vector & x)
            {
                _size = x.size();
                _capacity = _size;
                _alloc = x.get_allocator();
                _array = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(_array + i, x[i]);
            }
            
            ~vector() 
            {
                if (_array)
                {
                    for (size_type i = 0; i < _size; i++)
                        _alloc.destroy(&_array[i]);
                    _alloc.deallocate(_array, _capacity);
                }
            }
            vector& operator= (const vector& x)
            {
                if (this != &x)
                {
                    if (_capacity >= x.size())
                        _size = x.size();
                    else
                    {
                        _size = x.size();
                        _alloc.deallocate(_array, _capacity);
                        _capacity = _size;
                        _array = _alloc.allocate(_capacity);
                    }
                    for (size_type i = 0; i < x.size(); i++)
                        _alloc.construct(_array + i, x[i]);
                }
                return *this;
            }
            

            // Iterators:
            iterator begin() { return (iterator(_array)); }
            const_iterator begin() const { return const_iterator(_array); }
            iterator end() { return (iterator(_array + _size)); }
            const_iterator end() const { return const_iterator(_array + _size); }
            reverse_iterator rbegin() { return reverse_iterator(end()); }
            const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
            reverse_iterator rend() { return reverse_iterator(begin()); }
            const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

            // Capacity :
            size_type size() const { return _size; }
            size_type max_size() const { return _alloc.max_size(); }
            size_type capacity() const { return _capacity; }
            bool empty() const { return _size == 0; }
            void resize (size_type n, value_type val = value_type())
            {
                try
                {
                    reserve(n);
                    if (_size > n)
                    {
                        for (size_type i = n; i < _size; i++)
                            _alloc.destroy(&_array[i]);
                    }
                    if (_size < n)
                    {
                        for (size_type i = _size; i < n; i++)
                            _alloc.construct(_array + i, val);
                    }
                    _size = n;
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
                if (new_cap > max_size())
                    throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
                if (_capacity < new_cap)
                {
                    try
                    {
                        newArray = _alloc.allocate(new_cap);
                        for (size_type i = 0; i < _size; i++)
                        {
                            _alloc.construct(newArray + i, _array[i]);
                            _alloc.destroy(_array + i);
                        }
                        _alloc.deallocate(_array, _capacity);
                        _capacity = new_cap;
                        _array  = newArray;
                    }
                    catch (std::bad_alloc &e)
                    {
                        throw std::bad_alloc();
                    }
                }
            }

            // Element access :
            reference operator[] (size_type n) { return _array[n]; }
            const_reference operator[] (size_type n) const { return _array[n]; }
            reference at (size_type n)
            {
                if (n < 0 || n >= _size)
                    throw std::out_of_range("vector");
                return _array[n];
            }
            const_reference at (size_type n) const
            {
                if (n < 0 || n >= _size)
                    throw std::out_of_range("vector");
                return _array[n];
            }
            reference front() { return _array[0]; }
            const_reference front() const { return _array[0]; }
            reference back() { return _array[_size - 1]; }
            const_reference back() const { return _array[_size - 1]; }

            // Modifiers :
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last)
            {
                _size = std::distance(first, last);
                if (_capacity < _size)
                {
                    _alloc.deallocate(_array, _capacity);
                    _capacity = _size;
                    _array = _alloc.allocate(_capacity);
                }
                for (size_type i = 0; first != last; first++)
                {
                    _alloc.construct(_array + i, *first);
                    i++;
                }
            }
            void assign (size_type n, const value_type& val)
            {
                _size = n;
                if (_capacity < n)
                {
                    _alloc.deallocate(_array, _capacity);
                    _capacity = _size;
                    _array = _alloc.allocate(_capacity);
                }
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(_array + i, val);
            }
            void push_back (const value_type& val)
            {
                try
                {
                    if (_capacity < _size + 1)
                    {
                        if (!_capacity)
                            reserve(1);
                        else
                            reserve(_capacity * 2);
                    }
                    _size++;
                    _alloc.construct(_array + (_size - 1), val);
                }
                catch(const std::bad_alloc& e)
                {
                    throw std::bad_alloc();
                }
            }
            void pop_back()
            {
                if (_size)
                {
                    _size--;
                    _alloc.destroy(_array + _size);
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                difference_type d = abs(std::distance(begin(), position));
                if (_size + 1 > _capacity)
                {
                    if (!_capacity)
                        reserve(1);
                    else
                        reserve(_capacity * 2);
                }
                if (_size)
                {
                    for (size_type i = d + 1; i <= _size ;i++)
                        std::swap(_array[d], _array[i]);
                }
                _size++;
                _alloc.construct(_array + d, val);
                return (iterator(_array + d));
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                difference_type d = std::distance(begin(), position);
                if (_size + n > _capacity)
                {
                    if (_size + n <= _capacity * 2)
                        reserve(_capacity * 2);
                    else
                        reserve(_size + n);
                }
                if (_size)
                {
                    for (int i = _size - 1; d <= i; i--)
                        _array[i + n] = _array[i];
                }
                for (size_type i = d; i < n + d; i++)
                    _alloc.construct(_array + i, val);
                _size += n;
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
            {
                difference_type d = abs(std::distance(begin(), position));
                difference_type n = abs(std::distance(first, last));
                if (_size + n > _capacity)
                {
                    if (_size + n <= _capacity * 2)
                        reserve(_capacity * 2);
                    else
                        reserve(_size + n);
                }
                if (_size)
                {
                    for (difference_type i = d; i < d + n; i++)
                        _array[i + n] = _array[i];
                }
                for (size_type i = d; first != last; first++)
                {
                    _alloc.construct(_array + i, *first);
                    i++;
                }
                _size += n;
            }
            iterator erase (iterator position)
            {
                difference_type d = std::distance(begin(), position);
                for (size_type i = d; i < _size; i++)
                    _array[i] = _array[i + 1];
                _alloc.destroy((_array - 1) + d);
                _size--;
                return (iterator(_array + d));
            }
            iterator erase (iterator first, iterator last)
            {
                difference_type d = abs(std::distance(begin(), first));
                difference_type n = abs(std::distance(first, last));
                for (int i = d; i < d + n; i++)
                    _alloc.destroy(_array + i);
                if (_size != (size_type)n)
                    for (difference_type i = d; i + n < (difference_type)_size ; i++)
                        _array[i] = _array[i + n];
                _size -= n;
                return (iterator(_array + d));
            }
            void swap (vector& x)
            {
                size_type tmp = x._size;
                x._size = _size;
                _size = tmp;
                tmp = x._capacity;
                x._capacity = _capacity;
                _capacity = tmp;
                pointer data = x._array;
                x._array = _array;
                _array = data;
            }
            void clear()
            {
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(&_array[i]);
                _size = 0;
            }
            // Allocator :
            allocator_type get_allocator() const { return _alloc; }
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
            return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
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

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !ft::operator<(rhs, lhs);
    }

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::operator<(rhs, lhs);
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !ft::operator<(lhs, rhs);
    }
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
}

#endif
