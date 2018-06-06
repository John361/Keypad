#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{   
    m_action = new Action(this);
    m_editor = new QTextEdit;
    m_file = new File();

    addAction(m_action->newWindow());
    addAction(m_action->openFile());
    addAction(m_action->saveFile());
    addAction(m_action->saveFileAs());
    addAction(m_action->leaveApp());

    connect(m_action->newWindow(), SIGNAL(triggered(bool)), this, SLOT(openNewWindow()));
    connect(m_action->openFile(), SIGNAL(triggered(bool)), this, SLOT(openFile()));
    connect(m_action->saveFile(), SIGNAL(triggered(bool)), this, SLOT(saveFile()));
    connect(m_action->saveFileAs(), SIGNAL(triggered(bool)), this, SLOT(saveFileAs()));
    connect(m_action->leaveApp(), SIGNAL(triggered(bool)), this, SLOT(close()));

    setCentralWidget(m_editor);
}

void MainWindow::openFile()
{
    const QString fileName = QFileDialog::getOpenFileName(this);
    m_file = new File(fileName);

    const QString text(m_file->readFile());
    m_editor->setText(text);
}

void MainWindow::openNewWindow()
{
    MainWindow *mw = new MainWindow;
    mw->show();
}

void MainWindow::saveFile()
{
    const QString text(m_editor->toPlainText());
    m_file->writeFile(text);
}

void MainWindow::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    const QString text(m_editor->toPlainText());

    m_file->writeFileAs(fileName, text);
}
