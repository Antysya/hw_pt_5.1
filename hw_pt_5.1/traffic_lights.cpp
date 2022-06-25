#include "traffic_lights.h"
#include <iostream>
using namespace std;

Traficlight::Traficlight()
{
    current = new Red();
    cout << '\n';
}

void Traficlight::setCurrent(State* s)
{
    current = s;
}

void State::red(Traficlight* m)
{
    cout << "Красный\n";
}

void State::yellow_r(Traficlight* m)
{
    cout << "Желтый\n";
}

void State::green(Traficlight* m)
{
    cout << "Зеленый\n";
}

void State::yellow_g(Traficlight* m)
{
    cout << "Желтый\n";
}

void Traficlight::red()
{
    current->red(this);
}

void Traficlight::green()
{
    current->green(this);
}

void Traficlight::yellow_g()
{
    current->yellow_g(this);
}

void Traficlight::yellow_r()
{
    current->yellow_r(this);
}

Yellow::Yellow()
{
    cout << "Желтый\n";
};

void Yellow::yellow_g(Traficlight* m)
{
    m->setCurrent(new Yellow());
    delete this;
}

void Yellow::yellow_r(Traficlight* m)
{
    m->setCurrent(new Yellow());
    delete this;
}

Red::Red()
{
    cout << "Красный";
};

void Red::yellow_r(Traficlight* m) {
    m->setCurrent(new Yellow());
    delete this;
}

Green::Green()
{
    cout << "Зеленый\n";
};

void Green::yellow_g(Traficlight* m)
{
    m->setCurrent(new Yellow());
    delete this;
}