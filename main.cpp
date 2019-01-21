//
// Created by fahr on 18.01.19.
//
// тестовое задание Программист C++ Junior
// для компании FORWARD

#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>

//#include "stdafx.h"

#include "environment.h"
#include "entity.h"
#include "engine.h"


int main(int argc, char** argv) {

    // setlocale(LC_ALL, "ru");

    // ОКРУЖАЮЩАЯ СРЕДА
    Environment ENVI;
    double ambientTemp = 0;

    // ДВИГАТЕЛЬ
    // можно задать свои значения параметров двигателя

        // момент инерции двигателя
        double engine_mInertia = 0.1;

        // кусочно-линейная зависимость крутящего момента М, вырабатываемого двигателем, от скорости вращения коленвала V
        std::unordered_map <int, int> engine_M_V_dep;

        engine_M_V_dep = { { 20,  0 },
                           { 75,  75 },
                           { 100, 150 },
                           { 105, 200 },
                           { 75,  250 },
                           { 0,   300 } };

        // температура перегрева
        double engine_tOverheat = 110.0;

        // температура двигателя
        double engine_tCurrent = ambientTemp;

        // коэффициент зависимости скорости нагрева от крутящего момента
        double engine_Hm = 0.01;

        // коэффициент зависимости скорости нагрева от скорости вращения коленвала
        double engine_Hv = 0.0001;

        // коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей среды
        double engine_C = 0.1;


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

    std::cout << "Температура окружающей среды: " << ENVI.get_temp() << "°" << '\n';
    std::cout << "Температура двигателя: " << DVS.get_temp() << "°" << '\n';




    return 0;
}