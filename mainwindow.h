#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Starter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Starter *starter = nullptr;
};

#endif // MAINWINDOW_H
