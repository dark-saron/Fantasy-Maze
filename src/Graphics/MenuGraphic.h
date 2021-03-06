#pragma once

#include <QLabel>
#include <qobject.h>
#include "src/App/Phase.h"
#include "ui_MenuWidget.h"
#include "src/Graphics/Widget.h"

class CMenuGraphic : public CWidget
{
    Q_OBJECT

    
public:

    CMenuGraphic();
    ~CMenuGraphic();

    void Reset();
    void Start();
    void Draw();
	void ShowBtn();

private slots:
    void OnContinueButton();
    void OnSingleStartButton();
    void OnMultiStartButton();
    void OnExitGameButton();

private:
    Ui::MenuWidget* _ui;
};

