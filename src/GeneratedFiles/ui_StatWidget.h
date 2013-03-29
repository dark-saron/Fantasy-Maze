/********************************************************************************
** Form generated from reading UI file 'StatWidget.ui'
**
** Created: Fri 29. Mar 14:55:55 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATWIDGET_H
#define UI_STATWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *_nameLabel;
    QProgressBar *_healthBar;
    QProgressBar *_manaBar;
    QLabel *_levelLabel;
    QProgressBar *_levelBar;
    QLabel *_atkLabel;
    QLabel *_defLabel;
    QLabel *_inventurInformation;
    QGridLayout *_inventoryGrid;

    void setupUi(QWidget *StatWidget)
    {
        if (StatWidget->objectName().isEmpty())
            StatWidget->setObjectName(QString::fromUtf8("StatWidget"));
        StatWidget->resize(489, 500);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(32);
        sizePolicy.setVerticalStretch(32);
        sizePolicy.setHeightForWidth(StatWidget->sizePolicy().hasHeightForWidth());
        StatWidget->setSizePolicy(sizePolicy);
        StatWidget->setMinimumSize(QSize(300, 500));
        verticalLayoutWidget = new QWidget(StatWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 311, 501));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(20, 10, 20, 20);
        _nameLabel = new QLabel(verticalLayoutWidget);
        _nameLabel->setObjectName(QString::fromUtf8("_nameLabel"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        _nameLabel->setFont(font);
        _nameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_nameLabel);

        _healthBar = new QProgressBar(verticalLayoutWidget);
        _healthBar->setObjectName(QString::fromUtf8("_healthBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(_healthBar->sizePolicy().hasHeightForWidth());
        _healthBar->setSizePolicy(sizePolicy1);
        _healthBar->setMaximumSize(QSize(16777213, 16777215));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        _healthBar->setPalette(palette);
        _healthBar->setContextMenuPolicy(Qt::NoContextMenu);
        _healthBar->setAutoFillBackground(false);
        _healthBar->setMinimum(0);
        _healthBar->setMaximum(100);
        _healthBar->setValue(100);
        _healthBar->setAlignment(Qt::AlignCenter);
        _healthBar->setTextVisible(true);
        _healthBar->setInvertedAppearance(false);
        _healthBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(_healthBar);

        _manaBar = new QProgressBar(verticalLayoutWidget);
        _manaBar->setObjectName(QString::fromUtf8("_manaBar"));
        _manaBar->setContextMenuPolicy(Qt::NoContextMenu);
        _manaBar->setValue(100);
        _manaBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_manaBar);

        _levelLabel = new QLabel(verticalLayoutWidget);
        _levelLabel->setObjectName(QString::fromUtf8("_levelLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(_levelLabel->sizePolicy().hasHeightForWidth());
        _levelLabel->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        _levelLabel->setFont(font1);
        _levelLabel->setTextFormat(Qt::PlainText);
        _levelLabel->setScaledContents(true);
        _levelLabel->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        _levelLabel->setMargin(2);
        _levelLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(_levelLabel);

        _levelBar = new QProgressBar(verticalLayoutWidget);
        _levelBar->setObjectName(QString::fromUtf8("_levelBar"));
        sizePolicy1.setHeightForWidth(_levelBar->sizePolicy().hasHeightForWidth());
        _levelBar->setSizePolicy(sizePolicy1);
        _levelBar->setMinimumSize(QSize(100, 15));
        _levelBar->setMaximumSize(QSize(16777215, 16777215));
        _levelBar->setBaseSize(QSize(100, 15));
        _levelBar->setContextMenuPolicy(Qt::NoContextMenu);
        _levelBar->setValue(100);
        _levelBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_levelBar);

        _atkLabel = new QLabel(verticalLayoutWidget);
        _atkLabel->setObjectName(QString::fromUtf8("_atkLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(_atkLabel->sizePolicy().hasHeightForWidth());
        _atkLabel->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        _atkLabel->setFont(font2);
        _atkLabel->setTextFormat(Qt::PlainText);
        _atkLabel->setScaledContents(true);
        _atkLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        _atkLabel->setWordWrap(true);
        _atkLabel->setMargin(5);

        verticalLayout->addWidget(_atkLabel);

        _defLabel = new QLabel(verticalLayoutWidget);
        _defLabel->setObjectName(QString::fromUtf8("_defLabel"));
        sizePolicy3.setHeightForWidth(_defLabel->sizePolicy().hasHeightForWidth());
        _defLabel->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(10);
        _defLabel->setFont(font3);
        _defLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        _defLabel->setMargin(5);

        verticalLayout->addWidget(_defLabel);

        _inventurInformation = new QLabel(verticalLayoutWidget);
        _inventurInformation->setObjectName(QString::fromUtf8("_inventurInformation"));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        _inventurInformation->setFont(font4);
        _inventurInformation->setScaledContents(false);
        _inventurInformation->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_inventurInformation);

        _inventoryGrid = new QGridLayout();
        _inventoryGrid->setSpacing(3);
        _inventoryGrid->setObjectName(QString::fromUtf8("_inventoryGrid"));
        _inventoryGrid->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout->addLayout(_inventoryGrid);


        retranslateUi(StatWidget);

        QMetaObject::connectSlotsByName(StatWidget);
    } // setupUi

    void retranslateUi(QWidget *StatWidget)
    {
        StatWidget->setWindowTitle(QApplication::translate("StatWidget", "Form", 0, QApplication::UnicodeUTF8));
        _nameLabel->setText(QApplication::translate("StatWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        _healthBar->setFormat(QApplication::translate("StatWidget", "Health %v / %m", 0, QApplication::UnicodeUTF8));
        _manaBar->setFormat(QApplication::translate("StatWidget", "Mana %v / %m", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        _levelLabel->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        _levelLabel->setText(QApplication::translate("StatWidget", "Level", 0, QApplication::UnicodeUTF8));
        _levelBar->setFormat(QApplication::translate("StatWidget", "%v / %m", 0, QApplication::UnicodeUTF8));
        _atkLabel->setText(QApplication::translate("StatWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        _defLabel->setText(QApplication::translate("StatWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        _inventurInformation->setText(QApplication::translate("StatWidget", "Inventar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StatWidget: public Ui_StatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATWIDGET_H
