#pragma once

#include "GraphicEntity.h"

#include <QPixmap>

class CCharactereGraphic : public CGraphicEntity
{
public:
    CCharactereGraphic();
    ~CCharactereGraphic();

    const QPixmap& GetPixmap() const;
    void SetPixmap(const QPixmap&);

    QPixmap Draw();
    void Start();


private:

    QPixmap _pixmap;
    
};

