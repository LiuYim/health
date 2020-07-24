#ifndef ECGWAVEWIDGET_H
#define ECGWAVEWIDGET_H

#include <QWidget>
#include <QPixmap>

class EcgWaveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EcgWaveWidget(QWidget *parent = nullptr);
public:
    void refreshPixmap();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    QPixmap *pix_;
    int index_;          // x
    int ecgDataIndex_;   // y：取数组数据的索引
signals:

};

#endif // ECGWAVEWIDGET_H
