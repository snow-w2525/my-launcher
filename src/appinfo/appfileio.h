#ifndef APPFILEIO_H
#define APPFILEIO_H

#include <QVector>

class AppInfo;

class AppFileIO
{
public:
    AppFileIO();

private:
    bool GetAppInfo(QVector<AppInfo>& applist);
};

#endif // APPFILEIO_H
