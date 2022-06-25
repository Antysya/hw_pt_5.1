#include <iostream>
#include "traffic_lights.h"
#include <windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    void(Traficlight:: * ptrs[])() =
    {
      &Traficlight::red, &Traficlight::yellow_g, &Traficlight::green, & Traficlight::yellow_r
    };
    Traficlight fsm;

    while (true)
    {
        for (int i = 0; i < 4; i++) {
            system("cls");
            (fsm.*ptrs[i])();
            Sleep(3000);
        }
    }
}