#pragma once

#include "ui_MainWidget.h"

class QKeyEvent;
class CWidget;

class CWindowGraphic : public QMainWindow
{
public:
    enum EType
    {
        menu,
        game
    };

    CWindowGraphic();
    ~CWindowGraphic();

    void Detach();
    CWidget* GetWidget() const;
    void SetWidget(EType widget);
    
    void Draw();
    void Reset();
    void Start();

    void keyPressEvent(QKeyEvent* key);

signals:
  void DoDraw();

public slots:
  void OnDraw();
  void OnExit();

private:

    Ui::MainWidget* _ui;
    CWidget* _currentWidget;
};

