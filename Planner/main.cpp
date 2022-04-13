#include "subjectsmain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SubjectsMain w;
    w.show();
    return a.exec();
}
