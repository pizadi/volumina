#include <QCoreApplication>
#include "repository.h"
#include "httpserver.h"
#include "QJsonArray"
#include <QSqlDatabase>
#include <QSqlQueryModel>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../Library.db");
    db.open();
    HTTPServer server;
    server.startServer();
    return a.exec();
}
