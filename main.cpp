#include "mifaregui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MifareGUI w;
    w.show();

    return a.exec();
}
