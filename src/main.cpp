#include <iostream>
#include "configure.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <cmath>
#endif

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv){
    std::cout<<"Hello world! MajorVersion="<<ertb::VERSION_MAJOR<<" Minor="<<ertb::VERSION_MINOR<<std::endl;
    std::cout<<"Sqrt(4)="<<
#ifdef USE_MYMATH
    mysqrt(4)
#else
    std::sqrt(4)
#endif
    <<std::endl;
    return 0;
}