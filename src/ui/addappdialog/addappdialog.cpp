#include "addappdialog.h"
#include "ui_addappdialog.h"

#include <QFileDialog>

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
    dialog.setNameFilter("app(*.exe)");

    if(QDialog::Accepted != dialog.exec()) return;

    ui->lineEdit_apppath->setText(dialog.selectedFiles().first());
}
