#include "file.h"

File::File(const QString &fileName, QWidget *parent) : QWidget(parent)
{   
    m_file = new QFile(fileName);
    emit privateFileChanged(fileName);
}

File::File(QWidget *parent) : QWidget(parent)
{
    m_file = 0;
    m_fileInfo = 0;
    emit onPrivateFileChanged("");
}

QString File::readFile()
{
    const QString fileName = QFileDialog::getOpenFileName(parentWidget());
    m_file = new QFile(fileName);
    emit onPrivateFileChanged(fileName);

    if (!m_file->open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(parentWidget(), tr("Warning"), tr("File can not be opened"));
        return "";
    }

    const QByteArray bytes = m_file->readAll();
    const QString text = getUtf8(bytes);

    emit messageStatus(tr("File opened"));
    return text;
}

void File::writeFile(const QString &text)
{
    if (m_file == 0)
    {
        writeFileAs(text);
        return;
    }

    if (!m_file->open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(parentWidget(), tr("Warning"), tr("File can not be saved"));
        return;
    }

    writeBytes(text.toUtf8());
}

void File::writeFileAs(const QString &text)
{
    const QString fileName = QFileDialog::getSaveFileName(parentWidget());
    m_file = new QFile(fileName);
    emit onPrivateFileChanged(fileName);

    if (!m_file->open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(parentWidget(), tr("Warning"), tr("File can not be saved"));
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

QString File::getUtf8(const QByteArray &bytes)
{
    QTextCodec::ConverterState state;
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    const QString text = codec->toUnicode(bytes.constData(), bytes.size(), &state);
    m_file->close();

    if (state.invalidChars > 0)
    {
        QMessageBox::warning(parentWidget(), tr("Warning"), tr("File is not in UTF-8 and cannot be opened"));
        m_file = 0;
        emit onPrivateFileChanged("");
        return "";
    }

    return text;
}

void File::onPrivateFileChanged(const QString &fileName)
{
    const QFile file(fileName);
    m_fileInfo = new QFileInfo(file);

    emit fileNameChanged(m_fileInfo->fileName());
}
