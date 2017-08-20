#ifndef __LIB_FRAMEWORK__TDFSENSORFACTORY_H__
#define __LIB_FRAMEWORK__TDFSENSORFACTORY_H__

enum class TDFSensorType
{
    Adafruit_GPS = 0,
};

class ITDFSensor;

class TDFSensorFactory
{
private:
    TDFSensorFactory() = default;
public:
    static std::unique_ptr<ITDFSensor> Create(TDFSensorType type);
};

#endif // __LIB_FRAMEWORK__LORAWANFACTORY_H__
