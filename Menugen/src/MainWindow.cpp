/*

              MainWindow Class
    
      This file is the implementation of the MainWindow 
      class methods. For more information look in the
      MainWindow.hpp file.

 */

#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "RecipesModel.hpp"


MainWindow::MainWindow(QWidget *parent)
    :
    QMainWindow(parent),
    d_ui(new Ui::MainWindow),
    d_recipes(this)
{
    d_ui->setupUi(this);

    d_ui->listView_Recipes->setModel(&d_recipes);

    connectSlots();
    d_recipes.debugAdd();
}

MainWindow::~MainWindow()
{
    delete d_ui;
}

void MainWindow::connectSlots()
{
    QObject::connect(d_ui->action_Quit, &QAction::triggered,
                     qApp,              &QApplication::quit);

    // View Model connections
    QObject::connect(d_recipes,              &QAbstractItemModel::dataChanged,
                     d_ui->listView_Recipes, &QAbstractItemView::update);
}
