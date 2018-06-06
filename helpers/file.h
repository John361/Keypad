#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QMessageBox>
#include <QTextStream>
#include <QWidget>

class File : public QWidget
{
    Q_OBJECT

    public:
        File(const QString &fileName, QWidget *parent = nullptr);
        File(QWidget *parent = nullptr);

        /**
         * @brief readFile reads all lines from the file
         * @return
         */
        QString readFile();

    private:
        QFile *m_file;

    signals:
        /**
         * @brief readOnly allows to know that text cannot be saved at the same place
         */
        void readOnly();
};

#endif // FILE_H
