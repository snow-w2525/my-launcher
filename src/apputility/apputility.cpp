#include "apputility.h"
#define APP_NAME        "My Launcher"
#include <QString>
#include <QDebug>


/**
* @brief コンストラクタ
*/
AppUtility::AppUtility() {

}

/**
* @brief デストラクタ
*/
AppUtility::~AppUtility()
{

}

/**
* @brief インスタンス取得
*/
AppUtility &AppUtility::Instance() {
    static AppUtility instance;
    return instance;
}

/**
* @brief ログ情報を出力する
*/
void AppUtility::OutputLogInfo(QString method_name, QString message) {
    qDebug() << QString("[%1] %2:").arg(APP_NAME).arg(method_name) << message;
}
