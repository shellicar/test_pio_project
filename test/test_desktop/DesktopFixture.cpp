#ifdef UNIT_TEST

#include "unity_fixture.hpp"

TEST_GROUP(DesktopFixture);

#include <memory>

#include <MainProgram.h>
#include <StateMachine.h>

namespace
{
std::unique_ptr<MainProgram> program;
}

TEST_SETUP(DesktopFixture)
{
  program.reset(new MainProgram());
}

TEST_TEAR_DOWN(DesktopFixture)
{
  program.reset();
}

TEST(DesktopFixture, Given)
{
  TEST_PASS();
}

#endif
