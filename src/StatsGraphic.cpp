#include "StatsGraphic.h"

#include <qstring.h>
#include <string>

#include "Connector.h"
#include "CharactereLogic.h"
#include "Graphic.h"
#include "Config.h"

CStatsGraphic::CStatsGraphic(int playerNr)
              : _playerNr(playerNr)
{


    _ui = new Ui::StatWidget();
    _ui->setupUi(this);
 
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


CStatsGraphic::~CStatsGraphic()
{

   for (int x = 0; x < CStatsGraphic::INV_SIZE_X; x++)
    {
        for (int y = 0; y < CStatsGraphic::INV_SIZE_Y; y++)
        {
            delete _cell[x][y];
        }
    }

    delete _ui;
}

void CStatsGraphic::Reset()
{
}

void CStatsGraphic::Start()
{

}

void CStatsGraphic::Draw()
{
    
    CCharactereWorld* charWorld = CConnector::GetInstance().GetPlayerCharactere(_playerNr);

    if(charWorld)
    {    
        CCharactereLogic* charLogic = static_cast<CCharactereLogic*> (charWorld->GetLogicEntity());

        _ui->_nameLabel->setText("< Spieler >");
        _ui->_healthBar->setValue(charWorld->GetHealth());
        _ui->_healthBar->setMaximum(charWorld->GetMaxHealth());
        _ui->_manaBar->setValue(charWorld->GetMana());
        _ui->_manaBar->setMaximum(charWorld->GetMaxMana());
		_ui->_levelLabel->setText(QString("Level %1").arg(charWorld->GetLevel()));
        _ui->_levelBar->setValue(charWorld->GetNeedExpTillLvlUp());
        _ui->_levelBar->setMaximum(charLogic->GetLevelExp());
        
        
        _ui->_atkLabel->setText(QString("Attack: %1").arg(charWorld->GetAttack()));
        _ui->_defLabel->setText(QString("Defence: %1").arg(charWorld->GetDefense()));
        
    }


}