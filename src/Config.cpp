#include "Config.h"

#include "json/reader.h"

#include <assert.h>
#include <fstream>

// TODO: Fehlerbehandlung bei falschen JSON muss herein!

CConfig::CConfig()
{
}

CConfig::~CConfig()
{
}

bool CConfig::LoadConfig()
{
    return LoadCharactereTypes() && LoadCellTypes();
}

// loads the names from different creatures from /Ressources/Names.dat
bool CConfig::LoadCellTypes()
{
    char* filename = "Dungeon/CellTypes.dat";
    
    std::ifstream file(filename);

    json::Array root;
    json::Reader::Read(_cellTypes, file);
    
    json::Array::const_iterator iter(_cellTypes.Begin());
    json::Array::const_iterator iterEnd(_cellTypes.End());
    
    for (; iter != iterEnd; ++iter)
    {
        const json::Object& data = *iter;
        std::string id = (json::String) data["ID"];
        _imageNames[id] = (json::String) data["Image"];
    }

    file.close();
    return true;
}



// loads/reloads the creatures-configuration /Dungeon/Creatures.dat
bool CConfig::LoadCharactereTypes()
{
    char* filename = "Dungeon/CharactereTypes.dat";
    
    std::ifstream file(filename);

    json::Array root;
    json::Reader::Read(root, file);
    
    json::Array::const_iterator iter(root.Begin());
    json::Array::const_iterator iterEnd(root.End());
    
    for (; iter != iterEnd; ++iter)
    {
        // TODO: Das noch etwas aufhübschen
        const json::Object& data = *iter;

        std::string id = (json::String) data["ID"];
        _charactereTypes[id] = data;

        _imageNames[id] = (json::String) data["Image"];
    }

    file.close();
    return true;
}

const std::string& CConfig::GetImageName(const std::string& id)
{
    return _imageNames[id];
}

const json::Array& CConfig::GetCellTypes()
{
    return _cellTypes;
}

const json::Object& CConfig::GetCharactereType(const std::string& id)
{
    assert(_charactereTypes.find(id) != _charactereTypes.end());
    return _charactereTypes[id];
}

const json::Object CConfig::GetDungeon(int level)
{
    char filename[40];
    char* formatLevel = "Dungeon/Level%i.lvl";
    sprintf(filename, formatLevel, level);
    std::ifstream file(filename);

    json::Object dungeon;
    json::Reader::Read(dungeon, file);

    file.close();
    return dungeon;
}




///////////////////////////////////////////////////////////////
/// _singleton functions
//////////////////////////////////////////////////////////////

CConfig* CConfig::_singleton = 0;

//gets the instance of the singleton
CConfig& CConfig::GetInstance()
{
    assert(_singleton != 0);

    return *_singleton;
}

//creates the instance of the singleton
void CConfig::CreateInstance()
{
    assert(_singleton == 0);

    CConfig::_singleton = new CConfig();
}

//gives the memory free from the singleton and sets it back 0
void CConfig::DestroyInstance()
{
    assert(_singleton != 0);

    delete _singleton;
    _singleton = 0;
}

//gives true back if singleton is set
bool CConfig::IsValid()
{
    return _singleton != 0;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
