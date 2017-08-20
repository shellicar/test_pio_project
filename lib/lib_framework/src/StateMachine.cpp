#include "StateMachine.h"
#include "State.h"

#include <exception>
#include <memory>

StateMachine::StateMachine(IStateProgram *program):_program(program){}
StateMachine::~StateMachine(){}

void StateMachine::ChangeState(IState *state)
{
#ifdef __EXCEPTIONS
    if (!state)
        throw std::invalid_argument("state");
#endif

    std::unique_ptr<IState> ptr(state);
    ChangeState(std::move(ptr));
}

void StateMachine::ChangeState(std::unique_ptr<IState> state)
{
#ifdef __EXCEPTIONS
    if (!state)
        throw std::invalid_argument("state");
#endif

    if (_state)
        _state->Exit(this);
    _state = std::move(state);
    if (_state)
        _state->Enter(this);
}

IState *StateMachine::GetState()
{
    return _state.get();
}

void StateMachine::Handle()
{
    if (!_state)
        throw std::runtime_error("state is empty");
    _state->Handle(this);
}