#pragma once

#include "Widget.h"
#include "ui_GameWidget.h"
class CStatsGraphic;
class CDungeonGraphic;

class CGameGraphic : public CWidget
{
public:
    CGameGraphic();
    ~CGameGraphic(void);

    void Draw();
    void Reset();
    void Start();

private:
    CDungeonGraphic* _dungeonGraphic;
    CStatsGraphic* _statsGraphic0;
    CStatsGraphic* _statsGraphic1;

    Ui::_GameWidget* _ui;
};

