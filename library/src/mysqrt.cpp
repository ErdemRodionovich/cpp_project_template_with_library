#include <iostream>

#if defined(HAVE_LOG) && defined(HAVE_EXP)
#include <cmath>
#endif

#include "Table.h"

// a hack square root calculation using simple operations
double mysqrt(double x)
{
  if (x <= 0) {
    return 0;
  }

  double result = x;

  if(x >= 1 && x < 10){
       std::cout<<"Use table to calculate sqrt "<<std::endl;
       result = sqrtTable[static_cast<int>(x)];
       return result;
  }

  // do ten iterations
#if defined(HAVE_LOG) && defined(HAVE_EXP)
  result = std::exp(std::log(x) * 0.5);
  std::cout << "Computing sqrt of " << x << " to be " << result
            << " using log and exp" << std::endl;
#else
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
    std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
  }
#endif
  return result;
}
