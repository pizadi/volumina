QT  += core gui
QT  += network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addpenaltydialog.cpp \
    addtransaction.cpp \
    connectdialog.cpp \
    editaccountdialog.cpp \
    helpdialog.cpp \
    helplibdialog.cpp \
    lendbook.cpp \
    lenddialog.cpp \
    librarianwindow.cpp \
    libsearchview.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    memberviewdialog.cpp \
    renewbookdialog.cpp \
    renewmemberdialog.cpp \
    searchview.cpp \
    serverconnection.cpp

HEADERS += \
    addpenaltydialog.h \
    addtransaction.h \
    connectdialog.h \
    editaccountdialog.h \
    helpdialog.h \
    helplibdialog.h \
    lendbook.h \
    lenddialog.h \
    librarianwindow.h \
    libsearchview.h \
    logindialog.h \
    mainwindow.h \
    memberviewdialog.h \
    renewbookdialog.h \
    renewmemberdialog.h \
    searchview.h \
    serverconnection.h

FORMS += \
    addpenaltydialog.ui \
    addtransaction.ui \
    connectdialog.ui \
    editaccountdialog.ui \
    helpdialog.ui \
    helplibdialog.ui \
    lendbook.ui \
    lenddialog.ui \
    librarianwindow.ui \
    libsearchview.ui \
    logindialog.ui \
    mainwindow.ui \
    memberviewdialog.ui \
    renewbookdialog.ui \
    renewmemberdialog.ui \
    searchview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
