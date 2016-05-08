/*

              NewRecipeWindow Class
    
      This file is the implementation of the NewRecipeWindow
      class methods. For more information look in the
      NewRecipeWindow.hpp file.

 */

#include "NewRecipeWindow.hpp"
#include "ui_NewRecipeWindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


NewRecipeWindow::NewRecipeWindow(QSqlDatabase const &db, QWidget *parent)
    :
    QDialog(parent),
    d_ui(new Ui::NewRecipeWindow),
    d_db(db)
{
    d_ui->setupUi(this);
}

NewRecipeWindow::~NewRecipeWindow()
{
    delete d_ui;
}

void NewRecipeWindow::accept()
{
    QString name(d_ui->lineEditName->text());
    if (name.isEmpty())
        return;
    
    QSqlQuery query(d_db);
    query.exec(QString("INSERT INTO recipes(name) VALUES ('%1')").arg(name));
    if (query.lastError().type() != QSqlError::NoError)
        qDebug() << query.lastError().text();
    
    QDialog::accept();
}
