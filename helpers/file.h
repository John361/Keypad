#ifndef FILE_H
#define FILE_H

#include <QByteArray>
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

        void writeFile(const QString &text);

    private:
        QFile *m_file;

    signals:
        /**
         * @brief readOnly allows to know that text cannot be saved at the same place
         */
        void readOnly();

        /**
         * @brief saveStatus is emit when the file is saved
         */
        void saveStatus(QTextStream::Status);
};

#endif // FILE_H
