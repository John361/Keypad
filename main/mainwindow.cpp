#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_action = new Action(this);
    m_editor = new QTextEdit;
    m_textStream = 0;

    addAction(m_action->newWindow());
    addAction(m_action->openFile());

    connect(m_action->newWindow(), SIGNAL(triggered(bool)), this, SLOT(openNewWindow()));
    connect(m_action->openFile(), SIGNAL(triggered(bool)), this, SLOT(openFile()));

    setCentralWidget(m_editor);
}

void MainWindow::openFile()
{
    const QString fileName = QFileDialog::getOpenFileName(this);
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("Warning"), tr("The file cannot be opened"));
        return;
    }

    m_textStream = new QTextStream(&file);
    m_editor->setText(m_textStream->readAll());
    file.close();
}

void MainWindow::openNewWindow()
{
    MainWindow *mw = new MainWindow;
    mw->show();
}
