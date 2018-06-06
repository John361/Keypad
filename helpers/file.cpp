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
    if (!m_file->open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("Warning"), tr("File cannot be opened"));
        return "";
    }

    const QByteArray byte = m_file->readAll();
    const QString text(byte);
    m_file->close();

    messageStatus(tr("File opened"));
    return text;
}

void File::writeFile(const QString &text)
{
    if (m_file == 0)
    {
        QMessageBox::warning(parentWidget(), tr("Warning"), tr("No file opened"));
        return;
    }

    if (!m_file->open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(parentWidget(), tr("Warning"), tr("File cannot be saved"));
        return;
    }

    writeBytes(text.toUtf8());
}

void File::writeFileAs(const QString &fileName, const QString &text)
{
    m_file = new QFile(fileName);

    if (!m_file->open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this, tr("Warning"), tr("File cannot be saved"));
        return;
    }

    writeBytes(text.toUtf8());
}

void File::writeBytes(const QByteArray &bytes)
{
    QTextStream stream(m_file);
    stream << bytes;

    switch (stream.status())
    {
        case 0:
            emit messageStatus(tr("File saved"));
            break;

        case 3:
            emit messageStatus(tr("Data not written"));
            break;

        default:
            emit messageStatus(tr("Nothing to do"));
            break;
    }

    m_file->close();
}
