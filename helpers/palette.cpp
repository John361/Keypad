#include "palette.h"

Palette::Palette(QStringListModel *model, QWidget *parent)
{
    m_comboBox = new QComboBox(parent);
    m_comboBox->setModel(model);
    m_comboBox->setEditable(true);

    m_completer = new QCompleter(model);
}

