#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextStream>

#include "helpers/action.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);

    private:
        Action *m_action;
        QTextEdit *m_editor;
        QTextStream *m_textStream;

    signals:
        //void textStreamChanged();

    public slots:
        void openFile();

    private slots:
        /**
         * @brief openNewWindow
         */
        void openNewWindow();
};

#endif // MAINWINDOW_H
