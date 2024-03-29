QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agendaadding.cpp \
    agendamain.cpp \
    areyousure.cpp \
    cache.cpp \
    calendar.cpp \
    calendarmain.cpp \
    clock.cpp \
    color.cpp \
    currentuser.cpp \
    editdeletemarkasdomedialog.cpp \
    editordeletedialog.cpp \
    grade.cpp \
    gradesadding.cpp \
    gradesmain.cpp \
    main.cpp \
    overviewmain.cpp \
    plan.cpp \
    planinfodialog.cpp \
    settings.cpp \
    settingsmain.cpp \
    subject.cpp \
    subjectadding.cpp \
    subjectsmain.cpp \
    task.cpp \
    teacher.cpp \
    teacheradding.cpp \
    teachermain.cpp \
    timetableitemsadding.cpp \
    timetablemain.cpp \
    welcomemain.cpp \
    whattosave.cpp \
    windowsmanager.cpp

HEADERS += \
    agendaadding.h \
    agendamain.h \
    areyousure.h \
    cache.h \
    calendar.h \
    calendarmain.h \
    clock.h \
    color.h \
    currentuser.h \
    editdeletemarkasdomedialog.h \
    editordeletedialog.h \
    grade.h \
    gradesadding.h \
    gradesmain.h \
    overviewmain.h \
    plan.h \
    planinfodialog.h \
    settings.h \
    settingsmain.h \
    subject.h \
    subjectadding.h \
    subjectsmain.h \
    task.h \
    teacher.h \
    teacheradding.h \
    teachermain.h \
    timetableitemsadding.h \
    timetablemain.h \
    welcomemain.h \
    whattosave.h \
    windowsmanager.h

FORMS += \
    agendaadding.ui \
    agendamain.ui \
    areyousure.ui \
    calendar.ui \
    calendarmain.ui \
    clock.ui \
    editdeletemarkasdomedialog.ui \
    editordeletedialog.ui \
    gradesadding.ui \
    gradesmain.ui \
    overviewmain.ui \
    planinfodialog.ui \
    settingsmain.ui \
    subjectadding.ui \
    subjectsmain.ui \
    teacheradding.ui \
    teachermain.ui \
    timetableitemsadding.ui \
    timetablemain.ui \
    welcomemain.ui \
    whattosave.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
