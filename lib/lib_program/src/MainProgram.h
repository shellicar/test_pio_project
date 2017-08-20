#ifndef __MAINPROGRAM_H__
#define __MAINPROGRAM_H__

#include <memory>

class IStateMachine;
class IStateProgram;
class ILoraWAN;
class ITDFSensor;

#include <StateProgram.h>

class MainProgram : public StateProgram
{
private:
    std::unique_ptr<IStateMachine> _machine;
    std::unique_ptr<IStateProgram> _program;
    std::unique_ptr<ILoraWAN> _lora;
    std::unique_ptr<ITDFSensor> _sensor;

public:
    MainProgram();
    ~MainProgram();

    // initial setup
    void Setup();
    // loop
    void Loop();

    // initialise
    virtual void Init();
};

#endif // __MAINPROGRAM_H__
