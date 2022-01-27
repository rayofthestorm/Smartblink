#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_leds = new Gpio(this);
    m_state = 0;
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle); // verbindung Timer -> Gui Label
    m_timer->start(TIMEOUT);
}

void Gui::on_speedSlider_valueChanged(int value)
{
    m_timer->start(1000/value); //SpeedSlider Einstellungen
}

void Gui::on_blinkButton_clicked()
{
    auswahl = 0; //Variable fuer if-Abfrage
}

void Gui::on_lauflichtButton_clicked()
{
    auswahl = 1;
    zaehler = 1;
}
void Gui::toggle()
{
    m_state = !m_state;
    if(auswahl == 0)    //Blinken
    {
        if(m_state == 1)
          zaehler = 15;
          else
          zaehler = 0;

      m_leds->set(zaehler);
    }
    if(auswahl == 1)    //Laufliht
    {
        m_leds->set(zaehler);
          if(zaehler < 8)
           zaehler = zaehler * 2;
           else
           zaehler = 1;


    }
}
