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
    cout << "�������\n";
}

void State::yellow_r(Traficlight* m)
{
    cout << "������\n";
}

void State::green(Traficlight* m)
{
    cout << "�������\n";
}

void State::yellow_g(Traficlight* m)
{
    cout << "������\n";
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
    cout << "������\n";
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
    cout << "�������";
};

void Red::yellow_r(Traficlight* m) {
    m->setCurrent(new Yellow());
    delete this;
}

Green::Green()
{
    cout << "�������\n";
};

void Green::yellow_g(Traficlight* m)
{
    m->setCurrent(new Yellow());
    delete this;
}