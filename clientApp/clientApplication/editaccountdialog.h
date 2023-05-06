#ifndef EDITACCOUNTDIALOG_H
#define EDITACCOUNTDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include "memberviewdialog.h"
#include "serverconnection.h"

namespace Ui {
class EditAccountDialog;
}

class EditAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditAccountDialog(ServerConnection *, QWidget *parent = nullptr);
    ~EditAccountDialog();

private slots:
    void on_close_button_clicked();

    void on_parent_closed();

    void on_submit_button_clicked();

private:
    Ui::EditAccountDialog *ui;
    ServerConnection * server;
};

#endif // EDITACCOUNTDIALOG_H

