#ifndef PALETTE_H
#define PALETTE_H

#include <QComboBox>
#include <QCompleter>
#include <QStringListModel>


class Palette : QWidget {
    public:
        Palette(QStringListModel *model, QWidget *parent = nullptr);

    private:
        QComboBox *m_comboBox;
        QCompleter *m_completer;
};

#endif // PALETTE_H
