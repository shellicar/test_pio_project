#include "JoinState.h"
#include "StateID.h"

StateID JoinState::GetStateID() const
{
    return StateID::Join;
}

void JoinState::Enter(IStateMachine *m)
{
}

void JoinState::Exit(IStateMachine *m)
{
}

void JoinState::Handle(IStateMachine *m)
{
}
