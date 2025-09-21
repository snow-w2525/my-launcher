#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appdefiles.h"
#include "apppanel.h"

#include <QVBoxLayout>
#include <utility>

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
    AppPanel* panel = new AppPanel(app);
    layout->addWidget(panel);
    _panellist[app._appname] = panel;
}

void MainWindow::on_lineEdit_browse_textChanged(const QString &arg1) {

    // 文字が入っていなければ、すべてのパネルを表示して終了
    if(arg1.isEmpty()){
        for(const auto& panel : std::as_const(_panellist)){
            panel->setVisible(true);
        }
        return;
    }
    else{
        // 大文字を小文字に変換
        QString keyword = arg1.toLower();

        // 一度すべてのパネルを非表示にする
        for(const auto panel : std::as_const(_panellist)){
            panel->setVisible(false);
        }
        // 検索に合致したものだけを表示
        for (auto it = _panellist.constBegin(); it != _panellist.constEnd(); ++it) {
            if (it.key().toLower().contains(keyword)) {
                _panellist[it.key()]->setVisible(true);
            }
        }
    }
}
