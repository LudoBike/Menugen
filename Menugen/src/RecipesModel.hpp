/*

              RecipesModel Class
    
      This class provides to manage the recipes store
      by the user in the SQLite database. The name of
      the recipes is in the list link to the model.

 */

#ifndef __RECIPESMODEL_HPP__
#define __RECIPESMODEL_HPP__


#include <QStringList>
#include <QStringListModel>


class RecipesModel : public QStringListModel
{
    QStringList d_names;
    
public:
    explicit RecipesModel(QObject *parent = nullptr);
    virtual ~RecipesModel();
    void debugAdd();
};


#endif // __RECIPESMODEL_HPP__
