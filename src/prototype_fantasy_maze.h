#ifndef PROTOTYPE_FANTASY_MAZE_H
#define PROTOTYPE_FANTASY_MAZE_H

#include <QtGui/QMainWindow>
#include "ui_prototype_fantasy_maze.h"

class CDungeonGraphic;
class Prototype_Fantasy_Maze : public QMainWindow
{
    Q_OBJECT

public:
    Prototype_Fantasy_Maze(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~Prototype_Fantasy_Maze();

private:
    Ui::Prototype_Fantasy_MazeClass ui;
    CDungeonGraphic* _dungeonGraphic;
};

#endif // PROTOTYPE_FANTASY_MAZE_H
