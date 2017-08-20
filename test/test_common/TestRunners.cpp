#include "unity_fixture.hpp"

TEST_GROUP_RUNNER(StateMachineFixture)
{
    RUN_TEST_CASE(StateMachineFixture, Given_StateMachine_When_ChangeStateToRawPointer_Then_IsEntered);
    RUN_TEST_CASE(StateMachineFixture, Given_StateMachine_When_ChangeState_Then_HasState);
    RUN_TEST_CASE(StateMachineFixture, Given_StateMachine_When_ChangeStateToRawPointer_Then_HasState);
    RUN_TEST_CASE(StateMachineFixture, Given_StateMachine_When_ChangeState_Then_State_IsEntered);
    RUN_TEST_CASE(StateMachineFixture, Given_NullUniquePtr_When_ChangeState_Then_ExpectInvalidArgumentException);
    RUN_TEST_CASE(StateMachineFixture, Given_NullRawPtr_When_ChangeState_Then_ExpectInvalidArgumentException);
    RUN_TEST_CASE(StateMachineFixture, Given_NonNullState_When_ChangeState_Then_StatesAreEqual);
    RUN_TEST_CASE(StateMachineFixture, Given_StateMachine_When_Destroyed_Then_StateIsDeleted);
    RUN_TEST_CASE(StateMachineFixture, Given_non_null_state_when_ChangeState_then_success);
    RUN_TEST_CASE(StateMachineFixture, Given_StateMachine_When_destroyed_Then_State_is_deleted);
}

TEST_GROUP_RUNNER(InitFixture)
{
    RUN_TEST_CASE(InitFixture, Given_InitState);
    RUN_TEST_CASE(InitFixture, Given_InitState_When_ChangeState_then_StateIsInitState);
    RUN_TEST_CASE(InitFixture, Given_InitState_When_Then_InitCalled);
    RUN_TEST_CASE(InitFixture, Given_InitState_When_Handle_Then_ChangedToJoinState);
}
