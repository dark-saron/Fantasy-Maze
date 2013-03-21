#include "MenuGraphic.h"

#include "Logic.h"
#include "Graphic.h"

CMenuGraphic::CMenuGraphic()
{
    _ui = new Ui::MenuWidget();
    _ui->setupUi(this);
    QObject::connect(_ui->_singleStartBtn, SIGNAL(clicked()), this, SLOT(OnSingleStartButton()));
    QObject::connect(_ui->_multiStartBtn, SIGNAL(clicked()), this, SLOT(OnMultiStartButton()));
    QObject::connect(_ui->_endBtn, SIGNAL(clicked()), this, SLOT(OnExitGameButton()));
    
}


CMenuGraphic::~CMenuGraphic()
{
    delete _ui;
}

void CMenuGraphic::Reset()
{
}

void CMenuGraphic::Start()
{
}

void CMenuGraphic::Draw()
{
}

void CMenuGraphic::OnSingleStartButton()
{
    int level = 1;
    int players = 1;
    CLogic::GetInstance().StartLevel(level, players, true);
    CGraphic::GetInstance().SetAction(CGraphic::startGame);
}

void CMenuGraphic::OnMultiStartButton()
{
    int level = 1;
    int players = 2;
    CLogic::GetInstance().StartLevel(level, players, true);
    CGraphic::GetInstance().SetAction(CGraphic::startGame);
}

void CMenuGraphic::OnExitGameButton()
{
    CGraphic::GetInstance().SetExit();
}