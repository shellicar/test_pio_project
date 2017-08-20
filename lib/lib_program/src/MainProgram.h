#ifndef __MAINPROGRAM_H__
#define __MAINPROGRAM_H__

#include <memory>

class IStateProgram;
class IStateMachine;

class MainProgram
{
private:
    std::unique_ptr<IStateProgram> _program;
    std::unique_ptr<IStateMachine> _machine;

public:
    MainProgram();
    ~MainProgram();

    void Init();
    void Tick();
};

#endif // __MAINPROGRAM_H__
