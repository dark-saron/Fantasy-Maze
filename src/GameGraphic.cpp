#include "GameGraphic.h"
#include "DungeonGraphic.h"
#include "StatsGraphic.h"

#include "Logic.h"

CGameGraphic::CGameGraphic()
{
    _ui = new Ui::_GameWidget();

    _ui->setupUi(this);

    _dungeonGraphic = new CDungeonGraphic();
    _statsGraphic0 = new CStatsGraphic(0);
    
    _ui->horizontalLayout->addWidget(_dungeonGraphic);
    _ui->horizontalLayout->addWidget(_statsGraphic0);

    if(CLogic::GetInstance().GetPlayer(1))
    {
        _statsGraphic1 = new CStatsGraphic(1);
        _ui->horizontalLayout->addWidget(_statsGraphic1);
    }
}


CGameGraphic::~CGameGraphic(void)
{
}

void CGameGraphic::Start()
{
    _dungeonGraphic->Start();
    _statsGraphic0->Start();

    if(CLogic::GetInstance().GetPlayer(1))
    {
        _statsGraphic1->Start();
    }
}

void CGameGraphic::Reset()
{

}

void CGameGraphic::Draw()
{
    _dungeonGraphic->Draw();
    _statsGraphic0->Draw();

    if(CLogic::GetInstance().GetPlayer(1))
    {
        _statsGraphic1->Draw();
    }
}
