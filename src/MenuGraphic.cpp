#include "MenuGraphic.h"

#include "Graphic.h"
#include "Connector.h"
#include "Logic.h"

CMenuGraphic::CMenuGraphic()
{
    _ui = new Ui::MenuWidget();
    _ui->setupUi(this);
    _ui->_continueBtn->hide();
    QObject::connect(_ui->_singleStartBtn, SIGNAL(clicked()), this, SLOT(OnSingleStartButton()));
    QObject::connect(_ui->_continueBtn, SIGNAL(clicked()), this, SLOT(OnContinueButton()));
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

void CMenuGraphic::ShowBtn()
{

	_ui->_loadBtn->hide();
	_ui->_continueBtn->show();

}


void CMenuGraphic::Draw()
{
	if(CLogic::GetInstance().GetPlayer(0))
		ShowBtn();
}

void CMenuGraphic::OnContinueButton()
{
    CConnector::GetInstance().ContinueGame();
}

void CMenuGraphic::OnSingleStartButton()
{
    CConnector::GetInstance().StartGame(false);
}

void CMenuGraphic::OnMultiStartButton()
{
    CConnector::GetInstance().StartGame(true);
}

void CMenuGraphic::OnExitGameButton()
{
    CGraphic::GetInstance().Exit();
    CConnector::GetInstance().Exit();
}