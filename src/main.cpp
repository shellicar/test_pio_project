#ifdef UNIT_TEST
#include "unity_fixture.hpp"
#else

// need to include one file per library for dependencies

#include <MainProgram.h>



/*
#include <IState.h>
#include <StateProgram.h>
#include <unit_testing.h>
*/

MainProgram program;

#include <Arduino.h>

void setup(void)
{
    program.Setup();
}

void loop(void)
{
    program.Loop();
}

#endif
