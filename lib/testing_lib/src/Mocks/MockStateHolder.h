#ifndef __STATEMACHINE_MOCKSTATEHOLDER_H__
#define __STATEMACHINE_MOCKSTATEHOLDER_H__

#include <cstdint>

class IState;

#include "StateIDFwd.h"

class MockStateHolder
{
private:
  IState *_state;
  bool _isDeleted;
  bool _isEntered;
  bool _isExited;
  StateID _stateID;

public:
  MockStateHolder(StateID stateID);

  IState *GetState();

  bool IsDeleted() const { return _isDeleted; }
  bool IsEntered() const { return _isEntered; }
  bool IsExited() const { return _isExited; }

  void OnDelete();
  void OnEnter();
  void OnExit();
};

#endif // __STATEMACHINE_MOCKSTATEHOLDER_H__
