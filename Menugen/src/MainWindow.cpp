/*

              MainWindow Class
    
      This file is the implementation of the MainWindow 
      class methods. For more information look in the
      MainWindow.hpp file.

 */


#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    :
    QMainWindow(parent),
    d_ui(new Ui::MainWindow)
{
    d_ui->setupUi(this);

    connectSlots();
}

MainWindow::~MainWindow()
{
    delete d_ui;
}

void MainWindow::connectSlots()
{
    QObject::connect(d_ui->action_Quit, &QAction::triggered,
                     qApp,              &QApplication::quit);
}
