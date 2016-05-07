/*

              MainWindow Class
    
      This file is the implementation of the MainWindow 
      class methods. For more information look in the
      MainWindow.hpp file.

 */

#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    :
    QMainWindow(parent),
    d_ui(new Ui::MainWindow),
    d_recipesModel()
{
    d_ui->setupUi(this);
    d_ui->RecipesView->setModel(&d_recipesModel);
    
    setupDatabase();
    d_recipesModel.setQuery("SELECT name FROM recipes ORDER BY name ASC", d_db);
    
    connectSlots();

}

MainWindow::~MainWindow()
{
    delete d_ui;
}

void MainWindow::setupDatabase()
{
    d_db = QSqlDatabase::addDatabase("QSQLITE");
    d_db.setDatabaseName("database.db");
    if (!d_db.open())
    {
        QMessageBox mb(QMessageBox::Critical,
                       "Menugen Error",
                       "Fail to open database",
                       QMessageBox::Abort,
                       this);
        mb.exec();
    }

}

void MainWindow::connectSlots() const
{
    QObject::connect(d_ui->actionQuit, &QAction::triggered,
                     qApp,              &QApplication::quit);
}
