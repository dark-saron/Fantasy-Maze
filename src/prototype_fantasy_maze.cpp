#include "prototype_fantasy_maze.h"
#include <QLabel>
#include "DungeonGraphic.h"

Prototype_Fantasy_Maze::Prototype_Fantasy_Maze(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);

}

Prototype_Fantasy_Maze::~Prototype_Fantasy_Maze()
{
    delete _dungeonGraphic;
}
