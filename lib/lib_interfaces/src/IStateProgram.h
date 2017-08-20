#ifndef __STATEMACHINE_ISTATEPROGRAM_H__
#define __STATEMACHINE_ISTATEPROGRAM_H__

class IStateProgram
{
  protected:
    IStateProgram() = default;

  public:
    virtual ~IStateProgram() = default;

    virtual void Init() = 0;
};

#endif // __STATEMACHINE_ISTATEPROGRAM_H__
