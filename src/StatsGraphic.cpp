#include "StatsGraphic.h"

#include <qstring.h>
#include <string>

#include "Graphic.h"
#include "Logic.h"
#include "Player.h"
#include "Config.h"

CStatsGraphic::CStatsGraphic(int playerNr)
              : _playerNr(playerNr)
{
    _ui = new Ui::StatWidget();
    _ui->setupUi(this);
}


CStatsGraphic::~CStatsGraphic()
{

   /* for (int x = 0; x < CStatsGraphic::INV_SIZE_X; x++)
    {
        for (int y = 0; y < CStatsGraphic::INV_SIZE_Y; y++)
        {
            delete _cell[x][y];
        }
    }*/

    delete _ui;
}

void CStatsGraphic::Reset()
{
}

void CStatsGraphic::Start()
{
    _ui->_nameLabel->setText("<-Player->");
    _ui->_healthBar->setValue(0);
    _ui->_healthBar->setMaximum(10);
    _ui->_manaBar->setValue(5);
    _ui->_manaBar->setMaximum(10);
    _ui->_levelBar->setValue(0);
    _ui->_levelBar->setMaximum(2);
    _ui->_atkLabel->setText("Attack: ");
    _ui->_defLabel->setText("Defence: ");
 
    for (int x = 0; x < CStatsGraphic::INV_SIZE_X; x++)
    {
        for (int y = 0; y < CStatsGraphic::INV_SIZE_Y; y++)
        {
            _cell[x][y] = new QLabel();
            _cell[x][y]->setScaledContents(true);
            const QPixmap& pixmap = CGraphic::GetInstance().GetPixmap("1E400510-D928-4547-818D-A5E5CC24077F");
            _cell[x][y]->setPixmap(pixmap);
            _ui->_inventoryGrid->addWidget(_cell[x][y], x, y);
        }
    }
}

void CStatsGraphic::Draw()
{
    CPlayer* player = CLogic::GetInstance().GetPlayer(_playerNr);

    if(player)
    {    
        CCharactereWorld* charWorld = (CCharactereWorld*) player->GetCharactere().GetWorldEntity();

        _ui->_nameLabel->setText("< Player >");
        _ui->_healthBar->setValue(charWorld->GetHealth());
        _ui->_healthBar->setMaximum(charWorld->GetMaxHealth());
        _ui->_manaBar->setValue(charWorld->GetMana());
        _ui->_manaBar->setMaximum(charWorld->GetMaxMana());
        _ui->_levelBar->setValue(charWorld->GetNeedExpTillLvlUp());
        _ui->_levelBar->setMaximum(player->GetCharactere().GetLevelExp());
      
        
        _ui->_atkLabel->setText(QString("Attack: %1").arg(charWorld->GetAttack()));
        _ui->_defLabel->setText(QString("Defence: %1").arg(charWorld->GetDefense()));
        
    }

    //TODO: Setzen des inventars!!

}