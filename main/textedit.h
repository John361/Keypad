#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QAbstractTextDocumentLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QRectF>
#include <QScrollBar>
#include <QTextBlock>
#include <QTextEdit>

#include "helpers/linenumberarea.h"

class TextEdit : public QTextEdit {
    Q_OBJECT

    public:
        TextEdit(QWidget *parent = nullptr);

        int getFirstVisibleBlockId();
        void lineNumberAreaPaintEvent(QPaintEvent *event);
        int lineNumberAreaWidth();

    protected:
        void resizeEvent(QResizeEvent *e) override;

    private slots:
        void updateLineNumberAreaWidth(int newBlockCount);
        void updateLineNumberArea(QRectF /*rect_f*/);
        void updateLineNumberArea(int /*slider_pos*/);
        void updateLineNumberArea();

    private:
        LineNumberArea *m_lineNumberArea;
};


#endif // TEXTEDIT_H
