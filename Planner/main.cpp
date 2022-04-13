#include "timetablemain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimetableMain w;
    w.show();
    return a.exec();
}
