#include "ecgwavewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EcgWaveWidget w;
    w.show();
    return a.exec();
}
