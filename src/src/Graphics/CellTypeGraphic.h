#pragma once

#include "src/Graphics/GraphicEntity.h"
#include "src/Data/CellTypeWorld.h"

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

