#ifndef LEND_H
#define LEND_H
#include "basecontroller.h"
class Lend : public BaseController
{
public:
    Lend();
    QJsonDocument response(QJsonDocument);
    QJsonDocument create(QJsonDocument);
    QJsonDocument searchByMember(QJsonDocument);
    QJsonDocument renew(QJsonDocument);
    QJsonDocument returnBookItem(QJsonDocument);
};

#endif // LEND_H
