#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include <QPaintEvent>
#include <QSize>
#include <QWidget>


class TextEdit;


class LineNumberArea : public QWidget {
    public:
        LineNumberArea(TextEdit *editor);
        QSize sizeHint() const override;

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        TextEdit *m_codeEditor;
};

#endif // LINENUMBERAREA_H
