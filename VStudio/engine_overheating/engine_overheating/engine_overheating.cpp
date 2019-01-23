//
// Created by fahr on 18.01.19.
//
// тестовое задание Программист C++ Junior
// для компании FORWARD

#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include "pch.h"

#include "environment.h"
#include "entity.h"
#include "engine.h"


int main(int argc, char** argv) {

	// system("chcp 1251 > nul");
	setlocale(0, ".utf8");
    	

    // ОКРУЖАЮЩАЯ СРЕДА
    Environment ENVI;
    double ambientTemp = 0;

    // ДВИГАТЕЛЬ
    // можно задать свои значения параметров двигателя

        // момент инерции двигателя
        double engine_mInertia = 0.1;

        // кусочно-линейная зависимость крутящего момента М, вырабатываемого двигателем, от скорости вращения коленвала V
        std::map <int, int> engine_V_M_dep;

        engine_V_M_dep = { { 0, 20 },
                           { 75, 75 },
                           { 150, 100 },
                           { 200, 105 },
                           { 250, 75 },
                           { 300, 0 } };

        // температура перегрева
        double engine_tOverheat = 110.0;

        // температура двигателя
        double engine_temp = ambientTemp;

        // коэффициент зависимости скорости нагрева от крутящего момента
        double engine_Hm = 0.01;

        // коэффициент зависимости скорости нагрева от скорости вращения коленвала
        double engine_Hv = 0.0001;

        // коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей среды
        double engine_C = 0.1;

        Engine DVS(ambientTemp, engine_mInertia, engine_tOverheat, engine_Hm, engine_Hv, engine_C, engine_V_M_dep);

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
    engine_temp = ambientTemp;
    ENVI.set_temp(ambientTemp);
    DVS.set_temp(engine_temp, ambientTemp);

    std::cout << "Температура двигателя: " << DVS.get_temp() << "°" << '\n';
    std::cout << "Заводим двигатель" << '\n';

    DVS.logic();
    DVS.show_all_parameters();

    return 0;
}