#include "teachermain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TeacherMain w;
    w.show();
    return a.exec();
}
