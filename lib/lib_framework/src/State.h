#ifndef __STATEMACHINE_STATE_H__
#define __STATEMACHINE_STATE_H__

#include "IState.h"

class IStateMachine;

class State : public IState
{
protected:
  State() = default;

public:
  virtual ~State() = default;

  virtual void Handle(IStateMachine *m) = 0;

  virtual StateID GetStateID() const = 0;

  virtual void Enter(IStateMachine *m) = 0;
  virtual void Exit(IStateMachine *m) = 0;
};

#endif // __STATEMACHINE_STATE_H__
