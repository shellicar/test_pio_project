#ifndef __PROGRAMSTATES_JOINSTATE_H__
#define __PROGRAMSTATES_JOINSTATE_H__

#include <State.h>

class JoinState : public State
{
public:
  virtual ~JoinState() = default;

  void Handle(IStateMachine *m);
  void Enter(IStateMachine *m);
  void Exit(IStateMachine *m);

  StateID GetStateID() const;
};

#endif // __PROGRAMSTATES_JOINSTATE_H__
