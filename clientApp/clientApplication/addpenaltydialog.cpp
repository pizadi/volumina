#include "addpenaltydialog.h"
#include "ui_addpenaltydialog.h"

AddPenaltyDialog::AddPenaltyDialog(ServerConnection * srv, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPenaltyDialog)
{
    ui->setupUi(this);
    server = srv;
    connect(parent, SIGNAL(closed()), this, SLOT(on_parent_closed()));
}

AddPenaltyDialog::~AddPenaltyDialog()
{
    delete ui;
}

void AddPenaltyDialog::on_cancel_button_clicked()
{
    close();
}

void AddPenaltyDialog::on_parent_closed()
{
    close();
}
