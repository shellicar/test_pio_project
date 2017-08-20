#ifdef UNIT_TEST
#include "unity_fixture.hpp"

#include <StateMachine.h>
#include <State.h>

#include "Mocks/MockState.h"
#include "Mocks/MockStateHolder.h"
#include "Mocks/MockStateProgram.h"

#include "unit_testing.h"

//#include <memory>
//#include <functional>

enum class StateID : int16_t
{
    Invalid = -1,

    Zero = 0,
    MockOne = 1
};

namespace
{
std::unique_ptr<MockStateHolder> _mock;
std::unique_ptr<IState> _state;
std::unique_ptr<IStateProgram> _program;
std::unique_ptr<IStateMachine> _machine;
}

TEST_GROUP(StateMachineFixture);

TEST_SETUP(StateMachineFixture)
{
    _mock.reset(new MockStateHolder(StateID::MockOne));
    _state.reset(_mock->GetState());
    _program.reset(new MockStateProgram());
    _machine.reset(new StateMachine(_program.get()));
}

TEST_TEAR_DOWN(StateMachineFixture)
{
    _machine.reset();
    _program.reset();
    _state.reset();
    _mock.reset();
}

TEST(StateMachineFixture, Given_StateMachine_When_ChangeState_Then_HasState)
{
    _machine->ChangeState(std::move(_state));

    TEST_ASSERT_EQUAL(_mock->GetState(), _machine->GetState());
}

TEST(StateMachineFixture, Given_StateMachine_When_ChangeStateToRawPointer_Then_IsEntered)
{
    _machine->ChangeState(_state.release());

    TEST_ASSERT_TRUE(_mock->IsEntered());
}

TEST(StateMachineFixture, Given_StateMachine_When_ChangeStateToRawPointer_Then_HasState)
{
    _machine->ChangeState(_state.release());

    TEST_ASSERT_EQUAL(_mock->GetState(), _machine->GetState());
}

TEST(StateMachineFixture, Given_StateMachine_When_ChangeState_Then_State_IsEntered)
{
    _machine->ChangeState(std::move(_state));

    TEST_ASSERT_TRUE(_mock->IsEntered());
}

TEST(StateMachineFixture, Given_NullUniquePtr_When_ChangeState_Then_ExpectInvalidArgumentException)
{
    // given null pointer
    _state.reset();

    auto with = []() { _machine->ChangeState(std::move(_state)); };

    TEST_ASSERT_THROWS_MESSAGE(std::invalid_argument, with, "state");
}

TEST(StateMachineFixture, Given_NullRawPtr_When_ChangeState_Then_ExpectInvalidArgumentException)
{
    auto with = []() {
        IState *empty = 0;
        _machine->ChangeState(empty);
    };

    TEST_ASSERT_THROWS_MESSAGE(std::invalid_argument, with, "state");
}

TEST(StateMachineFixture, Given_NonNullState_When_ChangeState_Then_StatesAreEqual)
{
    _machine->ChangeState(std::move(_state));

    TEST_ASSERT_EQUAL(_mock->GetState(), _machine->GetState());
}

TEST(StateMachineFixture, Given_StateMachine_When_Destroyed_Then_StateIsDeleted)
{
    _machine->ChangeState(std::move(_state));
    _machine.reset();
    TEST_ASSERT_TRUE(_mock->IsDeleted());
}

TEST(StateMachineFixture, Given_non_null_state_when_ChangeState_then_success)
{
    _machine->ChangeState(std::move(_state));

    TEST_ASSERT_EQUAL(_mock->GetState(), _machine->GetState());
}

TEST(StateMachineFixture, Given_StateMachine_When_destroyed_Then_State_is_deleted)
{
    _machine->ChangeState(std::move(_state));
    _machine.reset();

    TEST_ASSERT_TRUE(_mock->IsDeleted());
}

/*

enum class StateID : int16_t
{
    Invalid = -1,

    Zero = 0,
    MockOne = 1
};

std::unique_ptr<MockStateHolder> _mock;
std::unique_ptr<IState> _state;
std::unique_ptr<IStateProgram> _program;
std::unique_ptr<IStateMachine> _machine;

void setUp()
{
    _mock.reset(new MockStateHolder(StateID::MockOne));
    _state.reset(_mock->GetState());
    _program.reset(new MockStateProgram());
    _machine.reset(new StateMachine(_program.get()));    
}

void tearDown()
{
    _machine.reset();
    _program.reset();
    _state.reset();
    _mock.reset();
}

    void Given_StateMachine_When_ChangeState_Then_HasState()
    {
        _machine->ChangeState(std::move(_state));

        TEST_ASSERT_EQUAL(_mock->GetState(), _machine->GetState());
    }






void Given_StateMachine_When_ChangeStateToRawPointer_Then_IsEntered()
{
    _machine->ChangeState(_state.release());

    TEST_ASSERT_TRUE(_mock->IsEntered());
}

void Given_StateMachine_When_ChangeStateToRawPointer_Then_HasState()
{
    _machine->ChangeState(_state.release());

    TEST_ASSERT_EQUAL(_mock->GetState(), _machine->GetState());
}

void Given_StateMachine_When_ChangeState_Then_State_IsEntered()
{
    _machine->ChangeState(std::move(_state));

    TEST_ASSERT_TRUE(_mock->IsEntered());
}

void Given_NullUniquePtr_When_ChangeState_Then_ExpectInvalidArgumentException()
{
    // given null pointer
    _state.reset();

    auto with = []() { _machine->ChangeState(std::move(_state)); };

    TEST_ASSERT_THROWS_MESSAGE(std::invalid_argument, with, "state");
}

void Given_NullRawPtr_When_ChangeState_Then_ExpectInvalidArgumentException()
{
    auto with = []() {
        IState *empty = 0;
        _machine->ChangeState(empty);
    };

    TEST_ASSERT_THROWS_MESSAGE(std::invalid_argument, with, "state");
}

void Given_NonNullState_When_ChangeState_Then_StatesAreEqual()
{
    _machine->ChangeState(std::move(_state));

    TEST_ASSERT_EQUAL(_mock->GetState(), _machine->GetState());
}

void Given_StateMachine_When_Destroyed_Then_StateIsDeleted()
{
    _machine->ChangeState(std::move(_state));
    _machine.reset();
    TEST_ASSERT_TRUE(_mock->IsDeleted());
}

void Given_non_null_state_when_ChangeState_then_success()
{
    _machine->ChangeState(std::move(_state));

    TEST_ASSERT_EQUAL(_mock->GetState(), _machine->GetState());
}

void Given_StateMachine_When_destroyed_Then_State_is_deleted()
{
    _machine->ChangeState(std::move(_state));
    _machine.reset();

    TEST_ASSERT_TRUE(_mock->IsDeleted());
}



void StateMachineFixture::TestAll()
{
    UNITY_BEGIN();
    RUN_TEST(Given_StateMachine_When_ChangeStateToRawPointer_Then_IsEntered);
    RUN_TEST(Given_StateMachine_When_ChangeState_Then_HasState);
    RUN_TEST(Given_StateMachine_When_ChangeStateToRawPointer_Then_HasState);
    RUN_TEST(Given_StateMachine_When_ChangeState_Then_State_IsEntered);
    RUN_TEST(Given_NullUniquePtr_When_ChangeState_Then_ExpectInvalidArgumentException);
    RUN_TEST(Given_NullRawPtr_When_ChangeState_Then_ExpectInvalidArgumentException);
    RUN_TEST(Given_NonNullState_When_ChangeState_Then_StatesAreEqual);
    RUN_TEST(Given_StateMachine_When_Destroyed_Then_StateIsDeleted);
    RUN_TEST(Given_non_null_state_when_ChangeState_then_success);
    RUN_TEST(Given_StateMachine_When_destroyed_Then_State_is_deleted);
    UNITY_END();
}
*/

#endif
