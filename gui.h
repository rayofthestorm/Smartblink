#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include "gpio.h"
#include <QTimer>

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

    void on_BlinkLable_linkActivated(const QString &link);

private:
    QTimer* m_timer;
    bool m_status;
    Gpio* m_leds;

};

#endif // GUI_H
