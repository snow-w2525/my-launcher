#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appdefiles.h"

class QVBoxLayout;

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

private:
    void SetAppPanel(AppInfo& app, QVBoxLayout* layout);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
