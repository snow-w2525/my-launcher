#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appdefiles.h"
#include "apppanel.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    /* windowの設定
     * ------------------------------------------------------------*/
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);


    /* アプリ情報の取得
     * ------------------------------------------------------------*/
    QWidget* container = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(container);
    for(AppInfo app: AppDefines::ALL){
        SetAppPanel(app, layout);
    }
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    ui->scrollArea_appmenu->setWidget(container);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetAppPanel(AppInfo& app, QVBoxLayout* layout) {
    layout->addWidget(new AppPanel(app));
}
