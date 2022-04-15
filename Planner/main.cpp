#include "gradesadding.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GradesAdding w;
    w.show();
    return a.exec();
}
