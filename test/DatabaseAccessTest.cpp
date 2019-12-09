#define BOOST_TEST_MODULE DatabaseAccessTest

#include "DatabaseAccess.h"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(DatabaseAccessSuite)

BOOST_AUTO_TEST_CASE(Test1)
{    
    BOOST_CHECK_EQUAL(DatabaseAccessLib::Test1(), 1);
}

BOOST_AUTO_TEST_CASE(Test2)
{    
    BOOST_CHECK_EQUAL(DatabaseAccessLib::Test2(), 2);
}


BOOST_AUTO_TEST_SUITE_END()