#pragma once

#include "UserInput.h"
#include "Widget.h"
#include "WindowGraphic.h"
#include "CellTypeWorld.h"
#include "CellTypeGraphic.h"

#include "CharactereWorld.h"
#include "CharactereGraphic.h"

#include <QtGui/QApplication>
#include <QObject>

class CGraphic : QObject
{
Q_OBJECT
public:
    enum EType
    {
        startGame,
        none,
        exit
    };

    enum EType2
    {
        menu,
        game
    };

    EType GetAction();
    int Run();
    void RemoveDeadEntities();
    void SetAction(EType action = none);
    void SetExit();
    void SetWidget(CWindowGraphic::EType widget);

    void Draw();
    void Reset();
    void Start();

    CCellTypeGraphic& GetCellType(const CCellTypeWorld& constCellType);
    CCharactereGraphic& GetCharactere(CCharactereWorld& charWorld);
    const QPixmap& GetPixmap(const std::string& typeID);
    CWidget* GetWidget() const;

     //singleton functions
    static void CreateInstance();
    static CGraphic& GetInstance();
    static void DestroyInstance();
    static bool IsValid();

signals:
  void DoDraw();
  void DoSetWidget();

public slots:
    void OnSetWidget();
    void OnDraw();
    void OnExit();
  
private:


    EType _action;
    CWindowGraphic::EType _setWidget;
    EType2 _deWidget;

    CWindowGraphic* _mainWindow;
    QApplication* _app;

    std::map<std::string, QPixmap> _pixmaps;

    // singleton
    CGraphic();
    CGraphic(int argc, char** argv);
    ~CGraphic();
    static CGraphic* _singleton;

};

