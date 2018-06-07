#ifndef FILE_H
#define FILE_H

#include <QByteArray>
#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QMessageBox>
#include <QTextCodec>
#include <QTextStream>
#include <QWidget>

class File : public QWidget
{
    Q_OBJECT

    public:
        File(const QString &fileName, QWidget *parent = nullptr);
        File(QWidget *parent = nullptr);

        /**
         * @brief readFile reads all lines from an UTF-8 file given by QFileDialog
         * @return
         */
        QString readFile();

        /**
         * @brief writeFile writes text in the same file if readFile() was called before else calls writeFileAs(const QString&)
         * @param text
         */
        void writeFile(const QString &text);

        /**
         * @brief writeFileAs saves all text in an other file
         * @param text
         */
        void writeFileAs(const QString &text);

    private:
        QFile *m_file;

        /**
         * @brief writeBytes writes bytes in the current file and closes it
         * @param bytes
         */
        void writeBytes(const QByteArray &bytes);

        /**
         * @brief getUtf8 converts bytes to utf8 and return the text after closes the file. File is set to 0 if its not UTF-8
         * @param bytes
         * @return empty string if it's not correct
         */
        QString getUtf8(const QByteArray &bytes);

    signals:
        /**
         * @brief readOnly allows to know that text cannot be saved at the same place
         */
        void readOnly();

        /**
         * @brief messageStatus is emit when the file is saved
         */
        void messageStatus(const QString &status);
};

#endif // FILE_H
