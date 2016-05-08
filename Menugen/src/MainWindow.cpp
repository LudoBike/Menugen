/*

              MainWindow Class
    
      This file is the implementation of the MainWindow 
      class methods. For more information look in the
      MainWindow.hpp file.

 */

#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "NewRecipeWindow.hpp"
#include <QMessageBox>
#include <QDebug>


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

void MainWindow::newRecipe()
{
    NewRecipeWindow w(d_db, this);
    w.exec();
    QSqlQuery tmp = d_recipesModel.query();
    d_recipesModel.clear();
    d_recipesModel.setQuery(tmp.executedQuery());
}

void MainWindow::setupDatabase()
{
    d_db = QSqlDatabase::addDatabase("QSQLITE");
    d_db.setDatabaseName("database.db");
    if (!d_db.open())
    {
        QMessageBox mb(QMessageBox::Critical,
                       tr("Menugen Erreur"),
                       tr("Impossible d'ouvrir la base de donnée"),
                       QMessageBox::Abort,
                       this);
        mb.exec();
    }

    QSqlQuery query(d_db);
    if (!d_db.tables().contains("recipes"))
        query.exec("CREATE TABLE recipes(id INTEGER PRIMARY KEY, name TEXT)");

    if(!d_db.tables().contains("menus"))
        query.exec(QString("CREATE TABLE menus(id INTEGER, mon INTEGER,") +
                   QString("tue INTEGER, wed INTEGER, thu INTEGER,") +
                   QString("fri INTEGER, sat INTEGER, sun INTEGER)"));
}

void MainWindow::connectSlots() const
{
    QObject::connect(d_ui->actionQuit,  &QAction::triggered,
                     qApp,              &QApplication::quit);

    QObject::connect(d_ui->actionNewRecipe, &QAction::triggered,
                     this,                  &MainWindow::newRecipe);
}
