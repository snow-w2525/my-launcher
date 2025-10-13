#include "apputility.h"
#define APP_NAME        "My Launcher"
#include <QString>
#include <QDebug>

AppUtility::AppUtility() {

}

AppUtility &AppUtility::Instance() {
    static AppUtility instance;
    return instance;
}

void AppUtility::OutputLogInfo(QString method_name, QString message) {
    qDebug() << QString("[%1] %2:").arg(APP_NAME).arg(method_name) << message;
}
