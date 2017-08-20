#include "MainProgram.h"

#include <StateProgram.h>
#include <StateMachine.h>

#include <iostream>

#include <LoraWANFactory.h>
#include <TDFSensorFactory.h>

#include <InitState.h>

class ProgramStateProgram : public StateProgram
{
  private:
    MainProgram *_program;

  public:
    ProgramStateProgram(MainProgram *program) : _program(program)
    {
    }

    void Init()
    {
        _program->Init();
    }

};

MainProgram::MainProgram()
{
    _program.reset(new ProgramStateProgram(this));
    _machine.reset(new StateMachine(_program.get()));
}
MainProgram::~MainProgram()
{
}

void MainProgram::Init()
{
    std::cout << "MainProgram.Init" << std::endl;

    _lora = LoraWANFactory::Create(LoraWANType::LMIC);
    _sensor = TDFSensorFactory::Create(TDFSensorType::Adafruit_GPS);
}

void MainProgram::Setup()
{
    _machine->ChangeState(new InitState());
}

void MainProgram::Loop()
{
    _machine->Handle();
}
