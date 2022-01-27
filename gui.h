#ifndef GUI_H
#define GUI_H
#include <QWidget>
#include "ui_gui.h"
#include "gpio.h"
#include <QTimer>

const int TIMEOUT = 1000;

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);

private slots:
    void on_speedSlider_valueChanged(int value);
    void on_blinkButton_clicked();
    void on_lauflichtButton_clicked();
    void toggle();
private:
    QTimer* m_timer;
    bool m_state = 0;
    bool auswahl = 0;
    unsigned int zaehler = 1;
    Gpio* m_leds;
};

#endif // GUI_H
