#include ".\MockState.h"
#include ".\MockStateHolder.h"

MockState::MockState(MockStateHolder *parent, StateID id) : _parent(parent), _handleCount(0), _stateID(id)
{
}

MockState::~MockState()
{
    if (_parent)
        _parent->OnDelete();
}

void MockState::Enter(IStateMachine *m)
{
    if (_parent)
        _parent->OnEnter();
}

void MockState::Exit(IStateMachine *m)
{
    if (_parent)
        _parent->OnExit();
}
