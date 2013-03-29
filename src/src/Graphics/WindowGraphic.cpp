#include "WindowGraphic.h"

#include "src/Graphics/Connector.h"
#include "src/Graphics/Graphic.h"
#include "src/App/Config.h"
#include "src/Logic/Player.h"

#include <QKeyEvent>
#include "src/Data/Direction.h"
#include "src/Graphics/DungeonGraphic.h"
#include "src/Graphics/MenuGraphic.h"
#include "src/Graphics/GameGraphic.h"


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

    // FIXME: this doesn't delete everything, it just deletes CWidget and all above, but not the attributes of CMenuGraphic or CGameGraphic...
    _currentWidget->hide();
    _currentWidget->close();

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
    CConnector& connector = CConnector::GetInstance();
    SDirection::EType input0 = SDirection::none;
    SDirection::EType input1 = SDirection::none;

    switch (key->key())
    {

        case Qt::Key_Up:
            input0 = SDirection::north; break;
        case Qt::Key_Down:
            input0 = SDirection::south; break;
        case Qt::Key_Left:
            input0 = SDirection::east;  break;
        case Qt::Key_Right:
            input0 = SDirection::west;  break;

        case Qt::Key_W:
            input1 = SDirection::north; break;
        case Qt::Key_S:
            input1 = SDirection::south; break;
        case Qt::Key_A:
            input1 = SDirection::east;  break;
        case Qt::Key_D:
            input1 = SDirection::west;  break;

        case Qt::Key_Escape:
            CConnector::GetInstance().ToggleMenu();  break;

    }

    if (input0 != SDirection::none)
        CConnector::GetInstance().Input(0, input0);
    
    if (input1 != SDirection::none)
        CConnector::GetInstance().Input(1, input1);
}


