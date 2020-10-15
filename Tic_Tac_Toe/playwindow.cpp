#include "playwindow.h"
#include "ui_playwindow.h"

PlayWindow::PlayWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    move = 0;
    for(auto tmp_x = 0; tmp_x < Size_x; tmp_x++)
        for(auto tmp_y = 0; tmp_y < Size_y; tmp_y++)
            matrix[tmp_x][tmp_y] = 0;
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindowDelFunc(PlayWindow *p) { delete p;}

std::shared_ptr<PlayWindow> PlayWindow::m_instance;

std::shared_ptr<PlayWindow> PlayWindow::instance()
{
    if(!m_instance){
        m_instance.reset(new PlayWindow, PlayWindowDelFunc);
    }
    return m_instance;
}

void PlayWindow::on_pushButton_clicked()
{
    GamePlayerVSPlayer(ui->pushButton,0,0);
//    QPixmap pix(":/res/img/x.jpg");
//    int w = ui->pushButton->width();
//    int h = ui->pushButton->height();
//    ui->pushButton->setIconSize(QSize(w-6,h-6));
//    ui->pushButton->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
}

void PlayWindow::on_pushButton_2_clicked()
{
    GamePlayerVSPlayer(ui->pushButton_2,0,1);
//    QPixmap pix(":/res/img/x.jpg");
//    int w = ui->pushButton_2->width();
//    int h = ui->pushButton_2->height();
//    ui->pushButton_2->setIconSize(QSize(w-6,h-6));
//    ui->pushButton_2->setIcon(static_cast<QIcon>(pix.scaled(w,h)));

}

void PlayWindow::on_pushButton_3_clicked()
{
    GamePlayerVSPlayer(ui->pushButton_3,0,2);
//    QPixmap pix(":/res/img/x.jpg");
//    int w = ui->pushButton_3->width();
//    int h = ui->pushButton_3->height();
//    ui->pushButton_3->setIconSize(QSize(w-6,h-6));
//    ui->pushButton_3->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
}

void PlayWindow::on_pushButton_4_clicked()
{
    GamePlayerVSPlayer(ui->pushButton_4,1,0);
//    QPixmap pix(":/res/img/x.jpg");
//    int w = ui->pushButton_4->width();
//    int h = ui->pushButton_4->height();
//    ui->pushButton_4->setIconSize(QSize(w-6,h-6));
//    ui->pushButton_4->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
}

void PlayWindow::on_pushButton_5_clicked()
{
    GamePlayerVSPlayer(ui->pushButton_5,1,1);
//    QPixmap pix(":/res/img/o.jpg");
//    int w = ui->pushButton_5->width();
//    int h = ui->pushButton_5->height();
//    ui->pushButton_5->setIconSize(QSize(w-6,h-6));
//    ui->pushButton_5->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
}

void PlayWindow::on_pushButton_6_clicked()
{
    GamePlayerVSPlayer(ui->pushButton_6,1,2);
//    QPixmap pix(":/res/img/x.jpg");
//    int w = ui->pushButton_6->width();
//    int h = ui->pushButton_6->height();
//    ui->pushButton_6->setIconSize(QSize(w-6,h-6));
//    ui->pushButton_6->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
}

void PlayWindow::on_pushButton_7_clicked()
{
    GamePlayerVSPlayer(ui->pushButton_7,2,0);
//    QPixmap pix(":/res/img/x.jpg");
//    int w = ui->pushButton_7->width();
//    int h = ui->pushButton_7->height();
//    ui->pushButton_7->setIconSize(QSize(w-6,h-6));
//    ui->pushButton_7->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
}

void PlayWindow::on_pushButton_8_clicked()
{
    GamePlayerVSPlayer(ui->pushButton_8,2,1);
//    QPixmap pix(":/res/img/x.jpg");
//    int w = ui->pushButton_8->width();
//    int h = ui->pushButton_8->height();
//    ui->pushButton_8->setIconSize(QSize(w-6,h-6));
//    ui->pushButton_8->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
}

void PlayWindow::on_pushButton_9_clicked()
{
    GamePlayerVSPlayer(ui->pushButton_9,2,2);
//    QPixmap pix(":/res/img/x.jpg");
//    int w = ui->pushButton_9->width();
//    int h = ui->pushButton_9->height();
//    ui->pushButton_9->setIconSize(QSize(w-6,h-6));
//    ui->pushButton_9->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
}

void PlayWindow::GamePlayerVSPlayer(QPushButton *button, int x, int y)
{
    move++;
    if(move % 2 == 0 && move !=0)
    {
        QPixmap pix(":/res/img/o.jpg");
        int w = button->width();
        int h = button->height();
        button->setIconSize(QSize(w-6,h-6));
        button->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
        matrix[x][y] = 1;
    }
    else
    {
        QPixmap pix(":/res/img/x.jpg");
        int w = button->width();
        int h = button->height();
        button->setIconSize(QSize(w-6,h-6));
        button->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
        matrix [x][y] = 2;
    }
//    if((move == 9 || Roles()) || (move == 9 && Roles()))
    if(move == 9 || Roles() == true)
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Закончились ходы","Начать сначало",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            move = 0;
            ui->pushButton->setIcon(QIcon());
            ui->pushButton_2->setIcon(QIcon());
            ui->pushButton_3->setIcon(QIcon());
            ui->pushButton_4->setIcon(QIcon());
            ui->pushButton_5->setIcon(QIcon());
            ui->pushButton_6->setIcon(QIcon());
            ui->pushButton_7->setIcon(QIcon());
            ui->pushButton_8->setIcon(QIcon());
            ui->pushButton_9->setIcon(QIcon());
            for(auto tmp_x = 0; tmp_x < Size_x; tmp_x++)
                for(auto tmp_y = 0; tmp_y < Size_y; tmp_y++)
                    matrix[tmp_x][tmp_y] = 0;
        }
    }
}

bool PlayWindow::Roles()
{
    if(matrix[0][0] == matrix[0][1] == matrix[0][2])
        return true;
    else
        return false;

//    if((matrix[0][0] == matrix[0][1] == matrix[0][2]) ||
//            (matrix[1][0] == matrix[1][1] == matrix[1][2]) ||
//            (matrix[2][0] == matrix[2][1] == matrix[2][2]) ||
//            (matrix[0][0] == matrix[1][0] == matrix[2][0]) ||
//            (matrix[0][1] == matrix[1][1] == matrix[2][1]) ||
//            (matrix[0][2] == matrix[1][2] == matrix[2][2]) ||
//            (matrix[0][0] == matrix[1][1] == matrix[2][2]) ||
//            (matrix[0][2] == matrix[1][1] == matrix[2][0]))
//    {
//        return true;
//    }
//    else
//        return false;
}

