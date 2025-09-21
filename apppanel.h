#ifndef APPPANEL_H
#define APPPANEL_H

#include <QWidget>

struct AppInfo;

namespace Ui {
class AppPanel;
}

class AppPanel : public QWidget
{
    Q_OBJECT

public:
    explicit AppPanel(AppInfo& app, QWidget *parent = nullptr);
    ~AppPanel();

private:
    Ui::AppPanel *ui;
};

#endif // APPPANEL_H
