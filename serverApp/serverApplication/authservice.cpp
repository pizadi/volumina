#include "authservice.h"
#include "convertorservice.h"
#include <QJsonArray>

AuthService::AuthService()
{

}



QJsonDocument AuthService::login(QJsonDocument input)
{
    QString func = input.object().value("Func").toString();
    QJsonDocument jsonInput(input.object().value("Input").toObject());
    QJsonDocument output;
   username = jsonInput.object()["username"].toString();
   password = jsonInput.object()["password"].toString();
   qDebug() << username << password << endl;
   QSqlQueryModel *model = new QSqlQueryModel();
   model=new QSqlQueryModel();
   QString query;
   query="SELECT * from librarian WHERE username='";
   query+=username;
   query+="' and password='";
   query+=password;
   query+="'";
   model->setQuery(query);
   QJsonDocument x = ConvertorService::toJson(model);
   QJsonObject outjson;
   qDebug() << x.toJson() << endl;
   if (x.array().isEmpty())
   {
       outjson.insert("status", 400);
       QJsonDocument output(outjson);
       return output;
   }
   else
   {
        QString  account_id = x.array().at(0)["account_id"].toString();
        Repository *repo = new Repository();
        QJsonDocument ret = repo->readLibrarian(account_id);
        QJsonObject jsonObject;
        jsonObject.insert("status", QJsonValue::fromVariant("201"));
        ret.setObject(jsonObject);
        return ret;
   }



}
