#ifndef QTKEYPADBRIDGE_H
#define QTKEYPADBRIDGE_H

#include <QKeyEvent>

/* This class is used by every Widget which wants to interact with the
 * virtual keypad. Simply call QtKeypadBridge::keyPressEvent or keyReleaseEvent
 * to relay the key events into the virtual calc. */

class QtKeypadBridge : public QObject
{
public:
    static void keyPressEvent(QKeyEvent *event);
    static void keyReleaseEvent(QKeyEvent *event);

    /* Type a string into the calc by pressing the matching keypad keys one
     * after another (used for pasting from the host clipboard).
     * Characters without a keypad key are skipped. */
    static void typeText(const QString &text);

    virtual bool eventFilter(QObject *obj, QEvent *event);
};

extern QtKeypadBridge qt_keypad_bridge;

#endif // QTKEYPADBRIDGE_H
