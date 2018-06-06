#ifndef FILE_H
#define FILE_H

#include <QByteArray>
#include <QFile>
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

        /**
         * @brief writeFile writes text in the same file
         * @param text
         */
        void writeFile(const QString &text);

        /**
         * @brief writeFileAs saves text in an other file
         * @param fileName
         * @param text
         */
        void writeFileAs(const QString &fileName, const QString &text);

    private:
        QFile *m_file;

        /**
         * @brief writeBytes writes bytes and closes the file
         * @param bytes
         */
        void writeBytes(const QByteArray &bytes);

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
