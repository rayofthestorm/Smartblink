#ifndef GPIO_H
#define GPIO_H

#include <QObject>

const QList<int> LEDS = {18, 23, 24, 25};
const int LFLAGS = 0;
const int CHIP = 0;

class Gpio : public QObject
{
    Q_OBJECT
public:
    explicit Gpio(QObject *parent = nullptr);
    ~ Gpio(); //Destructor
    void set(int pin, int state);

signals:

public slots:

private:
    int m_handel;
};
#endif // GPIO_H
