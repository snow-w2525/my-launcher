#include "apppanel.h"
#include "ui_apppanel.h"
#include "appdefines.h"

#include <QIcon>
#include <QFile>
#include <QFileDialog>
#include <QProcess>
#include <QStringList>
#include <utility>

AppPanel::AppPanel(AppInfo& app, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AppPanel)
{
    ui->setupUi(this);

    /* スタイルの設定
     * ------------------------------------------------------------*/
    ui->frame_apppanel->setStyleSheet(app.Style);


    /* タイトル
     * ------------------------------------------------------------*/
    ui->label_apptitle->setText(app.AppName);


    /* 実行ボタン
     * ------------------------------------------------------------*/
    ui->pushButton_execapp->setIcon(QIcon(app.IconPath));
    ui->pushButton_execapp->setFlat(true);
    ui->pushButton_execapp->setStyleSheet("QPushButton{background-color: white; border-radius: 10px}");

    connect(ui->pushButton_execapp, &QPushButton::clicked, this, [=]() {    // ボタンを押した時の処理
#if defined(Q_OS_WIN)
        if(ui->comboBox_filelist->currentText().isEmpty()){
            QProcess::startDetached(app._command);
        }
        else{
            QProcess::startDetached(app._command, QStringList() << ui->comboBox_filelist->currentText());
        }
#elif defined(Q_OS_MAC)
        if(ui->comboBox_filelist->currentText().isEmpty()){
            QProcess::startDetached("open", {"-a", app.Command});
        }
        else{
            QProcess::startDetached("open", {"-a", app.Command, ui->comboBox_filelist->currentText()});
        }
#endif
    });


    /* ファイル検索ボタン
     * ------------------------------------------------------------*/
    connect(ui->pushButton_filebrowse, &QPushButton::clicked, this, [=]() {
        QFileDialog dialog(this);
        dialog.setFileMode(QFileDialog::ExistingFiles);                     // 複数ファイル選択を許可
        dialog.setOption(QFileDialog::ShowDirsOnly, false);                 // フォルダも選択
        dialog.setOption(QFileDialog::DontUseNativeDialog, true);           // Qt独自ダイアログを使用
        QString exts;
        for(const QString& ext : app.Exts){
            exts += ext + ";;";
        }
        dialog.setNameFilter(exts);

        if(!dialog.exec()) return;

        QStringList selected_paths = dialog.selectedFiles();
        for (const QString &path : std::as_const(selected_paths)) {
            ui->comboBox_filelist->addItem(path);
        }
    });


    /* 実体がない場合はパネルを非活性にする
     * ------------------------------------------------------------*/
    if(!QFile::exists(app.AppPath)){
        ui->frame_apppanel->setStyleSheet(AppDefines::DEACTIVATE_PANEL);
        ui->pushButton_execapp->setEnabled(false);
    }

}

AppPanel::~AppPanel()
{
    delete ui;
}
