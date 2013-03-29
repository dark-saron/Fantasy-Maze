#include "CellTypeGraphic.h"
#include "Graphic.h"
#include <assert.h>

CCellTypeGraphic::CCellTypeGraphic()
{
}



CCellTypeGraphic::~CCellTypeGraphic()
{
}

void CCellTypeGraphic::Start()
{
    assert(this->GetWorldEntity() != 0);
    this->SetPixmap(CGraphic::GetInstance().GetPixmap(this->GetWorldEntity()->GetTypeID()));
}

const QPixmap& CCellTypeGraphic::GetPixmap() const
{
    return _pixmap;
}

void CCellTypeGraphic::SetPixmap(const QPixmap& pixmap)
{
    _pixmap = pixmap;
}

const QPixmap CCellTypeGraphic::Draw()
{
    return GetPixmap();
}