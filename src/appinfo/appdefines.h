#ifndef APPDEFILES_H
#define APPDEFILES_H

#include <QString>
#include <QVector>

struct AppInfo {
    QString AppName;               // アプリ名
    QString AppPath;               // アプリの実体へのパス
    QString Command;               // アプリを起動するコマンド
    QString IconPath;              // アイコンのパス
    QString Style;                 // 背景色
    QVector<QString> Exts;         // 拡張子
};

namespace AppDefines {

    extern const QString DEACTIVATE_PANEL;

    extern const AppInfo EXCEL;
    extern const AppInfo WORD;
    extern const AppInfo POWERPOINT;
    extern const AppInfo VSCODE;

    extern const QVector<AppInfo> ALL;
}


#endif // APPDEFILES_H
