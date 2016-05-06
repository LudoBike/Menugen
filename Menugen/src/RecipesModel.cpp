/*

              RecipesModel Class
    
      This file is the implementation of the RecipesModel 
      class methods. For more information look in the
      RecipesModel.hpp file.

 */

#include "RecipesModel.hpp"


RecipesModel::RecipesModel(QObject *parent)
    :
    QStringListModel(parent),
    d_names()
{
    d_names += "Lol";
    setStringList(d_names);
}

RecipesModel::~RecipesModel()
{
}

void RecipesModel::debugAdd()
{
    d_names << "Tartiflette" << "Oeuf au plat" << "Kebab";
}
