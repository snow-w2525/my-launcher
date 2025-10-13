#ifndef APPUTILITY_H
#define APPUTILITY_H

class QString;

class AppUtility
{
public:
    static AppUtility& Instance();
    void OutputLogInfo(QString method_name, QString message);

private:
    AppUtility();
    ~AppUtility();
    AppUtility(const AppUtility&) = delete;
    AppUtility& operator=(const AppUtility&) = delete;
};

#endif // APPUTILITY_H
