//
// Created by fahr on 18.01.19.
//
// тестовое задание Программист C++ Junior
// для компании FORWARD

#include <iostream>
//#include "stdafx.h"

#include "environment.h"
#include "entity.h"
#include "engine.h"


int main(int argc, char** argv) {

    // setlocale(LC_ALL, "ru");

    // окружающая среда
    Environment ENVI;
    double ambientTemp = 0;

    Engine DVS;

    std::cout << "Тестовое задание" << '\n';
    std::cout << "Расчёт времени от запуска ДВС до перегрева ДВС" << '\n';

    do {
        std::cout << "Введите температуру окружающей среды: ";
        std::cin >> ambientTemp;
        if (ambientTemp < -273) {
            std::cout << "! - Такой температуры не бывает в природе" << '\n';
        }
        else if (ambientTemp > 60) {
            std::cout << "! - Такой температуры не бывает в земных условиях" << '\n';
        }
    }
    while (!(ambientTemp >= -273 && ambientTemp <= 60));

    // устанавливаем температуру окружающей среды
    ENVI.set_temp(ambientTemp);
    DVS.set_temp(ambientTemp);

    std::cout << "Температура окружающей среды: " << ENVI.get_temp() << '\n';
    std::cout << "Температура двигателя: " << ENVI.get_temp() << '\n';




    return 0;
}