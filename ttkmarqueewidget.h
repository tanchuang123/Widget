#ifndef TTKMARQUEEWIDGET_H
#define TTKMARQUEEWIDGET_H



#include <QWidget>


class  TTKMarqueeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TTKMarqueeWidget(QWidget *parent = 0);

    void setText(const QString &newText);
    inline QString text() const { return m_myText.trimmed(); }

    QSize sizeHint() const;

protected:
    virtual void paintEvent(QPaintEvent *event) override;//override是指派生类重写基类的虚函数
    virtual void showEvent(QShowEvent *event) override;
    virtual void hideEvent(QHideEvent *event) override;
    virtual void timerEvent(QTimerEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    QString m_myText;
    int m_offset, m_myTimerId;

};

#endif // TTKMARQUEEWIDGET_H
