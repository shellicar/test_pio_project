#ifdef UNIT_TEST

#include "unity_fixture.hpp"

static void runAllTests(void)
{
    UnityFixture.Verbose = true;
    RUN_TEST_GROUP(EmbeddedFixture);
    //RUN_TEST_GROUP(StateMachineFixture);
}

#include <Arduino.h>

void setup()
{
    delay(5000);
    runAllTests();
}
void loop()
{

}

#endif // UNIT_TEST
