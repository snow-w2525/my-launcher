#ifndef ADDAPPDIALOG_H
#define ADDAPPDIALOG_H

#include <QDialog>

namespace Ui {
class AddAppDialog;
}

class AddAppDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAppDialog(QWidget *parent = nullptr);
    ~AddAppDialog();

private slots:
    void on_pushButton_appbrowse_clicked();

    void on_pushButton_filebrowse_clicked();

    void on_pushButton_changecolor_clicked();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::AddAppDialog *ui;
};

#endif // ADDAPPDIALOG_H
