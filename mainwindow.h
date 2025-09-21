#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appdefiles.h"

#include <QHash>

class QVBoxLayout;
class AppPanel;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_browse_textChanged(const QString &arg1);

private:
    void SetAppPanel(AppInfo& app, QVBoxLayout* layout);

private:
    Ui::MainWindow *ui;
    QHash<QString, AppPanel*> _panellist;
};
#endif // MAINWINDOW_H
