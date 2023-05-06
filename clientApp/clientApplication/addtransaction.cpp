#include "addtransaction.h"
#include "ui_addtransaction.h"

AddTransaction::AddTransaction(ServerConnection * srv, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTransaction)
{
    ui->setupUi(this);
    server = srv;
    connect(parent, SIGNAL(closed()), this, SLOT(on_parent_closed()));
}

AddTransaction::~AddTransaction()
{
    delete ui;
}

void AddTransaction::on_pushButton_clicked()
{
    close();
}

void AddTransaction::on_parent_closed()
{
    close();
}
