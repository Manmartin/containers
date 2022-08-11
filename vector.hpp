#ifndef VECTOR_HPP
# define VECTOR_HPP


# include <iterator.hpp>

namespace ft
{
    template < typename value_type >
    class VectorIterator: public ft::iterator<std::random_access_iterator_tag, value_type> {
        
        VectorIterator( void ) {
        }
        ~VectorIterator() {}

        private:
    };

    template< class T, class Allocator = std::allocator<T> >
    class vector {
        public:
            /* Member types */

            typedef T value_type;
            typedef Allocator allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
                /* TODO:  reverse Iterators */
            typedef ft::VectorIterator<value_type> iterator;
            typedef ft::VectorIterator<const value_type> const_iterator;

            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef std::size_t size_type;
            /* Constructors */
            
            explicit vector (const allocator_type &alloc = allocator_type()): _Alloc(alloc), _Cap(0), _Size(0), _Ptr(NULL) {}
            
            /* Destructor */
            ~vector() {}
            /* Iterator functions */
            iterator    begin( void ) { return iterator(_Ptr); }

            /* Capacity functions */
            size_type size( void ) const { return _Size; }
            size_type max_size( void ) const { return _Alloc.max_size(); }
            size_type capacity( void ) const { return _Cap; }


        private:
            allocator_type  _Alloc;
            size_type       _Cap;
            size_type       _Size;
            T*              _Ptr;
    };
}

#endif
