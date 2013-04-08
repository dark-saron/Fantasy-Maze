#pragma once

#include "ui_DungeonWidget.h"

#include "src/Data/CellTypeWorld.h"
#include "src/Data/CharactereWorld.h"
#include "src/Graphics/Widget.h"

#include <QPixmap>

#include <map>

class QLabel;
class QWidget;
class CPlayer;

class CDungeonGraphic : public CWidget
{
public:
    CDungeonGraphic();
    ~CDungeonGraphic();

    void Draw();

    void RemoveDeadEntities();
    void Reset();
    void Start();
    
private:
    static const int COLUMNS = 17;
    static const int ROWS = 17;

    void DrawCell(int x, int y, const QPixmap& pixmap);
    void DrawCell(const C2DPosition<>& pos, const QPixmap& pixmap);

    void DrawPlayerView(int playerNr);
    void DrawPlayerView(CCharactereWorld* player);

    QLabel* _cell[COLUMNS][ROWS];
    QWidget* _widget;
    Ui::DungeonWidget* _ui;

    const std::string _hiddenID;
};

