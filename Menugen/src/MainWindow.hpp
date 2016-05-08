/*

              MainWindow Class
    
      This class provides to manage the all the app
      and the other windows too.

 */

#ifndef __MAINWINDOW_HPP__
#define __MAINWINDOW_HPP__


#include <QMainWindow>
#include <QtSql>
#include <QStringListModel>


namespace Ui
{
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Ui::MainWindow *d_ui;
    QSqlDatabase    d_db;
    QSqlQueryModel  d_recipesModel;
    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

public slots:
    void newRecipe();

private:
    void setupDatabase();
    void connectSlots() const;
};


#endif // __MAINWINDOW_HPP__
