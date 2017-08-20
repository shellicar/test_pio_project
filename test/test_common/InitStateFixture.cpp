#ifdef UNIT_TEST

#include "unity_fixture.hpp"

#include <memory>

#include <InitState.h>
#include "Mocks/MockStateProgram.h"
#include <StateMachine.h>

#include "StateID.h"

namespace {
  std::unique_ptr<IState> _init;
  std::unique_ptr<MockStateProgram> _program;
  std::unique_ptr<IStateMachine> _machine;
}

TEST_GROUP(InitFixture);

TEST_SETUP(InitFixture)
{
  _init.reset(new InitState());
  _program.reset(new MockStateProgram());
  _machine.reset(new StateMachine(_program.get()));
}

TEST_TEAR_DOWN(InitFixture)
{
  _machine.reset();
  _program.reset();
  _init.reset();
}

TEST(InitFixture, Given_InitState)
{
  TEST_PASS();
}

TEST(InitFixture, Given_InitState_When_ChangeState_then_StateIsInitState)
{
  TEST_PASS();
  _machine->ChangeState(_init.release());
  TEST_ASSERT_EQUAL(StateID::Init, _machine->GetState()->GetStateID());
}

// can ChangeState to InitState
TEST(InitFixture, Given_InitState_When_Then_InitCalled)
{
  _machine->ChangeState(_init.release());
  TEST_ASSERT_TRUE(_program->IsInit())
}

TEST(InitFixture, Given_InitState_When_Handle_Then_ChangedToJoinState)
{
  // given
  _machine->ChangeState(_init.release());

  // when
  _machine->Handle();

  // then
  auto state = _machine->GetState();
  TEST_ASSERT_EQUAL(StateID::Join, state->GetStateID());
}

/*
#include ".\test_InitState.h"

#include <unity.h>
#include "../test/test_common/unit_testing.h"

#include <InitState.h>
#include <JoinState.h>
#include <StateMachine.h>
#include "../Mocks/MockStateProgram.h"

#include "StateID.h"



*/

/*
void setUp()
{

}

InitStateFixture::~InitStateFixture()
{
  _machine.reset();
  _program.reset();
  _init.reset();
}

InitStateFixture::InitStateFixture()
{
  _init.reset(new InitState());
  _program.reset(new MockStateProgram());
  _machine.reset(new StateMachine(_program.get()));
}

// can create InitState
class Given_InitState : public InitStateFixture
{
public:
  void Test()
  {
    TEST_PASS();
  }
};

class Given_InitState_When_ChangeState_then_StateIsInitState : public InitStateFixture
{
public:
  void Test()
  {
    _machine->ChangeState(_init.release());
    TEST_ASSERT_EQUAL(StateID::Init, _machine->GetState()->GetStateID());
  }
};

// can ChangeState to InitState
class Given_InitState_When_Then_InitCalled : public InitStateFixture
{
public:
  void Test()
  {
    _machine->ChangeState(_init.release());
    TEST_ASSERT_TRUE(_program->IsInit())
  }
};

class Given_InitState_When_Handle_Then_ChangedToJoinState : public InitStateFixture
{
public:
  void Setup()
  {
    _machine->ChangeState(_init.release());
  }

  void Test()
  {
    _machine->Handle();

    auto state = _machine->GetState();
    TEST_ASSERT_EQUAL(StateID::Join, state->GetStateID());
  }
};

void InitStateFixture::TestAll()
{
  UNITY_BEGIN();
  RUN_TEST_CLASS(Given_InitState);
  RUN_TEST_CLASS(Given_InitState_When_ChangeState_then_StateIsInitState);
  RUN_TEST_CLASS(Given_InitState_When_Then_InitCalled);
  RUN_TEST_CLASS(Given_InitState_When_Handle_Then_ChangedToJoinState);
  UNITY_END();
}

*/

#endif
