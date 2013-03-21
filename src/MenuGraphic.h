#pragma once

#include <QLabel>
#include <qobject.h>
#include "Phase.h"
#include "ui_MenuWidget.h"
#include "Widget.h"

class CMenuGraphic : public CWidget
{
    Q_OBJECT

    
public:

    CMenuGraphic();
    ~CMenuGraphic();

    void Reset();
    void Start();
    void Draw();

private slots:
    void OnSingleStartButton();
    void OnMultiStartButton();
    void OnExitGameButton();

private:
    Ui::MenuWidget* _ui;
};
