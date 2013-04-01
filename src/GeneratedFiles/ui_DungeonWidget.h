/********************************************************************************
** Form generated from reading UI file 'DungeonWidget.ui'
**
** Created: Sat Mar 30 21:32:07 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUNGEONWIDGET_H
#define UI_DUNGEONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DungeonWidget
{
public:
    QGridLayout *_dungeonGrid;

    void setupUi(QWidget *DungeonWidget)
    {
        if (DungeonWidget->objectName().isEmpty())
            DungeonWidget->setObjectName(QString::fromUtf8("DungeonWidget"));
        DungeonWidget->resize(544, 544);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(32);
        sizePolicy.setVerticalStretch(32);
        sizePolicy.setHeightForWidth(DungeonWidget->sizePolicy().hasHeightForWidth());
        DungeonWidget->setSizePolicy(sizePolicy);
        DungeonWidget->setMinimumSize(QSize(544, 544));
        DungeonWidget->setSizeIncrement(QSize(32, 32));
        _dungeonGrid = new QGridLayout(DungeonWidget);
        _dungeonGrid->setSpacing(0);
        _dungeonGrid->setContentsMargins(0, 0, 0, 0);
        _dungeonGrid->setObjectName(QString::fromUtf8("_dungeonGrid"));

        retranslateUi(DungeonWidget);

        QMetaObject::connectSlotsByName(DungeonWidget);
    } // setupUi

    void retranslateUi(QWidget *DungeonWidget)
    {
        DungeonWidget->setWindowTitle(QApplication::translate("DungeonWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DungeonWidget: public Ui_DungeonWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUNGEONWIDGET_H
