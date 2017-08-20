#ifndef __STATEMACHINE_MOCKSTATEPROGRAM_H__
#define __STATEMACHINE_MOCKSTATEPROGRAM_H__

#include <IStateProgram.h>

class MockStateProgram : public IStateProgram
{
  private:
    bool _init;

  public:
    MockStateProgram() : _init(false){};
    virtual ~MockStateProgram() = default;

    bool IsInit() const
    {
        return _init;
    }
    void Init()
    {
        _init = true;
    }
};

#endif // __STATEMACHINE_MOCKSTATEPROGRAM_H__
