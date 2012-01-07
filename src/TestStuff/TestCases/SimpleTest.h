//SimpleTest.h

#ifndef __SIMPLETEST_H
#define __SIMPLETEST_H

#include <cxxtest/TestSuite.h>

//
// A simple test suite: Just inherit CxxTest::TestSuite and write tests!
//

class SimpleTest : public CxxTest::TestSuite
{
public:
    void testEquality()
    {
        TS_ASSERT_EQUALS( 1, 1 );
        
    }

    
};


#endif // __SIMPLETEST_H
