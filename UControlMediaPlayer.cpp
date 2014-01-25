#include "UControlMediaPlayer.h"

/// PUBLIC
UControlMediaPlayer::UControlMediaPlayer(QWidget *parent)
    : QWidget(parent)
{        
    tButtonStartPause.setAutoRaise(true);
    tButtonStop.setAutoRaise(true);
    tButtonBack.setAutoRaise(true);
    tButtonNext.setAutoRaise(true);
    tButtonSoundOn.setAutoRaise(true);
    tButtonVolumeDown.setAutoRaise(true);
    tButtonVolumeUp.setAutoRaise(true);
    tButtonQuit.setAutoRaise(true);

    tButtonVolumeDown.setAutoRepeat(true);
    tButtonVolumeUp.setAutoRepeat(true);

    tButtonStartPause.setIcon(QIcon(":/IconPlayPause"));
    tButtonStop.setIcon(QIcon(":/IconStop"));
    tButtonBack.setIcon(QIcon(":/IconBack"));
    tButtonNext.setIcon(QIcon(":/IconNext"));
    tButtonSoundOn.setIcon(QIcon(":/IconSound"));
    tButtonVolumeDown.setIcon(QIcon(":/IconVolumeDown"));
    tButtonVolumeUp.setIcon(QIcon(":/IconVolumeUp"));
    tButtonQuit.setIcon(QIcon(":/IconQuit"));


    tButtonStartPause.setToolTip("Старт/пауза");
    tButtonStop.setToolTip("Стоп");
    tButtonBack.setToolTip("Предыдущий");
    tButtonNext.setToolTip("Следующий");
    tButtonSoundOn.setToolTip("Включить/выключить звук");
    tButtonVolumeDown.setToolTip("Понизить громкость");
    tButtonVolumeUp.setToolTip("Прибавить громкость");
    tButtonQuit.setToolTip("Выйти");


    QHBoxLayout *hBox = new QHBoxLayout();
    hBox->setMargin(0);
    hBox->setSpacing(0);
    hBox->addWidget(&tButtonStartPause);
    hBox->addWidget(&tButtonStop);
    hBox->addSpacing(10);
    hBox->addWidget(&tButtonBack);
    hBox->addWidget(&tButtonNext);
    hBox->addSpacing(10);
    hBox->addWidget(&tButtonSoundOn);
    hBox->addWidget(&tButtonVolumeDown);
    hBox->addWidget(&tButtonVolumeUp);
    hBox->addSpacing(10);
    hBox->addWidget(&tButtonQuit);
    hBox->addStretch();

    setLayout(hBox);


    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(&tButtonStartPause, Key_Media_Play_Pause);
    buttonGroup->addButton(&tButtonStop,       Key_Media_Stop);
    buttonGroup->addButton(&tButtonBack,       Key_Media_Back);
    buttonGroup->addButton(&tButtonNext,       Key_Media_Next);
    buttonGroup->addButton(&tButtonSoundOn,    Key_Media_Mute);
    buttonGroup->addButton(&tButtonVolumeDown, Key_Media_VolumeDown);
    buttonGroup->addButton(&tButtonVolumeUp,   Key_Media_VolumeUp);

    connect(buttonGroup, SIGNAL(buttonClicked(int)), SLOT(emitClickedKey(int)));

    connect(&tButtonQuit, SIGNAL(clicked()), SLOT(close()));

    setVisibleButtonQuit(false);
}
void UControlMediaPlayer::setVisibleButtonQuit(bool visible)
{
    tButtonQuit.setVisible(visible);
}

/// PRIVATE SLOTS
void UControlMediaPlayer::emitClickedKey(int key)
{
    // Моделируем нажатие клавиши
    keybd_event(key, 0, 0, 0);

    // Моделируем возврат клавиши в не нажатое состояние
    keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
}

/// PROTECTED
void UControlMediaPlayer::closeEvent(QCloseEvent *)
{
    emit iClose();
}

///// Демонстрационный пример
//#include <windows.h>

//void SetNumLock( BOOL bState )
//{
//    BYTE keyState[256];
//    GetKeyboardState((LPBYTE)&keyState);
//    if( (bState && !(keyState[VK_NUMLOCK] & 1))
//            ||  (!bState && (keyState[VK_NUMLOCK] & 1)) )
//    {
//        // Моделируем нажатие клавиши
//        keybd_event( VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
//        // Моделируем возврат клавиши в не нажатое состояние
//        keybd_event( VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
//    }
//}
//void main()
//{
//    SetNumLock( TRUE );
//}
