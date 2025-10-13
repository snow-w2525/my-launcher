#include "appfileio.h"
#include "appdefines.h"
#include "apputility.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#define FILE_FORMAT_VERSION                 "1.0.0"
#define APP_INFO_FILE                       "appinfo.json"
#define ERROR_APP_EXCEPTION                 "App raises exception error"
#define ERROR_COULD_NOT_READ_FILE           "Could not read file"
#define ERROR_FILE_FORMAT_INCORRECT         "File format is incorrect"

/* JSONファイルの識別子 */
#define JSON_IDENTIFIER_VERSION             "version"
#define JSON_IDENTIFIER_APP_INFO            "appinfo"
#define JSON_IDENTIFIER_APP_PATH            "path"
#define JSON_IDENTIFIER_APP_NAME            "name"
#define JSON_IDENTIFIER_APP_COLOR           "color"

AppFileIO::AppFileIO() {

}

/**
* @brief jsonファイルからアプリ情報を取得する
* @param app アプリ情報
* @param layout アプリパネルを貼るレイアウト
*/
bool AppFileIO::GetAppInfo(QVector<AppInfo> &applist) {
    try{
        // ファイルからデータを取得する
        QFile file(APP_INFO_FILE);
        if (!file.open(QIODevice::ReadOnly)) {
            throw QString(ERROR_COULD_NOT_READ_FILE);
        }
        QByteArray data = file.readAll();
        file.close();


        // JSONデータへのパース
        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
        if (parseError.error != QJsonParseError::NoError) {
            throw parseError.errorString();
        }

        if (!doc.isObject()) {
            throw QString(ERROR_FILE_FORMAT_INCORRECT);
        }

        QJsonObject obj = doc.object();
        if(FILE_FORMAT_VERSION != obj[JSON_IDENTIFIER_VERSION].toString()){
            throw QString(ERROR_FILE_FORMAT_INCORRECT);
        }

        QJsonArray arrayAppInfos = obj[JSON_IDENTIFIER_APP_INFO].toArray();

        for (const QJsonValue& value : arrayAppInfos) {
            QJsonObject obj = value.toObject();
            QString path = obj[JSON_IDENTIFIER_APP_PATH].toString();
            QString name = obj[JSON_IDENTIFIER_APP_NAME].toString();
        }

    }
    catch(QString& e){
        AppUtility::Instance().OutputLogInfo("AppFileIO::GetAppInfo", e);
        return false;
    }
    catch(...){
        AppUtility::Instance().OutputLogInfo("AppFileIO::GetAppInfo", ERROR_APP_EXCEPTION);
        return false;
    }

    return true;
}
