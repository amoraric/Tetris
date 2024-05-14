#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

    int getWidth() const;
    int getHeight() const;
    std::string getNickname() const;
    int getLevel() const;
    int getMaxTime() const;
    bool getRandomize() const;

private:
    Ui::Dialog *ui;
};

#endif // SETTINGSDIALOG_H
