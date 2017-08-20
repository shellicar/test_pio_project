#ifndef __STATEMACHINE_STATEMACHINE_H__
#define __STATEMACHINE_STATEMACHINE_H__

#include "IStateMachine.h"
#include <memory>

class IState;

class StateMachine : public IStateMachine
{
protected:
  std::unique_ptr<IState> _state;
  IStateProgram *_program;

public:
  StateMachine(IStateProgram *program);
  virtual ~StateMachine();

  virtual IState *GetState();

  virtual IStateProgram *GetProgram()
  {
    return _program;
  }

  virtual void Handle();

  virtual void ChangeState(IState *state);
  virtual void ChangeState(std::unique_ptr<IState> state);
};

#endif // __STATEMACHINE_STATEMACHINE_H__
