#define CRTP true
#include <iostream>
#ifdef CRTP
    #include "ShapesCRTP.tpp"
#else
    #include "Shapes.hpp"
#endif

#include<vector>

int main(int argc, char *argv[])
{
    std::vector<Shape*> v;	
    v.push_back(new Rectangle);
    v.push_back(new Triangle);
    v.push_back(new Circle);

    for (auto s : v) {
        Shape* c = s->Clone();
        int x = 0;
    }

    return 0;
}

