#include "action.h"

Action::Action(QWidget *parent) : QWidget(parent)
{
    m_newWindow = new QAction(tr("New window"));
    m_newWindow->setShortcut(QKeySequence("CTRL+ALT+W"));

    m_openFile = new QAction(tr("Open file"));
    m_openFile->setShortcut(QKeySequence("CTRL+ALT+O"));

    m_saveFile = new QAction(tr("Save file"));
    m_saveFile->setShortcut(QKeySequence("CTRL+S"));

    m_leaveApp = new QAction(tr("Leave application"));
    m_leaveApp->setShortcut(QKeySequence("CTRL+Q"));
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

QAction *Action::leaveApp()
{
    return m_leaveApp;
}
