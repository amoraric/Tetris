#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

/**
 * @brief The SettingsDialog class provides the settings interface for the game.
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the SettingsDialog class.
     * @param parent The parent widget.
     */
    explicit SettingsDialog(QWidget *parent = nullptr);
    /**
     * @brief Destructor for the SettingsDialog class.
     */
    ~SettingsDialog();
    /**
     * @brief Gets the width setting.
     * @return The width setting.
     */
    int getWidth() const;
    /**
     * @brief Gets the height setting.
     * @return The height setting.
     */
    int getHeight() const;
    /**
     * @brief Gets the nickname setting.
     * @return The nickname setting.
     */
    std::string getNickname() const;
    /**
     * @brief Gets the level setting.
     * @return The level setting.
     */
    int getLevel() const;
    /**
     * @brief Gets the maximum time setting.
     * @return The maximum time setting.
     */
    int getMaxTime() const;
    /**
     * @brief Gets the randomize setting.
     * @return The randomize setting.
     */
    bool getRandomize() const;

private:
    Ui::Dialog *ui; /**< The UI for the SettingsDialog. */
};

#endif // SETTINGSDIALOG_H
