#include "action.h"

Action::Action(QWidget *parent) : QWidget(parent)
{
    m_newWindow = new QAction(tr("New window"));
    m_newWindow->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_W));

    m_openFile = new QAction(tr("Open file"));
    m_openFile->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_O));

    m_saveFile = new QAction(tr("Save file"));
    m_saveFile->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));

    m_saveFileAs = new QAction(tr("Save file as"));
    m_saveFileAs->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_S));

    m_leaveApp = new QAction(tr("Leave application"));
    m_leaveApp->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
}

QAction *Action::newWindow()
{
    return m_newWindow;
}

QAction *Action::openFile()
{
    return m_openFile;
}

QAction *Action::saveFile()
{
    return m_saveFile;
}

QAction *Action::saveFileAs()
{
    return m_saveFileAs;
}

QAction *Action::leaveApp()
{
    return m_leaveApp;
}
