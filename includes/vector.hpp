#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <memory>
# include <stdexcept>
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
                    this->_alloc.deallocate(this->_array, this->_capacity);
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
            // template <class InputIterator>
            // void assign (InputIterator first, InputIterator last);	
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
                pointer newArray;
                if (this->_capacity < this->_size + 1)
                {
                    try
                    {
                        newArray = this->_alloc.allocate(this->_capacity == 0 ? 1 : this->_capacity * 2);
                        for (size_type i = 0; i < this->_size; i++)
                            newArray[i] = this->_array[i];
                        this->_alloc.deallocate(this->_array, this->_capacity);
                        this->_array = newArray;
                        this->_array[this->_size] = val;
                        this->_size++;
                        this->_capacity = this->_capacity == 0 ? 1 : this->_capacity * 2;
                    }
                    catch(const std::bad_alloc& e)
                    {
                        throw std::bad_alloc();
                    }
                }
                else
                {
                    this->_array[this->_size] = val;
                    this->_size++;
                }
            }
            void pop_back()
            {
                if (this->_size)
                {
                    this->_size--;
                    this->_alloc.destroy(&this->_array[this->_size]);
                }
            }
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
