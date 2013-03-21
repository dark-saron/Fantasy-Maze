#pragma once

#include <QtGui/QWidget>

class CWidget : public QWidget
{
    Q_OBJECT
public:
    virtual void Draw() = 0;
    virtual void Reset() = 0;
    virtual void Start() = 0;
};

