#include "memberviewdialog.h"
#include "ui_memberviewdialog.h"

MemberViewDialog::MemberViewDialog(ServerConnection * srv, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemberViewDialog)
{
    ui->setupUi(this);
    server = srv;
}

MemberViewDialog::~MemberViewDialog()
{
    delete ui;
}

void MemberViewDialog::on_close_button_clicked()
{
    close();
}

void MemberViewDialog::on_lend_button_clicked()
{
    SearchView * w = new SearchView(server, this);
    w->show();
}

void MemberViewDialog::on_renew_member_button_clicked()
{
    QJsonObject out;
    QJsonDocument doc;

    out.insert("Class", "Member");
    out.insert("Func", "Renew");
    out.insert("Input", MemberViewDialog::member);
    doc.setObject(out);
    QByteArray msg = doc.toJson();
    if (server->isOpen()) {
        server->write(msg);
        server->flush();
        if (server->waitForReadyRead(3000)){
            QByteArray ret = server->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(ret);
            QJsonValue status = jsonDoc.object()["status"];
            qDebug() << status.toString() << endl;
            if (status.toString() == "201"){
               this->ui->msg_label->setText("Member renewed.");
            } else {
                this->ui->msg_label->setText("Membership renewal failed.");
            }
        }
        else
        {
            this->ui->msg_label->setText("Communication Error.");
        }
    }
    else
    {
        this->ui->msg_label->setText("Server is disconnected.");
    }
}

void MemberViewDialog::on_add_transaction_button_clicked()
{
    AddTransaction * w = new AddTransaction(server, this);
    w->show();
}

void MemberViewDialog::on_MemberViewDialog_destroyed()
{
    emit closed();
}

void MemberViewDialog::on_add_penalty_button_clicked()
{
    AddPenaltyDialog * w = new AddPenaltyDialog(server, this);
    w->show();
}

void MemberViewDialog::on_renew_book_button_clicked()
{
    QJsonObject out;
    QJsonObject parameter;
    QJsonDocument doc;
    parameter.insert("lend_id", MemberViewDialog::lend.value("lend_id"));
    parameter.insert("lend_time", MemberViewDialog::lend.value("lend_times").toInt() + 1);
    out.insert("Class", "Lend");
    out.insert("Func", "Renew");
    out.insert("Input", parameter);
    doc.setObject(out);
    QByteArray msg = doc.toJson();
    if (server->isOpen()) {
        server->write(msg);
        server->flush();
        if (server->waitForReadyRead(3000)){
            QByteArray ret = server->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(ret);
            QJsonValue status = jsonDoc.object()["status"];
            qDebug() << status.toString() << endl;
            if (status.toString() == "201"){
               this->ui->msg_label->setText("Book renewed.");
            } else {
                this->ui->msg_label->setText("This book was renewed too mant times.");
            }
        }
        else
        {
            this->ui->msg_label->setText("Communication Error.");
        }
    }
    else
    {
        this->ui->msg_label->setText("Server is disconnected.");
    }
}

void MemberViewDialog::on_return_button_clicked()
{
    QJsonObject out;
    QJsonObject parameter;
    QJsonDocument doc;
    parameter.insert("lend_id", MemberViewDialog::lend.value("lend_id"));
    parameter.insert("lend_time", MemberViewDialog::lend.value("lend_times"));
    out.insert("Class", "Lend");
    out.insert("Func", "Return");
    out.insert("Input", parameter);
    doc.setObject(out);
    QByteArray msg = doc.toJson();
    if (server->isOpen()) {
        server->write(msg);
        server->flush();
        if (server->waitForReadyRead(3000)){
            QByteArray ret = server->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(ret);
            QJsonValue status = jsonDoc.object()["status"];
            qDebug() << status.toString() << endl;
            if (status.toString() == "201"){
               this->ui->msg_label->setText("The book is returned.");
            } else {
                this->ui->msg_label->setText("This lend is no longer valid.");
            }
        }
        else
        {
            this->ui->msg_label->setText("Communication Error.");
        }
    }
    else
    {
        this->ui->msg_label->setText("Server is disconnected.");
    }
}
