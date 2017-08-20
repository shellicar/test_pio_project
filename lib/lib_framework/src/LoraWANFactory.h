#ifndef __LIB_FRAMEWORK__LORAWANFACTORY_H__
#define __LIB_FRAMEWORK__LORAWANFACTORY_H__

enum class LoraWANType
{
    LMIC = 0,
};

class ILoraWAN;

class LoraWANFactory
{
private:
    LoraWANFactory() = default;
public:
    static std::unique_ptr<ILoraWAN> Create(LoraWANType type);
};

#endif // __LIB_FRAMEWORK__LORAWANFACTORY_H__
