/*

              NewRecipeWindow Class
    
      This class provides to create a new recipe
      and to store it in the database

 */

#ifndef __NEWRECIPEWINDOW_HPP__
#define __NEWRECIPEWINDOW_HPP__


#include <QDialog>
#include <QSqlDatabase>


namespace Ui
{
    class NewRecipeWindow;
}


class NewRecipeWindow : public QDialog
{
    Ui::NewRecipeWindow       *d_ui;
    QSqlDatabase        const &d_db;
    
public:
    NewRecipeWindow(QSqlDatabase const &db = QSqlDatabase(), QWidget *parent = nullptr);
    virtual ~NewRecipeWindow();

public slots:
    virtual void accept();
};


#endif // __NEWRECIPEWINDOW_HPP__
