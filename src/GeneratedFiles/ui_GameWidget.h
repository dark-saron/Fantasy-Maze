/********************************************************************************
** Form generated from reading UI file 'GameWidget.ui'
**
** Created: Sat Mar 30 21:32:07 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui__GameWidget
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *_GameWidget)
    {
        if (_GameWidget->objectName().isEmpty())
            _GameWidget->setObjectName(QString::fromUtf8("_GameWidget"));
        _GameWidget->resize(78, 16);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(_GameWidget->sizePolicy().hasHeightForWidth());
        _GameWidget->setSizePolicy(sizePolicy);
        _GameWidget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(_GameWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        retranslateUi(_GameWidget);

        QMetaObject::connectSlotsByName(_GameWidget);
    } // setupUi

    void retranslateUi(QWidget *_GameWidget)
    {
        _GameWidget->setWindowTitle(QApplication::translate("_GameWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class _GameWidget: public Ui__GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
