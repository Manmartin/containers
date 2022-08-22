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

    std::vector<int *> v;
    for (int i = 0; i < 10; i++)
        v.push_back(new int(i));
    std::cout << v.size() << '\n';
    std::cout << v.capacity() << '\n';
    v.resize(5);
    std::cout << v.size() << '\n';
    std::cout << v.capacity() << '\n';
    std::vector<int*>::iterator ita = v.begin();
    std::vector<int*>::iterator enda = v.end();
    while (ita != enda + 1)
    {
        std::cout << **ita++ << ' ';    
    }
    

    std::cout << '\n';
    typedef std::pair<int, std::string> p;
    vector<p> v2(5, p(5, "hola"));

    std::cout << "Capacity tests\n";
    std::cout << v2.size() << '\n';
    std::cout << v2.max_size() << '\n';
    std::cout << v2.capacity() << '\n';
    std::cout << '\n';

    std::vector<int>::iterator a;
    vector<p>::iterator it = v2.begin();
    vector<p>::iterator end = v2.end();
    std::cout << (it == end) << '\n';
    std::cout << (it != end) << '\n';
    std::cout << (it >= end) << '\n';
    std::cout << (it <= end) << '\n';
    std::cout << (it > end) << '\n';
    std::cout << (it < end) << '\n';

    while (it != end)
    {
        std::cout << '\n';
        return 0;
    }
    std::cout << '\n';

    /*
    v2.push_back(1);
    std::cout << v2.size() << '\n';
    std::cout << v2.capacity() << '\n';
    std::cout << '\n';
    v2.push_back(1);
    std::cout << v2.size() << '\n';
    std::cout << v2.capacity() << '\n';
    std::cout << '\n';
    v2.push_back(1);
    std::cout << v2.size() << '\n';
    std::cout << v2.capacity() << '\n';
    std::cout << '\n';
 */
    /*
    std::cout << "My vector\n";
    vector<int> v3(5, 4);
    std::cout << v3.size() << '\n';
    std::cout << v3.max_size() << '\n';
    std::cout << v3.capacity() << '\n';

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
    */
}
