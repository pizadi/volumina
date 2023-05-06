#ifndef ADDTRANSACTION_H
#define ADDTRANSACTION_H

#include <QDialog>
#include "serverconnection.h"

namespace Ui {
class AddTransaction;
}

class AddTransaction : public QDialog
{
    Q_OBJECT

public:
    explicit AddTransaction(ServerConnection *, QWidget *parent = nullptr);
    ~AddTransaction();

private slots:
    void on_pushButton_clicked();

    void on_parent_closed();

private:
    Ui::AddTransaction *ui;
    ServerConnection * server;
};

#endif // ADDTRANSACTION_H
