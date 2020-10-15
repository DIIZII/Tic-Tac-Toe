#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = nullptr);
    ~PlayWindow();

     static std::shared_ptr<PlayWindow> instance();

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_6_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_8_clicked();

     void on_pushButton_9_clicked();

private:
    Ui::PlayWindow *ui;

    friend class std::shared_ptr<PlayWindow>;
    static std::shared_ptr<PlayWindow> m_instance;

    int move;
    const static int Size_x = 3;
    const static int Size_y = 3;
    int matrix [Size_x][Size_y];
//    std::shared_ptr<std::shared_ptr<int>> matrix;

    void GamePlayerVSPlayer(QPushButton *button, int x, int y);

    bool Roles();

};

void PlayWindowDelFunc(PlayWindow *p);

#endif // PLAYWINDOW_H
