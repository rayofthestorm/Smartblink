#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_leds = new Gpio(this);

    m_timer = new QTimer(this);
    m_status = false;
    //Verbinde: Quelle(Timer aus klasse Timer) -> Zeil (Toggel-Funktion aus Klasse Gui)
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle );


}

void Gui::on_speedSlider_valueChanged(int value)
{
    if(m_timer->isActive())
            m_timer->start(1000/value);
}

void Gui::on_blinkButton_clicked()
{
    m_timer->start(1000/speedSlider->value());
}

void Gui::on_lauflichtButton_clicked()
{

}

void Gui::toggle()
{
    m_status = !m_status;
    BlinkLable->setNum(m_status);

    for(auto pin : LEDS)
    m_leds->set(pin,m_status);
}

void Gui::on_BlinkLable_linkActivated(const QString &link)
{

}
