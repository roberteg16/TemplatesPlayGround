#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <iostream>


template<typename T>
struct counter
{
    static int objects_created;
    static int objects_alive;

    counter()
    {
        ++objects_created;
        ++objects_alive;
    }

    counter(const counter&)
    {
        ++objects_created;
        ++objects_alive;
    }
protected:
    ~counter() // objects should never be removed through pointers of this type
    {
        --objects_alive;
    }
};

template <typename T>
int
counter<T>::objects_created( 0 );

template <typename T>
int
counter<T>::objects_alive( 0 );

class Foo : counter<Foo>
{
    public:
    ~Foo() = default;
};

class Bar : counter<Bar>
{};

int main(int argc, char *argv[])
{
    Foo x1;
    Bar y1;
//
// Foo: 1
// Bar: 1
//
    Foo x2;

//
// Foo: 2
//

    {
        Bar y2;
        //
        // Bar: 2
        //
    }

    //
    // Bar: 1
    //

    std::cout << counter<Foo>::objects_created << std::endl; // Should print 2
    std::cout << counter<Foo>::objects_alive << std::endl; // Should print 2

    std::cout << counter<Bar>::objects_created << std::endl; // Should print 2
    std::cout << counter<Bar>::objects_alive << std::endl; // Should print 1

    return 0;
}


#endif /*__COUNTER_H__ */
