#include "apppanel.h"
#include "ui_apppanel.h"
#include "appdefiles.h"

#include <QIcon>
#include <QFile>
#include <QFileDialog>
#include <QProcess>
#include <QStringList>

AppPanel::AppPanel(AppInfo& app, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AppPanel)
{
    ui->setupUi(this);

    // スタイル設定
    ui->frame_apppanel->setStyleSheet(app._style);

    // アプリタイトル
    ui->label_apptitle->setText(app._appname);

    // 実行ボタン
    ui->pushButton_execapp->setIcon(QIcon(app._iconpath));
    ui->pushButton_execapp->setFlat(true);
    // 実体の存在確認
#ifdef Q_OS_WIN
    qDebug() << app._apppath;
    ui->pushButton_execapp->setEnabled(QFile::exists(app._apppath));
#elif Q_OS_MAC
#endif
    connect(ui->pushButton_execapp, &QPushButton::clicked, this, [=]() {
        if(ui->comboBox_filelist->currentText().isEmpty()){
            QProcess::startDetached(app._command);
        }
        else{
            QProcess::startDetached(app._command, QStringList() << ui->comboBox_filelist->currentText());
        }
    });

    // ファイル検索ボタン
    connect(ui->pushButton_filebrowse, &QPushButton::clicked, this, [=]() {
        QFileDialog dialog(this);
        dialog.setFileMode(QFileDialog::ExistingFiles);             // 複数ファイル選択を許可
        dialog.setOption(QFileDialog::ShowDirsOnly, false);         // フォルダも選択
        dialog.setOption(QFileDialog::DontUseNativeDialog, true);   // Qt独自ダイアログを使用
        QString exts;
        for(QString ext : app._exts){
            exts += ext + ";;";
        }
        dialog.setNameFilter(exts);

        if(!dialog.exec()) return;

        QStringList selected_paths = dialog.selectedFiles();
        for (const QString &path : selected_paths) {
            ui->comboBox_filelist->addItem(path);
        }
    });


}

AppPanel::~AppPanel()
{
    delete ui;
}
