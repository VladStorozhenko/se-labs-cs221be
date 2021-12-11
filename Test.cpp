#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "calculate.h"
BOOST_AUTO_TEST_CASE(myTestCase)
{
  BOOST_TEST(calculate(0,2)==46);//0*...+1*2*5+2*3*6=46 
}
