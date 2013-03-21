#pragma once

#include "GraphicEntity.h"

#include "CellTypeWorld.h"

#include <QLabel>
#include <QPixmap>


class CCellTypeGraphic : public CGraphicEntity
{
public:
    CCellTypeGraphic();
    ~CCellTypeGraphic();

    const QPixmap& GetPixmap() const;
    void SetPixmap(const QPixmap& pixmap);

    const QPixmap Draw();
    void Start();


private:
    QPixmap _pixmap;

};

