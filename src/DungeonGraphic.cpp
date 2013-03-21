#include "DungeonGraphic.h"

#include "WorldIterator.h"
#include "Dungeon.h"
#include "CellTypeWorld.h"
#include "CellTypeGraphic.h"
#include "Logic.h"
#include "Player.h"
#include "Config.h"
#include "Graphic.h"

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QGridLayout>


CDungeonGraphic::~CDungeonGraphic()
{
    for (int x = 0; x < COLUMNS; ++x) {
        for (int y = 0; y < ROWS; ++y) {
               delete _cell[x][y];
        }
    }
    delete _ui;
}

CDungeonGraphic::CDungeonGraphic()
                : CWidget(),
                  _hiddenID("1E400510-D928-4547-818D-A5E5CC24077F") 
{
    _ui = new Ui::DungeonWidget();
    _ui->setupUi(this);

    for (int x = 0; x < COLUMNS; ++x) {
        for (int y = 0; y < ROWS; ++y) {
            _cell[x][y] = new QLabel();
            _cell[x][y]->setScaledContents(true);
            DrawCell(x, y, CGraphic::GetInstance().GetPixmap(_hiddenID));
            _ui->_dungeonGrid->addWidget(_cell[x][y], x, y);
        }
    }
}

void CDungeonGraphic::Start()
{

}

void CDungeonGraphic::RemoveDeadEntities()
{

}



void CDungeonGraphic::Reset()
{
    for (int x = 0; x < COLUMNS; ++x) {
        for (int y = 0; y < ROWS; ++y) {
            DrawCell(x, y, CGraphic::GetInstance().GetPixmap(_hiddenID));
        }
    }
}

void CDungeonGraphic::DrawCell(const C2DPosition& pos, const QPixmap& pixmap)
{
    DrawCell(pos.GetXPos(), pos.GetYPos(), pixmap);
}

void CDungeonGraphic::DrawCell(int x, int y, const QPixmap& pixmap)
{
    if ((pixmap.isNull())       ||
        (x < 0 || x >= ROWS)    ||
        (y < 0 || y >= COLUMNS) ||
        (_cell[x][y]->pixmap()  &&
         _cell[x][y]->pixmap()->pixmapData() == pixmap.pixmapData()))
        return;
     
    _cell[x][y]->setPixmap(pixmap);
}



void CDungeonGraphic::Draw()
{
    Reset();
    DrawPlayerView(0);
    DrawPlayerView(1);
}

void CDungeonGraphic::DrawPlayerView(int playerNr)
{
    CPlayer* player = CLogic::GetInstance().GetPlayer(playerNr);
    DrawPlayerView(player);
}

void CDungeonGraphic::DrawPlayerView(CPlayer* player)
{
    if(!player) return;

    CCharactereWorld* playerWorld = (CCharactereWorld*) player->GetCharactere().GetWorldEntity();
    C2DPosition pos      = playerWorld->GetPosition() - playerWorld->GetViewRange();
    C2DPosition posRange = playerWorld->GetPosition() + playerWorld->GetViewRange();
    
    for (int x = pos.GetXPos(); x <= posRange.GetXPos(); ++x)
    {
        for (int y = pos.GetYPos(); y <= posRange.GetYPos(); ++y)
        {
            // TODO: const_cast bescause you get just an const cellTypeWorld from the dungeon
            const CCellTypeWorld& cellTypeWorld = CDungeon::GetInstance().GetCell(C2DPosition(x, y));
            CCellTypeGraphic& cellTypeGraphic = CGraphic::GetInstance().GetCellType(cellTypeWorld);
            
            DrawCell(x, y, cellTypeGraphic.Draw());
        }
    }

    CCharactereWorld* areaChars = CDungeon::GetInstance().GetCharactersInArea(pos, posRange); 
    IWorldIterator iter = IWorldIterator(areaChars);

    for (; iter.FirstLoop(); ++iter)
    {
        CCharactereWorld& charWorld = (CCharactereWorld&) *(*iter);
        CCharactereGraphic& charGraphic = CGraphic::GetInstance().GetCharactere(charWorld);
        DrawCell(charWorld.GetPosition(), charGraphic.Draw());
    }
}

