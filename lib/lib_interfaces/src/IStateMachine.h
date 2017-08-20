#ifndef __STATEMACHINE_ISTATEMACHINE_H__
#define __STATEMACHINE_ISTATEMACHINE_H__

class IState;

#include <memory>

class IStateProgram;

class IStateMachine
{
  protected:
    IStateMachine() = default;

  public:
    virtual ~IStateMachine() = default;

    virtual IStateProgram* GetProgram() = 0;

    virtual void Handle() = 0;

    virtual void ChangeState(IState *state) = 0;
    virtual void ChangeState(std::unique_ptr<IState> state) = 0;
    virtual IState *GetState() = 0;
};

#endif // __STATEMACHINE_ISTATEMACHINE_H__
