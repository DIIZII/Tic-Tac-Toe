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
            matrix[tmp_x][tmp_y] = -1;

    winZero = 0;
    winCross = 0;
    ui->labelZero->setText("0");
    ui->labelCross->setText("0");
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
    ui->pushButton->setEnabled(false);
    GamePlayerVSPlayer(ui->pushButton,0,0);
}

void PlayWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setEnabled(false);
    GamePlayerVSPlayer(ui->pushButton_2,0,1);
}

void PlayWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setEnabled(false);
    GamePlayerVSPlayer(ui->pushButton_3,0,2);
}

void PlayWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->setEnabled(false);
    GamePlayerVSPlayer(ui->pushButton_4,1,0);
}

void PlayWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setEnabled(false);
    GamePlayerVSPlayer(ui->pushButton_5,1,1);
}

void PlayWindow::on_pushButton_6_clicked()
{
    ui->pushButton_6->setEnabled(false);
    GamePlayerVSPlayer(ui->pushButton_6,1,2);
}

void PlayWindow::on_pushButton_7_clicked()
{
    ui->pushButton_7->setEnabled(false);
    GamePlayerVSPlayer(ui->pushButton_7,2,0);
}

void PlayWindow::on_pushButton_8_clicked()
{
    ui->pushButton_8->setEnabled(false);
    GamePlayerVSPlayer(ui->pushButton_8,2,1);
}

void PlayWindow::on_pushButton_9_clicked()
{
    ui->pushButton_9->setEnabled(false);
    GamePlayerVSPlayer(ui->pushButton_9,2,2);
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
        matrix[x][y] = 0;
    }
    else
    {
        QPixmap pix(":/res/img/x.jpg");
        int w = button->width();
        int h = button->height();
        button->setIconSize(QSize(w-6,h-6));
        button->setIcon(static_cast<QIcon>(pix.scaled(w,h)));
        matrix [x][y] = 1;
    }

    int result = -1;
    if(Roles(result) == true)
    {
        if(result == 1)
        {
            winCross++;
            QMessageBox::about(this,"Победа","Победили крестики. Счет"
                               + QString::number(winCross)
                               + ":"
                               + QString::number(winZero)
                               + "\nНовая партия");
            ui->labelCross->setText(QString::number(winCross));
        }
        else if(result == 0)
        {
            winZero++;
            QMessageBox::about(this,"Победа","Победили нолики. Счет"
                               + QString::number(winCross)
                               + ":"
                               + QString::number(winZero)
                               + "\nНовая партия");
            ui->labelZero->setText(QString::number(winZero));
        }
        else
        {
            //-1
        }
        NewGame();
    }

    if(move == 9)
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Закончились ходы","Ничья.))) \nНачать сначало",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            NewGame();
        }
    }
}

void PlayWindow::NewGame()
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
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    for(auto tmp_x = 0; tmp_x < Size_x; tmp_x++)
        for(auto tmp_y = 0; tmp_y < Size_y; tmp_y++)
            matrix[tmp_x][tmp_y] = -1;
}

bool PlayWindow::Roles(int &number)
{

    if((matrix[0][0] == 0 && matrix[0][1] == 0 && matrix[0][2] == 0)
            || (matrix[1][0] == 0 && matrix[1][1] == 0 && matrix[1][2] == 0)
            || (matrix[2][0] == 0 && matrix[2][1] == 0 && matrix[2][2] == 0)
            || (matrix[0][0] == 0 && matrix[1][0] == 0 && matrix[2][0] == 0)
            || (matrix[0][1] == 0 && matrix[1][1] == 0 && matrix[2][1] == 0)
            || (matrix[0][2] == 0 && matrix[1][2] == 0 && matrix[2][2] == 0)
            || (matrix[0][0] == 0 && matrix[1][1] == 0 && matrix[2][2] == 0)
            || (matrix[0][2] == 0 && matrix[1][1] == 0 && matrix[2][0] == 0))
    {
        number = 0;
        return true;
    }
    else if((matrix[0][0] == 1 && matrix[0][1] == 1 && matrix[0][2] == 1)
            || (matrix[1][0] == 1 && matrix[1][1] == 1 && matrix[1][2] == 1)
            || (matrix[2][0] == 1 && matrix[2][1] == 1 && matrix[2][2] == 1)
            || (matrix[0][0] == 1 && matrix[1][0] == 1 && matrix[2][0] == 1)
            || (matrix[0][1] == 1 && matrix[1][1] == 1 && matrix[2][1] == 1)
            || (matrix[0][2] == 1 && matrix[1][2] == 1 && matrix[2][2] == 1)
            || (matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1)
            || (matrix[0][2] == 1 && matrix[1][1] == 1 && matrix[2][0] == 1))
    {
        number = 1;
        return true;
    }
    else
        return false;
}


void PlayWindow::on_pushButton_back_clicked()
{
    MenuWindow::instance()->show();
    this->close();
}

void PlayWindow::on_pushButto_clear_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Очистить","Начать сначало?",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        NewGame();
    }
}
