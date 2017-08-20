#ifdef UNIT_TEST

#include "unity_fixture.hpp"

static void runAllTests(void)
{
    UnityFixture.Verbose = true;
    RUN_TEST_GROUP(DesktopFixture);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}

#endif // UNIT_TEST
