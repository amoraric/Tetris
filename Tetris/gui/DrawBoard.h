#ifndef DRAWBOARD_H
#define DRAWBOARD_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "Position.h"
#include "BrickModel.h"

/**
 * @brief The DrawBoard class handles the graphical representation of the game board.
 */
class DrawBoard {
public:
    /**
     * @brief Constructor for the DrawBoard class.
     * @param scene The QGraphicsScene where the board will be drawn.
     */
    DrawBoard(QGraphicsScene *scene);
    /**
     * @brief Draws the grid on the game board.
     * @param viewWidth The width of the view.
     * @param viewHeight The height of the view.
     */
    void drawGrid(int viewWidth, int viewHeight);
    /**
     * @brief Sets the size of the game board.
     * @param newWidth The new width of the board.
     * @param newHeight The new height of the board.
     */
    void setSize(int newWidth, int newHeight);
    /**
     * @brief Gets the size of the game board.
     * @return A pair containing the width and height of the board.
     */
    std::pair<int, int> getBoardSize();
    /**
     * @brief Updates the game board with the current state.
     * @param staticBoard The static part of the board.
     * @param currentPosition The position of the current brick.
     * @param currentBrick The current brick model.
     */
    void updateBoard(const std::vector<std::vector<bool>>& staticBoard, const Position& currentPosition, const BrickModel& currentBrick);
    /**
     * @brief Resets the game board.
     */
    void reset();

private:
    QGraphicsScene *scene; /**< The QGraphicsScene where the board is drawn. */
    int numColumns; /**< The number of columns on the board. */
    int numRows; /**< The number of rows on the board. */
    int blockSize; /**< The size of each block on the board. */
    QColor color; /**< The color of the blocks. */
    /**
     * @brief Calculates the size of each block based on the view dimensions.
     * @param width The width of the view.
     * @param height The height of the view.
     * @return The size of each block.
     */
    int calculateBlockSize(int width, int height);
};

#endif // DRAWBOARD_H
