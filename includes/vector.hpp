#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <memory>
# include <stdexcept>


namespace ft {
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;

        private:
            allocator_type _alloc;
            size_type _size;
            size_type _capacity;
            pointer _array;
        
        public:
            explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _capacity(0), _array(NULL)  {}
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n), _array(this->_alloc.allocate(n)) {
                for (size_type i = 0; i < this->_size; i++)
                    this->_array[i] = val;
            }
            // template <class InputIterator>
            // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            // vector (const vector& x);
            ~vector() 
            {
                if (this->_array)
                    this->_alloc.deallocate(this->_array, this->_capacity);
            }


            // Capacity :
            size_type size() const { return this->_size; }
            size_type max_size() const { return this->_alloc.max_size(); }
            size_type capacity() const { return this->_capacity; }
            bool empty() const { return this->_size == 0; }

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



            // Allocator :
            allocator_type get_allocator() const { return this->_alloc; }
    };

    // class out_of_range : public std::logic_error
    // {
    //     public:
    //     explicit out_of_range (const string& what_arg) : logic_error(what_arg) {};
    // };
}


#endif
