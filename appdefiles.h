#ifndef APPDEFILES_H
#define APPDEFILES_H

#include <QString>
#include <QVector>

struct AppInfo {
    QString _appname;               // アプリ名
    QString _apppath;               // アプリの実体へのパス
    QString _command;               // アプリを起動するコマンド
    QString _iconpath;              // アイコンのパス
    QString _style;                 // 背景色
    QVector<QString> _exts;         // 拡張子
};

namespace AppDefines {

    extern const AppInfo EXCEL;
    extern const AppInfo WORD;
    extern const AppInfo POWERPOINT;
    extern const AppInfo VSCODE;

    extern const QVector<AppInfo> ALL;
}


#endif // APPDEFILES_H
