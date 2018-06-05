#ifndef MENUFILE_H
#define MENUFILE_H

#include <QMenu>

class MenuFile : public QMenu
{
    public:
        MenuFile(const QString &title, QWidget *parent = nullptr);
};

#endif // MENUFILE_H
