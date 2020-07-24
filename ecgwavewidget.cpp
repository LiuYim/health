#include "ecgwavewidget.h"
#include <QTimer>
#include <QPainter>
#include <QColor>

EcgWaveWidget::EcgWaveWidget(QWidget *parent) : QWidget(parent)
{
    pix_ = new QPixmap(this->width(), this->height());
    pix_->fill(Qt::black);

    // 创建和启动定时器
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this,  &EcgWaveWidget::refreshPixmap);
    timer->start(10);
}
int ecgWave[] = {
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
       2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
       2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
       2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
       2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
       1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
       2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
       2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
       1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
       2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
       2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
       2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
       2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
       2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
       2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
       2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
       2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000};

void EcgWaveWidget::refreshPixmap()
{
    // 1.将波形画到pixmap上
    // 1.1 定义painter
    QPainter painter(pix_);
    painter.setPen(QPen(QColor(0,255,0), 2));

    // 1.2擦除当前列
    painter.save();
    painter.setPen(Qt::black);
    painter.drawLine(index_, 0, index_,  pix_->height());
    painter.drawLine(index_+1, 0, index_+1,  pix_->height());
    painter.drawLine(index_+2, 0, index_+2,  pix_->height());
    painter.drawLine(index_+3, 0, index_+3,  pix_->height());
    painter.drawLine(index_+4, 0, index_+4,  pix_->height());
    painter.drawLine(index_+5, 0, index_+5,  pix_->height());
    painter.drawLine(index_+6, 0, index_+6,  pix_->height());
    painter.restore();

    // 1.3更新绘图参数，水平方向循环绘图
    index_ = index_ + 2;
    if (index_ > pix_->width())
    {
        index_ = 2;
    }

    QPoint lineStart;
    QPoint lineEnd;
    // 设置起始、结束的x坐标
    lineStart.setX(index_-2);
    lineEnd.setX(index_);

    // 设置起始点、结束点y坐标
    // 起始点的y值：
    lineStart.setY(round((double)pix_->height()/2 - (((double)ecgWave[ecgDataIndex_] - 2048)/600 * pix_->height()/2)));

    // 更新参数循环取数
    ecgDataIndex_ += 10;
    if (ecgDataIndex_ >= sizeof(ecgWave)/sizeof(int))
    {
        ecgDataIndex_ = 0;
    }

    // 设置结束点的y值
    lineEnd.setY(round((double)pix_->height()/2 - (((double)ecgWave[ecgDataIndex_] - 2048)/600 * pix_->height()/2)));

    // 1.4 绘制直线
    painter.drawLine(lineStart, lineEnd);

    // 2. 更新
    this->update();

}

// 重绘事件
void EcgWaveWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, pix_->width(), pix_->height(), *pix_);
}

void EcgWaveWidget::resizeEvent(QResizeEvent *event)
{
    *pix_ = pix_->scaled(this->size());
    pix_->fill(Qt::black);
    index_ = 0;          // x
    ecgDataIndex_ = 0;   // y：取数组数据的索引
}