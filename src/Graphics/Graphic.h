#pragma once

#include "src/Graphics/CellTypeGraphic.h"
#include "src/Data/CellTypeWorld.h"
#include "src/Graphics/CharactereGraphic.h"
#include "src/Data/CharactereWorld.h"
#include "src/Data/Direction.h"
#include "src/Graphics/WindowGraphic.h"

#include <QObject>

class QApplication;

class CGraphic : private QObject
{
Q_OBJECT
public:
    int Run();
    void RemoveDeadEntities();
    void SetWidget(CWindowGraphic::EType widget);

    void Draw();
    void Reset();
    void Start();

    CCellTypeGraphic& GetCellType(const CCellTypeWorld& constCellType);
    CCharactereGraphic& GetCharactere(CCharactereWorld& charWorld);
    const QPixmap& GetPixmap(const std::string& typeID);
    void Exit();

     //singleton functions
    static void CreateInstance(int argc, char* argv[]);
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

    QApplication* _app;
    CWindowGraphic* _mainWindow;
    std::map<std::string, QPixmap> _pixmaps;
    CWindowGraphic::EType _setWidget;

    // singleton
    CGraphic();
    CGraphic(int argc, char** argv);
    ~CGraphic();
    static CGraphic* _singleton;
};

