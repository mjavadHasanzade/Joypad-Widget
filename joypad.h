#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>

class QPropertyAnimation;
class QParallelAnimationGroup;

class JoyPad : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(float x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(float y READ y WRITE setY NOTIFY yChanged)
public:
    explicit JoyPad(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

    float x() const;
    float y() const;
    void mouseReleaseEvent(QMouseEvent *event) override;

    bool getIsJoyPadActive() const;

signals:
    void xChanged(float value);
    void yChanged(float value);
    void joyActivationChanged(bool active);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

public slots:
    void setX(float value);
    void setY(float value);
    void setJoyPadActive(bool value);

    // Add or remove the knob return animations in x or y- direction.
    void removeXAnimation();
    void addXAnimation();

    void removeYAnimation();
    void addYAnimation();

    /*  Set the alignment of the quadratic content if the widgets geometry isn quadratic.
     *  Flags can be combined eg. setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    */
    void setAlignment(Qt::Alignment f);


private:
    float m_x;
    float m_y;
    bool isJoyPadActive = false;

    QParallelAnimationGroup *m_returnAnimation;
    QPropertyAnimation *m_xAnimation;
    QPropertyAnimation *m_yAnimation;

    QRectF m_bounds;
    QRectF m_knopBounds;

    QPoint m_lastPos;
    bool knopPressed;

    Qt::Alignment m_alignment;

protected:

    bool focusNextPrevChild(bool next) override {
        return QWidget::focusNextPrevChild(next);
    }

    void focusInEvent(QFocusEvent *event) override {
        QWidget::focusInEvent(event);
    }

    void focusOutEvent(QFocusEvent *event) override {
        QWidget::focusOutEvent(event);
    }
};
