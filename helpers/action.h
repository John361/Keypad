#ifndef ACTION_H
#define ACTION_H

#include <QAction>

class Action : public QWidget
{
    Q_OBJECT

    public:
        Action(QWidget *parent = nullptr);

        /**
         * @brief openPalette returns m_openPalette
         * @return
         */
        QAction *openPalette();

        /**
         * @brief newWindow returns m_newWindow
         * @return
         */
        QAction *newWindow();

        /**
         * @brief openFile returns m_openFile
         * @return
         */
        QAction *openFile();

        /**
         * @brief saveFile returns m_saveFile
         * @return
         */
        QAction *saveFile();

        /**
         * @brief saveFileAs returns m_saveFileAs
         * @return
         */
        QAction *saveFileAs();

        /**
         * @brief leaveApp returns m_leaveApp
         * @return
         */
        QAction *leaveApp();

    private:
        QAction *m_newWindow;
        QAction *m_openPalette;
        QAction *m_openFile;
        QAction *m_saveFile;
        QAction *m_saveFileAs;
        QAction *m_leaveApp;
};

#endif // ACTION_H
