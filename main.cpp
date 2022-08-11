#include <iostream>
#include <vector>
#include <vector.hpp>
#include <typeinfo>

#ifndef NAMESPACE
# define NAMESPACE std 
#endif

using NAMESPACE::vector;

int main(void) {
    /* Vector Iterator */
    /* Iterator traits */
    /* Vector member types */

    std::cout << "Init tests\n\n";
    vector<int> v;

    std::cout << v.size() << '\n';
    std::cout << v.max_size() << '\n';
    std::cout << v.capacity() << '\n';

    typedef ft::iterator_traits< ft::VectorIterator<int> > a;
    std::cout << "iterator_traits tests\n\n";
    std::cout << typeid(a::value_type).name() << '\n';
    std::cout << typeid(a::difference_type).name() << '\n';
    std::cout << typeid(a::pointer).name() << '\n';
    std::cout << typeid(a::reference).name() << '\n';
    std::cout << typeid(a::iterator_category).name() << '\n';

    std::cout << "Vector types tests\n\n";
    std::cout << typeid(vector<std::string>::value_type).name() << '\n';
    std::cout << typeid(vector<std::string>::allocator_type).name() << '\n';
    std::cout << typeid(vector<std::string>::reference).name() << '\n';
    std::cout << typeid(vector<std::string>::const_reference).name() << '\n';
    return 0;
}
