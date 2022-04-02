#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
namespace CS52
{
    class  Container
    {
        public:
            virtual  int size()  const = 0;
            virtual  std:: string  type()  const = 0;
            virtual ~Container () {/* empty   body*/}
    };
}
#endif
