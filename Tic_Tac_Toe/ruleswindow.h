#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QWidget>

#include "menuwindow.h"

namespace Ui {
class RulesWindow;
}

class RulesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RulesWindow(QWidget *parent = nullptr);
    ~RulesWindow();

    static std::shared_ptr<RulesWindow> instance();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::RulesWindow *ui;

    friend class std::shared_ptr<RulesWindow>;
    static std::shared_ptr<RulesWindow> m_instance;

};

void RulesWindowDelFunc(RulesWindow *p);

#endif // RULESWINDOW_H
