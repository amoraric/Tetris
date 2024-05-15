#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
class HelpDialog;
}

/**
 * @brief The HelpDialog class provides the help interface for the game.
 */
class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the HelpDialog class.
     * @param parent The parent widget.
     */
    explicit HelpDialog(QWidget *parent = nullptr);
    /**
     * @brief Destructor for the HelpDialog class.
     */
    ~HelpDialog();

private:
    Ui::HelpDialog *ui; /**< The UI for the HelpDialog. */
};

#endif // HELPDIALOG_H
