#ifndef UWINDOWCONTROLMEDIAPLAYER_H
#define UWINDOWCONTROLMEDIAPLAYER_H

#include <QWidget>
#include <QMouseEvent>
#include <QRect>
#include <QPainter>

#include "UControlMediaPlayer.h"

class UWindowControlMediaPlayer: public QWidget
{
public:
    UWindowControlMediaPlayer();

private:
    QPoint lastPos;
    bool press;

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // UWINDOWCONTROLMEDIAPLAYER_H
