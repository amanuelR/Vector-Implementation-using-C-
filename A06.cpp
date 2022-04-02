#include <iostream>
#include "Container.h"
#include "Vector.h"
using namespace std;
int main()
{
    CS52::Container *container [2];
    container [0] = new  CS52::Vector(2,1);
    container [1] = new  CS52::Vector(5,3);//  Print  out  the  type  and  length  of each  Container  element
    std::cout  << "\n\ntest  polymorphism\n";
    for (int i = 0; i < 2; i++)
    {
        std::cout  << "Container[" << i << "]" << " is a "<< container[i]->type ();    // delete  Vector  Objects  Pointed  to by  Container
        std::cout  << " with  length " << container[i]->size() << "\n";

    }
    for (int i = 0; i < 2; i++)
        delete  container[i];
    return  0;
}
