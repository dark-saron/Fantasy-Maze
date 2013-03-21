/********************************************************************************
** Form generated from reading UI file 'MenuWidget.ui'
**
** Created: Thu 14. Mar 20:59:47 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWIDGET_H
#define UI_MENUWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *_singleStartBtn;
    QPushButton *_multiStartBtn;
    QPushButton *_loadBtn;
    QPushButton *_endBtn;

    void setupUi(QWidget *MenuWidget)
    {
        if (MenuWidget->objectName().isEmpty())
            MenuWidget->setObjectName(QString::fromUtf8("MenuWidget"));
        MenuWidget->resize(260, 500);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MenuWidget->sizePolicy().hasHeightForWidth());
        MenuWidget->setSizePolicy(sizePolicy);
        MenuWidget->setMinimumSize(QSize(260, 500));
        MenuWidget->setMaximumSize(QSize(260, 500));
        MenuWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        MenuWidget->setInputMethodHints(Qt::ImhNone);
        verticalLayoutWidget = new QWidget(MenuWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 261, 501));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout->setContentsMargins(20, 10, 20, 20);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        _singleStartBtn = new QPushButton(verticalLayoutWidget);
        _singleStartBtn->setObjectName(QString::fromUtf8("_singleStartBtn"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        _singleStartBtn->setFont(font1);
        _singleStartBtn->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(_singleStartBtn);

        _multiStartBtn = new QPushButton(verticalLayoutWidget);
        _multiStartBtn->setObjectName(QString::fromUtf8("_multiStartBtn"));
        _multiStartBtn->setEnabled(true);
        sizePolicy1.setHeightForWidth(_multiStartBtn->sizePolicy().hasHeightForWidth());
        _multiStartBtn->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        _multiStartBtn->setFont(font2);
        _multiStartBtn->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(_multiStartBtn);

        _loadBtn = new QPushButton(verticalLayoutWidget);
        _loadBtn->setObjectName(QString::fromUtf8("_loadBtn"));
        _loadBtn->setFont(font1);
        _loadBtn->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(_loadBtn);

        _endBtn = new QPushButton(verticalLayoutWidget);
        _endBtn->setObjectName(QString::fromUtf8("_endBtn"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(true);
        _endBtn->setFont(font3);
        _endBtn->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(_endBtn);


        retranslateUi(MenuWidget);

        QMetaObject::connectSlotsByName(MenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MenuWidget)
    {
        MenuWidget->setWindowTitle(QString());
        label->setText(QApplication::translate("MenuWidget", "Menu Fantasy Maze", 0, QApplication::UnicodeUTF8));
        _singleStartBtn->setText(QApplication::translate("MenuWidget", "Start Singleplayer", 0, QApplication::UnicodeUTF8));
        _multiStartBtn->setText(QApplication::translate("MenuWidget", "Start Multiplayer", 0, QApplication::UnicodeUTF8));
        _loadBtn->setText(QApplication::translate("MenuWidget", "Load", 0, QApplication::UnicodeUTF8));
        _endBtn->setText(QApplication::translate("MenuWidget", "End Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuWidget: public Ui_MenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGET_H
