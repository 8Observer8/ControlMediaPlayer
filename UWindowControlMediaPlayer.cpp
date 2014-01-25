#include "UWindowControlMediaPlayer.h"

/// PUBLIC
UWindowControlMediaPlayer::UWindowControlMediaPlayer()
    : press(false)
{
    setWindowFlags(Qt::Tool
                   | Qt::FramelessWindowHint
                   | Qt::WindowStaysOnTopHint);

    setAttribute(Qt::WA_MouseTracking, true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    QVBoxLayout *vBox = new QVBoxLayout();
    vBox->setContentsMargins(4, 10, 4, 4);
    vBox->setSpacing(0);
    setLayout(vBox);

    UControlMediaPlayer *controlMediaPlayer = new UControlMediaPlayer();
    controlMediaPlayer->setVisibleButtonQuit(true);
    connect(controlMediaPlayer, SIGNAL(iClose()), SLOT(close()));

    vBox->addWidget(controlMediaPlayer);

    resize(vBox->sizeHint());
}

/// PROTECTED
void UWindowControlMediaPlayer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::gray);
    painter.drawRoundedRect(rect(), 11, 11);

    painter.setPen(QPen(Qt::black, 3));
    painter.setBrush(QColor(Qt::black));
    int indent = 6;
    painter.drawLine(indent, indent, rect().width() - indent, indent);
}
void UWindowControlMediaPlayer::mouseMoveEvent(QMouseEvent *event)
{
    if(press)
        move(event->globalPos() - lastPos);
}
void UWindowControlMediaPlayer::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        press = true;
        lastPos = event->pos();
    }
}
void UWindowControlMediaPlayer::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        Q_UNUSED(event);
        press = false;
    }
}
