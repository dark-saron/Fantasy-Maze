#pragma once

#include "json/elements.h"

#include <map>

class CConfig
{

public:
    
	~CConfig();
	CConfig();
    bool LoadCellTypes();
	bool LoadConfig();
    bool LoadCharactereTypes();
    
    const json::Array& GetCellTypes();
    const json::Object GetDungeon(int level);
    const json::Object& GetCharactereType(const std::string& id);
    const std::string& GetImageName(const std::string& id);

    //singleton functions
    static bool IsValid();
	static CConfig& GetInstance();
    static void CreateInstance();
    static void DestroyInstance();
    
private:
    
	json::Array _cellTypes;
	std::map<std::string, json::Object> _charactereTypes;
    std::map<std::string, std::string> _imageNames;
    
    static CConfig* _singleton;
};
