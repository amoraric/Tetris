#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->spinBoxWidth->setValue(10);
    ui->spinBoxHeight->setValue(20);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

int SettingsDialog::getWidth() const
{
    return ui->spinBoxWidth->value();
}

int SettingsDialog::getHeight() const
{
    return ui->spinBoxHeight->value();
}
