#ifndef DIFFICULTY_H
#define DIFFICULTY_H

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
