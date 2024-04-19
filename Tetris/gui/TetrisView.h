#ifndef TETRISVIEW_H
#define TETRISVIEW_H
#include <QtWidgets>

class TetrisView : public QWidget {

private:
    QGridLayout *gridLayout;
    void initUI() {
        gridLayout = new QGridLayout(this);
        gridLayout->setSpacing(0);

        // Create the game board
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                QLabel *cell = new QLabel;
                cell->setMinimumSize(10, 10);
                cell->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                cell->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
                cell->setLineWidth(0);
                cell->setMidLineWidth(1);
                gridLayout->addWidget(cell, i, j);
                gridLayout->setRowStretch(i, 1);
                gridLayout->setColumnStretch(j, 1);
            }
        }

        setLayout(gridLayout);
    }


    int rows;
    int cols;
public:
    TetrisView(int rows, int cols, QWidget *parent = nullptr) : QWidget(parent), rows(rows), cols(cols) {
        initUI();
    }
    void setCellOccupied(int row, int col) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                QLabel *cell = qobject_cast<QLabel*>(gridLayout->itemAtPosition(row, col)->widget());
                cell->setStyleSheet("background-color: blue"); // Change the background color to indicate occupation
            }
        }

        // Method to set a cell as unoccupied
        void setCellUnoccupied(int row, int col) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                QLabel *cell = qobject_cast<QLabel*>(gridLayout->itemAtPosition(row, col)->widget());
                cell->setStyleSheet(""); // Reset the background color
            }
        }

};



#endif // TETRISVIEW_H
