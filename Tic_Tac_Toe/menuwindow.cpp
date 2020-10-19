#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);

    QPixmap pix1(":/res/img/image.png");
    int w = ui->labelImage->width() * 10;
    int h = ui->labelImage->height() * 10;

    ui->labelImage->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindowDelFunc(MenuWindow * p) { delete p;}

std::shared_ptr<MenuWindow> MenuWindow::m_instance;

std::shared_ptr<MenuWindow> MenuWindow::instance()
{
    if(!m_instance){
        m_instance.reset(new MenuWindow, MenuWindowDelFunc);
    }
    return m_instance;
}

void MenuWindow::on_pushButton_2_clicked()
{
    this->close();
    PlayWindow::instance()->show();
}

void MenuWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Выход","Вы уверены?",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        this->close();
    }
}

void MenuWindow::on_pushButton_developer_clicked()
{
    QMessageBox::about(this,"Разработчик","DIIZII");
}

void MenuWindow::on_pushButton_3_clicked()
{
    RulesWindow::instance()->show();
    this->close();
}
