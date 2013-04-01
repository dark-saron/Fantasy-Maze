#include "src/Graphics/Graphic.h"

#include "src/Graphics/WindowGraphic.h"
#include "src/App/Config.h"
#include "src/Data/Dungeon.h"
#include "src/Graphics/Connector.h"
#include "src/Data/WorldIterator.h"
#include "src/Graphics/Widget.h"

#include <QObject>
#include <QApplication>
#include <QTranslator>
#include <assert.h>

//singleton is always 0
CGraphic* CGraphic::_singleton = 0;

CGraphic::CGraphic(int argc, char* argv[])
         : QObject()
{

    _app = new QApplication(argc, argv);
	//QTranslator* test = new QTranslator(_app, "prototype_fantasy_maze_de.ts");
	//_app->installTranslator(test);
	_mainWindow = new CWindowGraphic();

    _app->connect(this, SIGNAL(DoDraw()), this, SLOT(OnDraw()));
    _app->connect(this, SIGNAL(DoSetWidget()), this, SLOT(OnSetWidget()));
    _app->connect(_app, SIGNAL(aboutToQuit()), this, SLOT(OnExit()));

    _mainWindow->SetWidget(CWindowGraphic::menu);
}


CGraphic::~CGraphic()
{
    Reset();
    
    CCellTypeWorld* cellTypeWorld = CDungeon::GetInstance().GetAllCellTypes();
    IWorldIterator iter = IWorldIterator(cellTypeWorld);

    for (; iter.FirstLoop(); ++iter)
    {
        delete static_cast<CCellTypeGraphic*> ((*iter)->GetGraphicEntity());
    }

    delete _mainWindow;
    delete _app;
}


void CGraphic::Exit()
{
    _app->exit();
}

void CGraphic::SetWidget(CWindowGraphic::EType widget)
{
    _setWidget = widget;
    emit(DoSetWidget());
}

void CGraphic::Reset()
{
    _mainWindow->Reset();
    _pixmaps.clear();
}

int CGraphic::Run()
{
    return _app->exec();
}

void CGraphic::Start()
{
    _mainWindow->Start();
}


void CGraphic::Draw()
{
    emit(DoDraw());
}


void CGraphic::OnExit()
{
    CConnector::GetInstance().Exit();
}

void CGraphic::OnDraw()
{
    _mainWindow->Draw();
}


void CGraphic::OnSetWidget()
{
    _mainWindow->SetWidget(_setWidget);
}

void CGraphic::RemoveDeadEntities()
{
    CCharactereWorld* charWorld = CDungeon::GetInstance().GetAllCharacters();
    CCharactereGraphic* charGraphic; 
    IWorldIterator iter = IWorldIterator(charWorld);
    for (; iter.FirstLoop(); ++iter)
    {
        charWorld   = static_cast<CCharactereWorld*> (*iter);
        charGraphic = static_cast<CCharactereGraphic*> (charWorld->GetGraphicEntity()); 
        if (charGraphic && charWorld->IsDead())
            delete charGraphic;
    }
}

// loads and returns the pixmap from the given ID, if it doesnt exist, it returns an empty pixmap
const QPixmap& CGraphic::GetPixmap(const std::string& typeID)
{
    if (_pixmaps.find(typeID) == _pixmaps.end())
    {
        const char* imageName = CConfig::GetInstance().GetImageName(typeID).c_str();
        QPixmap pixmap = QPixmap(imageName);
        assert(!pixmap.isNull()); // if this happens, the dungeon-files are broken or the pixmap doesnt exist

        _pixmaps[typeID] = pixmap;
    }
    return _pixmaps[typeID];
}

// returns the graphicEntity to this cellType, if it doesnt exist, it will create it
CCellTypeGraphic& CGraphic::GetCellType(const CCellTypeWorld& constCellType)
{
    // TODO: find another solution without const_cast, const_cast is needed, bescause we get just an const cellTypeWorld from the dungeon
    CCellTypeWorld& cellTypeWorld = const_cast<CCellTypeWorld&> (constCellType);
    CCellTypeGraphic* cellTypeGraphic = static_cast<CCellTypeGraphic*> (cellTypeWorld.GetGraphicEntity());
    if (!cellTypeGraphic)
    {
        cellTypeGraphic = new CCellTypeGraphic();
        cellTypeGraphic->SetWorldEntity(&cellTypeWorld);
        cellTypeWorld.SetGraphicEntity(cellTypeGraphic);
        cellTypeGraphic->Start();
    }

    return *cellTypeGraphic;
}

CCharactereGraphic& CGraphic::GetCharactere(CCharactereWorld& charWorld)
{
    CCharactereGraphic* charGraphic = static_cast<CCharactereGraphic*> (charWorld.GetGraphicEntity());
    if (!charGraphic)
    {
        charGraphic = new CCharactereGraphic();
        charGraphic->SetWorldEntity(&charWorld);
        charWorld.SetGraphicEntity(charGraphic);
        charGraphic->Start();
    }

    return *charGraphic;
}


///////////////////////////////////////////////////////////////
/// _singleton functions
//////////////////////////////////////////////////////////////

//gets the instance of the singleton
CGraphic& CGraphic::GetInstance()
{
    assert(_singleton != 0);

    return *_singleton;
}

//creates the instance of the singleton
void CGraphic::CreateInstance(int argc, char* argv[])
{
    assert(_singleton == 0);
     
    CGraphic::_singleton = new CGraphic(argc, argv);
}

//gives the memory free from the singleton and sets it back 0
void CGraphic::DestroyInstance()
{
    assert(_singleton != 0);

    delete _singleton;
    _singleton = 0;
}

//gives true back if singleton is set
bool CGraphic::IsValid()
{
    return _singleton != 0;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
