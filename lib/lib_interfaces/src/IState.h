#ifndef __STATEMACHINE_ISTATE_H__
#define __STATEMACHINE_ISTATE_H__

class IStateMachine;

#include "StateIDFwd.h"

class IState
{
protected:
  IState() {}

public:
  virtual ~IState() {}

  virtual void Handle(IStateMachine *m) = 0;

  virtual StateID GetStateID() const = 0;

  virtual void Enter(IStateMachine *m) = 0;
  virtual void Exit(IStateMachine *m) = 0;
};

#endif // __STATEMACHINE_ISTATE_H__
