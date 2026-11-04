#include "lcdwidget.h"
#include "core/keypad.h"
#include "qtkeypadbridge.h"
#include "qmlbridge.h"
#include "qtframebuffer.h"

LCDWidget::LCDWidget(QWidget *parent, Qt::WindowFlags f)
    : QWidget(parent, f)
{
    setMinimumSize(320, 240);
    // Hovering over the screen acts like a finger sliding on the touchpad,
    // so the mouse drives the calc cursor without pressing anything.
    setMouseTracking(true);

    connect(&refresh_timer, SIGNAL(timeout()), this, SLOT(update()));

    refresh_timer.setInterval(1000 / 30); // 30 fps
}

void LCDWidget::mousePressEvent(QMouseEvent *event)
{
    the_qml_bridge->setTouchpadState((qreal)event->x() / width(), (qreal)event->y() / height(), true, event->button() == Qt::RightButton);
}

void LCDWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
        keypad.touchpad_down = keypad.touchpad_contact = false;
    else
        keypad.touchpad_contact = false;

    the_qml_bridge->touchpadStateChanged();
    keypad.kpc.gpio_int_active |= 0x800;
    keypad_int_check();
}

void LCDWidget::mouseMoveEvent(QMouseEvent *event)
{
    the_qml_bridge->setTouchpadState((qreal)event->x() / width(), (qreal)event->y() / height(), true, keypad.touchpad_down);
}

void LCDWidget::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    keypad.touchpad_down = keypad.touchpad_contact = false;
    the_qml_bridge->touchpadStateChanged();
    keypad.kpc.gpio_int_active |= 0x800;
    keypad_int_check();
}

void LCDWidget::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);

    refresh_timer.start();
}

void LCDWidget::hideEvent(QHideEvent *e)
{
    QWidget::hideEvent(e);

    refresh_timer.stop();
}

void LCDWidget::closeEvent(QCloseEvent *e)
{
    QWidget::closeEvent(e);

    emit closed();
}

void LCDWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    paintFramebuffer(&painter);
}
