#ifndef __STATEMACHINE_STATEPROGRAM_H__
#define __STATEMACHINE_STATEPROGRAM_H__

#include <IStateProgram.h>

class StateProgram : public IStateProgram
{
  protected:
    StateProgram() = default;

  public:
    virtual ~StateProgram() = default;
    
    virtual void Init() = 0;
};

#endif // __STATEMACHINE_STATEPROGRAM_H__
