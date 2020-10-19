#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QPixmap>

#include "playwindow.h"
#include "ruleswindow.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

    static std::shared_ptr<MenuWindow> instance();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_developer_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MenuWindow *ui;

    friend class std::shared_ptr<MenuWindow>;
    static std::shared_ptr<MenuWindow> m_instance;
};

void MenuWindowDelFunc(MenuWindow *p);

#endif // MENUWINDOW_H
