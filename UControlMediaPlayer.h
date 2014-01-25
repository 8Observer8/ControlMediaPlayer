#ifndef UCONTROLMEDIAPLAYER_H
#define UCONTROLMEDIAPLAYER_H

#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>
#include <QButtonGroup>

#include <QDebug>

#include <windows.h>

#define Key_Media_Play_Pause 0xB3
#define Key_Media_Stop       0xB2
#define Key_Media_Back       0xB1
#define Key_Media_Next       0xB0
#define Key_Media_Mute       0xAD
#define Key_Media_Sound      0xFA
#define Key_Media_VolumeUp   0xAF
#define Key_Media_VolumeDown 0xAE

class UControlMediaPlayer: public QWidget
{
    Q_OBJECT
    
public:
    UControlMediaPlayer(QWidget *parent = 0);
    void setVisibleButtonQuit(bool visible);

private:
    QToolButton tButtonStartPause;
    QToolButton tButtonStop;
    QToolButton tButtonNext;
    QToolButton tButtonBack;
    QToolButton tButtonSoundOn;
    QToolButton tButtonVolumeUp;
    QToolButton tButtonVolumeDown;
    QToolButton tButtonQuit;

private slots:
    void emitClickedKey(int key);

signals:
    void iClose();

protected:
    void closeEvent(QCloseEvent *);
};

#endif // UCONTROLMEDIAPLAYER_H
