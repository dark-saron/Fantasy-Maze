#include "CharactereGraphic.h"

#include "Graphic.h"
#include "CharactereWorld.h"

#include <assert.h>

CCharactereGraphic::CCharactereGraphic()
                   : CGraphicEntity()
{
}

CCharactereGraphic::~CCharactereGraphic()
{
}

void CCharactereGraphic::Start()
{
    assert(this->GetWorldEntity() != 0);
    this->SetPixmap(CGraphic::GetInstance().GetPixmap(this->GetWorldEntity()->GetTypeID()));
}

const QPixmap& CCharactereGraphic::GetPixmap() const
{
    return _pixmap;
}

void CCharactereGraphic::SetPixmap(const QPixmap& pixmap)
{
    _pixmap = pixmap;
}

QPixmap CCharactereGraphic::Draw()
{
    CCharactereWorld* charWorld = static_cast<CCharactereWorld*> (GetWorldEntity());
    if (charWorld->IsDead())
        return QPixmap();
    return _pixmap;
}