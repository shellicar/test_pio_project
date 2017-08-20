#include ".\MockStateHolder.h"
#include ".\MockState.h"

MockStateHolder::MockStateHolder(StateID id) : _state(0),
                                     _isDeleted(false),
                                     _isEntered(false),
                                     _isExited(false),
                                     _stateID(id)
{
}

IState *MockStateHolder::GetState()
{
    if (_state == 0)
        _state = new MockState(this, _stateID);
    return _state;
}

void MockStateHolder::OnDelete()
{
    _isDeleted = true;
}

void MockStateHolder::OnEnter()
{
    _isEntered = true;
}

void MockStateHolder::OnExit()
{
    _isExited = true;
}
