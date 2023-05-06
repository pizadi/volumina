#include "editaccountdialog.h"
#include "ui_editaccountdialog.h"
QJsonObject MemberViewDialog::lend;
QJsonObject MemberViewDialog::member;

EditAccountDialog::EditAccountDialog(ServerConnection * srv, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditAccountDialog)
{
    ui->setupUi(this);
    connect(parent, SIGNAL(closed()), this, SLOT(on_parent_closed()));
    server = srv;
    ui->email_line_dit->setText(MemberViewDialog::member.value("email").toString());
    ui->home_address_text_dit->setText(MemberViewDialog::member.value("address").toString());
    ui->phone_number_line_dit->setText(MemberViewDialog::member.value("phone_number").toString());
    ui->first_name_line_dit->setText(MemberViewDialog::member.value("user_name").toString());
}

EditAccountDialog::~EditAccountDialog()
{
    delete ui;
}

void EditAccountDialog::on_close_button_clicked()
{
    this->close();
}

void EditAccountDialog::on_parent_closed()
{
    close();
}

void EditAccountDialog::on_submit_button_clicked()
{
//    repo.updateLibrarian(jsonObject["account_id"].toString(),
//           jsonObject["email"].toString(), jsonObject["address"].toString(),
//           jsonObject["phone_number"].toString(), jsonObject["password"].toString());
    QJsonObject parameter;

    if (ui->new_password_line_dit->text() != ui->new_password_line_dit->text()) {
        ui->msg_label->setText("Passwords do not match.");
        return;
    }
    else if (ui->new_password_line_dit->text() == ""){
        parameter.insert("account_id", MemberViewDialog::member.value("account_id"));
        parameter.insert("email", ui->email_line_dit->text());
        parameter.insert("address", ui->home_address_text_dit->toPlainText());
        parameter.insert("phone_number", ui->phone_number_line_dit->text());
        parameter.insert("password", MemberViewDialog::member.value("password"));
    }
    else {
        parameter.insert("account_id", MemberViewDialog::member.value("account_id"));
        parameter.insert("email", ui->email_line_dit->text());
        parameter.insert("address", ui->home_address_text_dit->toPlainText());
        parameter.insert("phone_number", ui->phone_number_line_dit->text());
        parameter.insert("password", ui->new_password_line_dit->text());
    }
    QJsonObject out;
    QJsonDocument doc;

    out.insert("Class", "Lend");
    out.insert("Func", "Create");
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
               this->ui->msg_label->setText("Data changed.");
                close();
            } else {
                this->ui->msg_label->setText("Failed to update user data.");
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
