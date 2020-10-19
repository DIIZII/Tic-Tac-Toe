#include "ruleswindow.h"
#include "ui_ruleswindow.h"

RulesWindow::RulesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RulesWindow)
{
    ui->setupUi(this);

    QPixmap pix1(":/res/img/algoritm-kak-vyigrat-v-krestiki-noliki.png");
    int w = ui->label->width() * 10;
    int h = ui->label->height() * 10;

    ui->label->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
}

RulesWindow::~RulesWindow()
{
    delete ui;
}

void RulesWindowDelFunc(RulesWindow * p) { delete p;}

std::shared_ptr<RulesWindow> RulesWindow::m_instance;

std::shared_ptr<RulesWindow> RulesWindow::instance()
{
    if(!m_instance){
        m_instance.reset(new RulesWindow, RulesWindowDelFunc);
    }
    return m_instance;
}

void RulesWindow::on_pushButton_back_clicked()
{
    MenuWindow::instance()->show();
    this->close();
}
