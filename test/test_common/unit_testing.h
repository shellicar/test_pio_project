#ifndef __UNIT_TESTING_H__
#define __UNIT_TESTING_H__

#ifdef UNIT_TEST

#include <functional>
#include <cstring>
#include "unity_fixture.hpp"

template <typename Ty>
void __test_assert_throws(std::function<void()> arg, const char *what = 0)
{
    try
    {
        arg();
    }
    catch (const Ty &e)
    {
        if (!what || strcmpi(e.what(), what) == 0)
            TEST_PASS();
    }
    TEST_FAIL();
}


#define TEST_ASSERT_THROWS(ex, func) __test_assert_throws<ex>(func)
#define TEST_ASSERT_THROWS_MESSAGE(ex, func, what) __test_assert_throws<ex>(func, what)



/*
#include "TestFixture.h"

#define RUN_TEST_CLASS(x) RUN_TEST([]() { x().RunTest(); })



#include <cstring>

#include <unity.h>


*/
#endif // UNIT_TEST

#endif // __UNIT_TESTING_H__
