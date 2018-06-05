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
        QFile *m_file;
        QTextEdit *m_editor;

    signals:

    public slots:
        /**
         * @brief openFile opens a file and writes text in the editor
         */
        void openFile();

        /**
         * @brief saveFile save text from the editor in the file
         */
        void saveFile();

    private slots:
        /**
         * @brief openNewWindow opens a new MainWindow
         */
        void openNewWindow();
};

#endif // MAINWINDOW_H
