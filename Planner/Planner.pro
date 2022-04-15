QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addgradedialog.cpp \
    agendaadding.cpp \
    agendamain.cpp \
    calendar.cpp \
    calendarmain.cpp \
    clock.cpp \
    editdeletemarkasdomedialog.cpp \
    editordeletedialog.cpp \
    gradesadding.cpp \
    gradesmain.cpp \
    main.cpp \
    overviewmain.cpp \
    settingsmain.cpp \
    subjectadding.cpp \
    subjectsmain.cpp \
    teacheradding.cpp \
    teachermain.cpp \
    timetableitemsadding.cpp \
    timetablemain.cpp \
    welcomemain.cpp \
    windowsmanager.cpp

HEADERS += \
    addgradedialog.h \
    agendaadding.h \
    agendamain.h \
    calendar.h \
    calendarmain.h \
    clock.h \
    editdeletemarkasdomedialog.h \
    editordeletedialog.h \
    gradesadding.h \
    gradesmain.h \
    overviewmain.h \
    settingsmain.h \
    subjectadding.h \
    subjectsmain.h \
    teacheradding.h \
    teachermain.h \
    timetableitemsadding.h \
    timetablemain.h \
    welcomemain.h \
    windowsmanager.h

FORMS += \
    addgradedialog.ui \
    agendaadding.ui \
    agendamain.ui \
    calendar.ui \
    calendarmain.ui \
    clock.ui \
    editdeletemarkasdomedialog.ui \
    editordeletedialog.ui \
    gradesadding.ui \
    gradesmain.ui \
    overviewmain.ui \
    settingsmain.ui \
    subjectadding.ui \
    subjectsmain.ui \
    teacheradding.ui \
    teachermain.ui \
    timetableitemsadding.ui \
    timetablemain.ui \
    welcomemain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
