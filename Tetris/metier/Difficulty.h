#ifndef DIFFICULTY_H
#define DIFFICULTY_H

/**
 * @brief The Difficulty class defines the difficulty of the game
 */
class Difficulty {
    int maxScore_;
    int maxLines_;
    int timeLimit_;
public:
    Difficulty(int level);
    int getMaxScore();
    int getMaxLines();
    int getTimeLimit();
};

#endif // DIFFICULTY_H
