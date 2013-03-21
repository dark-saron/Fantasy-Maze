#include "WindowGraphic.h"

#include "Logic.h"
#include "Graphic.h"
#include "Config.h"
#include "Player.h"

#include <QKeyEvent>
#include "StatsGraphic.h"
#include "DungeonGraphic.h"
#include "MenuGraphic.h"
#include "GameGraphic.h"


CWindowGraphic::CWindowGraphic()
               : QMainWindow()

{
    _currentWidget = 0;

    _ui = new Ui::MainWidget();
    _ui->setupUi(this);
}


CWindowGraphic::~CWindowGraphic()
{
}

void CWindowGraphic::SetWidget(CWindowGraphic::EType widget)
{
    _ui->setupUi(this);

    switch(widget)
    {
     case CWindowGraphic::game: _currentWidget = new CGameGraphic(); break;
     case CWindowGraphic::menu: _currentWidget = new CMenuGraphic(); break;
    }
    _ui->horizontalLayout->addWidget(_currentWidget);
    
}

CWidget* CWindowGraphic::GetWidget() const
{
    return _currentWidget;
}

//detach the menu grafic in the gamephase
void CWindowGraphic::Detach()
{
    if (! _currentWidget)  return; 

    _currentWidget->hide();
    _currentWidget->deleteLater();

    delete _currentWidget;
    _currentWidget = 0;
}

void CWindowGraphic::Reset()
{
    if (_currentWidget)
        _currentWidget->Reset();
}

void CWindowGraphic::Start()
{     
    _currentWidget->Start();
    this->show();
}

// Draws everay Widget in the Window
void CWindowGraphic::Draw()
{
    _currentWidget->Draw();
}


// Gets Key Event and sets Player Input
void CWindowGraphic::keyPressEvent(QKeyEvent *key)
{
    CLogic& logic = CLogic::GetInstance();
    SUserInput::EType input0 = SUserInput::none;
    SUserInput::EType input1 = SUserInput::none;

    switch (key->key())
    {

        case Qt::Key_Up:
            input0 = SUserInput::north; break;
        case Qt::Key_Down:
            input0 = SUserInput::south; break;
        case Qt::Key_Left:
            input0 = SUserInput::east;  break;
        case Qt::Key_Right:
            input0 = SUserInput::west;  break;

        case Qt::Key_W:
            input1 = SUserInput::north; break;
        case Qt::Key_S:
            input1 = SUserInput::south; break;
        case Qt::Key_A:
            input1 = SUserInput::east;  break;
        case Qt::Key_D:
            input1 = SUserInput::west;  break;

        case Qt::Key_Escape:
            input0 = SUserInput::back;  break;

    }

    if (logic.GetPlayer(0) && input0 != SUserInput::none)
        logic.GetPlayer(0)->SetInput(input0);
    
    if (logic.GetPlayer(1) && input1 != SUserInput::none)
        logic.GetPlayer(1)->SetInput(input1);
}


