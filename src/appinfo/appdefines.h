#ifndef APPDEFILES_H
#define APPDEFILES_H

#include <QString>
#include <QVector>

struct AppInfo {
    QString appname;               // アプリ名
    QString apppath;               // アプリの実体へのパス
    QString command;               // アプリを起動するコマンド
    QString iconpath;              // アイコンのパス
    QString style;                 // 背景色
    QVector<QString> exts;         // 拡張子
    bool isdefaultapp;             // デフォルトで表示させる
    bool isneedfile;               // ファイルの要不要
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
