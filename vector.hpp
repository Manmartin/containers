#ifndef VECTOR_HPP
# define VECTOR_HPP


# include <iterator.hpp>

namespace ft
{
    template < typename value_type >
    class VectorIterator: public ft::iterator<std::random_access_iterator_tag, value_type> {
        typedef ft::iterator<std::random_access_iterator_tag, value_type> iterator;
        public:
            typedef typename iterator::difference_type difference_type;

            VectorIterator( value_type *ptr  = NULL ): _Ptr(ptr) {}
            VectorIterator( VectorIterator const &ref ) { *this = ref; }
            ~VectorIterator() {}

            VectorIterator  &operator=( VectorIterator const &ref ) {
                this->_Ptr = ref._Ptr;
                return *this;
            }

            /* Incremental/Decremental operators */
            VectorIterator  &operator++( void ) {
                _Ptr++;
                return *this;
            }
            VectorIterator  operator++( int n ) {
                VectorIterator temp = *this;
                this->_Ptr += n == 0 ? 1 : n;
                return temp;
            }
            VectorIterator  &operator--( void ) {
                _Ptr--;
                return *this;
            }
            VectorIterator  operator--( int n ) {
                VectorIterator temp = *this;
                this->_Ptr -= n == 0 ? 1 : n;
                return temp;
            }

            VectorIterator  operator+( const difference_type n ) const { return _Ptr + n; }
            VectorIterator  operator+=( const difference_type n ) const { return _Ptr += n; }
            VectorIterator  operator-=( const difference_type n ) const { return _Ptr -= n; }
            VectorIterator  operator-( difference_type const n ) const { return _Ptr - n; }
            difference_type operator-( VectorIterator const &ref ) const { return _Ptr - ref._Ptr; }
            friend VectorIterator   operator+( difference_type const n, VectorIterator const &it ) { return it._Ptr + n; }

            typename iterator::reference operator*( void ) const { return *_Ptr; }
            typename iterator::reference operator[]( difference_type const n ) const { return *(_Ptr + n); }
            typename iterator::pointer operator->( void ) const { return &(operator*()); }

            bool    operator==( VectorIterator const &ref ) const { return this->_Ptr == ref._Ptr; }
            bool    operator!=( VectorIterator const &ref ) const { return this->_Ptr != ref._Ptr; }
            bool    operator>=( VectorIterator const &ref ) const { return this->_Ptr >= ref._Ptr; }
            bool    operator<=( VectorIterator const &ref ) const { return this->_Ptr <= ref._Ptr; }
            bool    operator>( VectorIterator const &ref ) const { return this->_Ptr > ref._Ptr; }
            bool    operator<( VectorIterator const &ref ) const { return this->_Ptr < ref._Ptr; }

        private:
            value_type* _Ptr;
    };

    

    template< class T, class Allocator = std::allocator<T> >
    class vector {
        public:
            /* Member types */

            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
                /* TODO:  reverse Iterators */
            typedef ft::VectorIterator<value_type>              iterator;
            typedef ft::VectorIterator<const value_type>        const_iterator;

            typedef typename iterator::difference_type    difference_type;
            typedef typename allocator_type::size_type          size_type;
            /* Constructors */
            
            explicit vector (const allocator_type &alloc = allocator_type()): _Alloc(alloc), _Cap(0), _Size(0), _Ptr(NULL) {}
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _Alloc(alloc) {
                    pointer aux = _Alloc.allocate(n);
                    for (size_type i = 0; i < n;i++)
                       _Alloc.construct(&aux[i], val);
                    _Ptr = aux;
                    _Cap = n;
                    _Size = n;
            }

            ~vector() { _Alloc.deallocate(_Ptr, _Cap); }

            /* Iterator functions */
            iterator    begin( void ) { return iterator(_Ptr); }
            iterator    end( void ) { return iterator(_Ptr + _Size); }

            /* Capacity functions */
            size_type size( void ) const { return _Size; }
            size_type max_size( void ) const { return _Alloc.max_size(); }
            size_type capacity( void ) const { return _Cap; }


        private:
            allocator_type  _Alloc;
            size_type       _Cap;
            size_type       _Size;
            pointer         _Ptr;
    };
}

#endif
