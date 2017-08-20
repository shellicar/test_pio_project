#ifndef __PROGRAMSTATES_INITSTATE_H__
#define __PROGRAMSTATES_INITSTATE_H__

#include <State.h>

class InitState : public State
{
public:
  virtual ~InitState() = default;

  void Handle(IStateMachine *m);
  void Enter(IStateMachine *m);
  void Exit(IStateMachine *m);

  StateID GetStateID() const;
};

#endif // __PROGRAMSTATES_INITSTATE_H__
