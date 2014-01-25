#include <QApplication>
#include <QTextCodec>

#include "UControlMediaPlayer.h"
#include "UWindowControlMediaPlayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));

//    UControlMediaPlayer w;
//    w.show();
    
    UWindowControlMediaPlayer ww;
    ww.show();

    return app.exec();
}
