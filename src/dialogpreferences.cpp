#include "dialogpreferences.h"
#include "ui_dialogpreferences.h"

DialogPreferences::DialogPreferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPreferences)
{
    ui->setupUi(this);
}

DialogPreferences::~DialogPreferences()
{
    delete ui;
}

void DialogPreferences::on_okButton_clicked()
{
    close();
}

void DialogPreferences::on_comboBoxLanguage_currentIndexChanged(int index)
{
    emit(comboBoxLanguageIndexChanged(index));
}
