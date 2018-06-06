#include "file.h"

File::File(const QString &fileName, QWidget *parent) : QWidget(parent)
{   
    m_file = new QFile(fileName);
}

File::File(QWidget *parent) : QWidget(parent)
{
    m_file = 0;
}

QString File::readFile()
{
    if (!m_file->open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this, tr("Warning"), tr("File cannot be opened"));
        return "";
    }

    const QByteArray byte = m_file->readAll();
    const QString text(byte);
    m_file->close();

    return text;
}
