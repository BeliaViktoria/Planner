QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agendaadding.cpp \
    agendamain.cpp \
    calendar.cpp \
    clock.cpp \
    main.cpp \
    subjectadding.cpp \
    subjectsmain.cpp \
    teacheradding.cpp \
    teachermain.cpp \
    timetableitemsadding.cpp \
    timetablemain.cpp

HEADERS += \
    agendaadding.h \
    agendamain.h \
    calendar.h \
    clock.h \
    subjectadding.h \
    subjectsmain.h \
    teacheradding.h \
    teachermain.h \
    timetableitemsadding.h \
    timetablemain.h

FORMS += \
    agendaadding.ui \
    agendamain.ui \
    calendar.ui \
    clock.ui \
    subjectadding.ui \
    subjectsmain.ui \
    teacheradding.ui \
    teachermain.ui \
    timetableitemsadding.ui \
    timetablemain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
