#include "InitState.h"

#include <IStateMachine.h>
#include <IStateProgram.h>

#include "JoinState.h"

#include "StateID.h"

StateID InitState::GetStateID() const
{
    return StateID::Init;
}

void InitState::Enter(IStateMachine *m)
{
    if (!m)
        throw new std::invalid_argument("m");

    m->GetProgram()->Init();
}

void InitState::Handle(IStateMachine *m)
{
    if (!m)
        throw new std::invalid_argument("m");

    m->ChangeState(new JoinState());
}

void InitState::Exit(IStateMachine *m)
{
    if (!m)
        throw new std::invalid_argument("m");
}
