#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QStatusBar>
#include <QTextEdit>

#include "helpers/action.h"
#include "helpers/file.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);

    private:
        Action *m_action;
        File *m_file;
        QStatusBar *m_statusBar;
        QTextEdit *m_editor;

        /**
         * @brief actionAndConnection adds action to the MainWindow and connects signals and slots
         */
        void actionAndConnection();

    signals:

    public slots:
        /**
         * @brief openFile opens a file and writes text in the editor
         */
        void openFile();

        /**
         * @brief saveFile saves text from the editor in the file
         */
        void saveFile();

        /**
         * @brief saveFileAs saves text from the editor to a choosing file
         */
        void saveFileAs();

    private slots:
        /**
         * @brief openNewWindow opens a new MainWindow
         */
        void openNewWindow();

        void changeFileStatus(const QString &status);
};

#endif // MAINWINDOW_H
