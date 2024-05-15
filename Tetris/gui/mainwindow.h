#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qgraphicsscene.h>
#include "DrawBoard.h"
#include <memory>
#include "Facade.h"
#include <QElapsedTimer>
#include "SettingsDialog.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class represents the main window of the application.
 */
class MainWindow : public QMainWindow, public Observer, public std::enable_shared_from_this<MainWindow>
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the MainWindow class.
     * @param parent The parent widget.
     */
    explicit MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Updates the main window. Overrides the update method from Observer.
     */
    void update() override;
    /**
     * @brief Destructor for the MainWindow class.
     */
    ~MainWindow();

protected:
    /**
     * @brief Handles key press events.
     * @param event The key event.
     */
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    /**
     * @brief Slot for handling play button click events.
     */
    void onPlayButtonClicked();
    /**
     * @brief Slot for handling end game button click events.
     */
    void onEndGameButtonClicked();
    /**
     * @brief Slot for opening the settings dialog.
     */
    void openSettingsDialog();
    /**
     * @brief Slot for opening the help dialog.
     */
    void openHelpDialog();
    /**
     * @brief The game loop that runs the game.
     */
    void gameLoop();
    /**
     * @brief Updates the game statistics.
     */
    void updateGameStats();
    /**
     * @brief Updates the time label.
     */
    void updateTimeLabel();
    /**
     * @brief Styles the buttons in the main window.
     */
    void styleButtons();

private:
    /**
     * @brief Handles resize events.
     * @param event The resize event.
     */
    void resizeEvent(QResizeEvent *event) override;
    Ui::MainWindow *ui; /**< The UI for the MainWindow. */
    QGraphicsScene *_scene; /**< The scene where the game is rendered. */
    std::unique_ptr<DrawBoard> drawBoard; /**< The draw board for the game. */
    std::unique_ptr<Facade> facade_; /**< The facade interface for the game. */
    std::string nickname_ = "Anonymous"; /**< The player's nickname. */
    int level_ = 1; /**< The current game level. */
    int timeMax_ = 600; /**< The maximum time for the game. */
    std::unique_ptr<QTimer> timer_; /**< The game timer. */
    std::unique_ptr<QTimer> updateTimer_; /**< The update timer for the game stats. */
    QElapsedTimer elapsedTimer_; /**< Timer to track elapsed time. */
    bool randomize_ = false; /**< Flag to indicate if the game should be randomized. */
    SettingsDialog settingsDialog; /**< The Settings UI. */
    /**
     * @brief Connects the buttons to their respective slots.
     */
    void connectButtons();
    /**
     * @brief Starts the game.
     */
    void startGame();
};

#endif // MAINWINDOW_H
