#ifdef UNIT_TEST

#include "unity_fixture.hpp"

static void runAllTests(void)
{
    UnityFixture.Verbose = true;
    RUN_TEST_GROUP(InitFixture);
    RUN_TEST_GROUP(StateMachineFixture);
}

#ifdef ARDUINO

#include <Arduino.h>

void setup()
{
    delay(5000);
    runAllTests();
}
void loop()
{

}

#else

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}
#endif // ARDUINO

#endif // UNIT_TEST
