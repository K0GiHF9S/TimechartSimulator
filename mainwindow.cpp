#include <QMetaObject>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "starter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_toggled(bool checked)
{
    if(checked)
    {
        if(starter == nullptr)
        {
            starter = new Starter();
            starter->wake();
        }
    }
    else
    {
        if(starter != nullptr)
        {
            starter->stop();
            delete starter;
            starter = nullptr;
        }
    }
}
