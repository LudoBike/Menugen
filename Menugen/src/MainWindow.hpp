/*

              MainWindow Class
    
      This class provides to manage the all the app
      and to manage the window too.

 */

#ifndef __MAINWINDOW_HPP__
#define __MAINWINDOW_HPP__


#include <QMainWindow>
#include "RecipesModel.hpp"


namespace Ui
{
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Ui::MainWindow *d_ui;
    RecipesModel    d_recipes;
    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    void connectSlots();
};


#endif // __MAINWINDOW_HPP__
