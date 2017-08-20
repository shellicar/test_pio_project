#ifndef __STATEMACHINE_MOCKSTATE_H__
#define __STATEMACHINE_MOCKSTATE_H__

#include <State.h>

class MockStateHolder;
class IStateMachine;

class MockState : public State
{
private:
  MockStateHolder *_parent;
  int _handleCount;
  StateID _stateID;

public:
  MockState(MockStateHolder *parent, StateID stateID);
  virtual ~MockState();

  StateID  GetStateID() const
  { return _stateID;}

  int HandleCount() const
  { return _handleCount;}

  virtual void Handle(IStateMachine *m)
  {
    ++_handleCount;
  }

  virtual void Enter(IStateMachine *m);
  virtual void Exit(IStateMachine *m);
};

#endif // __STATEMACHINE_MOCKSTATE_H__
