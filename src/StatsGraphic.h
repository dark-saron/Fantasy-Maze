#pragma once

#include <QLabel>
#include <qprogressbar.h>
#include <qgridlayout.h>
#include "CellTypeWorld.h"
#include "Widget.h"
#include "ui_StatWidget.h"

class CStatsGraphic : public CWidget
{
public:
    CStatsGraphic(int playerNr);
    ~CStatsGraphic();

    void Draw();
    void Reset();
    void Start();

private:
    int _playerNr;
    static const int INV_SIZE_X = 3;
    static const int INV_SIZE_Y = 3;

    Ui::StatWidget* _ui;
    QLabel* _cell[INV_SIZE_X][INV_SIZE_Y];
};

