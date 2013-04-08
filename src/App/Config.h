#pragma once

#include "src/Extern/json/elements.h"

#include <map>

class CConfig
{
public:
    CConfig();
    ~CConfig();

    bool LoadConfig();
    bool LoadCharactereTypes();
    bool LoadCellTypes();

    const json::Array& GetCellTypes();
    const json::Object GetDungeon(int level);
    const json::Object& GetCharactereType(const std::string& id);
    const std::string& GetImageName(const std::string& id);

    //singleton functions
    static void CreateInstance();
    static CConfig& GetInstance();
    static void DestroyInstance();
    static bool IsValid();

private:
    std::map<std::string, json::Object> _charactereTypes;
    std::map<std::string, std::string> _imageNames;
    json::Array _cellTypes;

    static CConfig* _singleton;
};
