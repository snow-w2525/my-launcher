#include "addappdialog.h"
#include "ui_addappdialog.h"

#include <QFileDialog>
#include <QColorDialog>

AddAppDialog::AddAppDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddAppDialog)
{
    ui->setupUi(this);
}

AddAppDialog::~AddAppDialog()
{
    delete ui;
}


void AddAppDialog::on_pushButton_appbrowse_clicked() {
    QFileDialog dialog(this);
    dialog.setOption(QFileDialog::DontUseNativeDialog, true);           // Qt独自ダイアログを使用

#if defined(Q_OS_WIN)
    dialog.setNameFilter("app(*.exe)");
#elif defined(Q_OS_MAC)

#endif
    if(QDialog::Accepted != dialog.exec()) return;

    ui->lineEdit_apppath->setText(dialog.selectedFiles().first());
}


void AddAppDialog::on_pushButton_filebrowse_clicked() {

}

/**
* @brief 色変更ダイアログを開く
* @param app アプリ情報
* @param layout アプリパネルを貼るレイアウト
*/
void AddAppDialog::on_pushButton_changecolor_clicked() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");

    if(color.isValid()){
        ui->frame_appcolor->setStyleSheet(QString("background-color: %1").arg(color.name()));
    }

}

void AddAppDialog::on_buttonBox_rejected() {
    this->close();
}

void AddAppDialog::on_buttonBox_accepted() {

}
