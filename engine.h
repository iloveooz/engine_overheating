//
// Created by fahr on 18.01.19.
//

#ifndef ENGINE_OVERHEATING_ENGINE_H
#define ENGINE_OVERHEATING_ENGINE_H

#include "entity.h"
#include <map>
#include <iostream>
#include <cmath>


class Engine : public Entity {
public:

    // конструктор по умолчанию
    explicit Engine (double ambientTemp = 0, double mI = 0.1, double en_tOverheat = 110.0, double en_Hm = 0.01, double en_Hv = 0.0001, double en_C = 0.1,
                     std::map <int, int> VM_dep = {}, bool started = false)
        : engineTemp(ambientTemp), engine_mInertia(mI), engine_tOverheat(en_tOverheat), engine_Hm(en_Hm), engine_Hv(en_Hv), engine_C(en_C), engine_V_M_dep(VM_dep), started(started) {};

    // заведён движок или не заведён
    bool started;

    // задать температуру двигателя
    void set_temp (double tempD, double tempA) {
        engineTemp = tempD;
        ambientTemp = tempA;
    }

    // отобразить температуру двигателя
    double get_temp () const{
        return engineTemp;
    }

    // задать момент инерции двигателя
    void set_mInertia (double mI) {
        engine_mInertia = mI;
    }

    void info () final {
        std::cout << "Бензиновый двигатель" << '\n';
    }

    void show_all_parameters() {
        // вывод всех параметров двигателя на экран
        std::cout << '\n' << "Параметры двигателя: " << '\n';
        std::cout << "Температура двигателя: " << engineTemp << " °С" << '\n';
        std::cout << "Момент инерции двигателя: " << engine_mInertia << " кг*м²" << '\n';

        std::cout << "Кусочно-линейная зависимость М от V. M = { ";
        for (auto it = std::begin(engine_V_M_dep); it != std::end(engine_V_M_dep); ++it)
            std::cout << it->second << ", ";
        std::cout << "} при V = { ";
        for (auto it = std::begin(engine_V_M_dep); it != std::end(engine_V_M_dep); ++it)
            std::cout << it->first << ", ";
        std::cout << "} соответственно." << '\n';

        std::cout << "Температура перегрева двигателя: " << engine_tOverheat << " °С" << '\n';
        std::cout << "К-нт зав-сти скорости нагрева от крутящего момента: " << engine_Hm << "  С°/H*m*сек" << '\n';
        std::cout << "К-нт зав-сти скорости нагрева от скорости вращения коленвала: " << engine_Hv << " C°*сек/рад²" << '\n';
        std::cout << "К-нт зав-сти скорости охлаждения от температуры двигателя и окр. среды: " << engine_C << " 1/сек" << '\n';
    }

    void logic() {
        double Vn = 0;
        double Vc = 0;

        int N = 0;

        while (N < 300) {
            auto it = std::begin(engine_V_M_dep);

            if ((N >= 0) && (N < 5));

            if ((N >= 5) && (N < 10)) {
                it++;
            }

            if ((N >= 10) && (N < 15)) {
                it++;
                it++;
            }

            if ((N >= 15) && (N < 20)) {
                it++;
                it++;
                it++;
            }

            if ((N >= 20) && (N < 25)) {
                it++;
                it++;
                it++;
                it++;
            }

            if ((N >= 25) && (N < 500)) {
                it++;
                it++;
                it++;
                it++;
                it++;
            }

            N++;

            Vn = it->second * engine_Hm + it->first * it->first * engine_Hv;
            Vc = engine_C * (ambientTemp - engineTemp);

            engineTemp = engineTemp + Vn + Vc;
            std::cout << "V = " << it->second << ", M = " << it->first << '\n';
            std::cout << "Vн = " << Vn << ", Vc = " << Vc << '\n';
            std::cout << "Tg = " << engineTemp << '\n';
            std::cout << "N = " << N << '\n';
            std::cout << "------------------------------------" << '\n';

            if (engineTemp >= 110) {
                std::cout << "Закипели!" << '\n';
                std::cout << "Со времени старта прошло " << N << " сек." << '\n';
                N = 501;
            }
        }

        std::cout << "Скорость охлаждения двигателя выше, чем скорость его нагрева." << '\n';
        std::cout << "Получается, что двигатель (эталонный в вакууме, независимо от времени)," << '\n';
        std::cout << "который описывается в задаче, не прогреется никогда, в большинстве случаев." << '\n';
        std::cout << "Скорее всего какая-то ошибка в исходных данных или в формулах расчёта." << '\n';
    };

    ~Engine() final {
    }

private:
    // нельзя копировать двигатель
    Engine (const Engine& );

    // присваивание
    Engine& operator = (Engine& );

    // температура окружающей среды
    double ambientTemp;

    // температура двигателя
    double engineTemp;

    // момент инерции двигателя
    double engine_mInertia;

    // кусочно-линейная зависимость крутящего момента М, вырабатываемого двигателем, от скорости вращения коленвала V
    std::map <int, int> engine_V_M_dep;

    // температура перегрева
    double engine_tOverheat;

    // коэффициент зависимости скорости нагрева от крутящего момента
    double engine_Hm;

    // коэффициент зависимости скорости нагрева от скорости вращения коленвала
    double engine_Hv;

    // коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей среды
    double engine_C;

};

class DizelEngine : public Entity {
public:
    void info () final {
        std::cout << "Дизельный двигатель" << '\n';
    }

private:
};

class GasEngine : public Entity {
public:
    void info () final {
        std::cout << "Газовый двигатель" << '\n';
    }

private:
};

class ElectricEngine : public Entity {
public:
    void info () final {
        std::cout << "Электрический двигатель" << '\n';
    }

private:
};

// если потребуется вводить новые движки
Entity* Entity::createDVS(DVS_ID id) {
    Entity* p;

    switch (id) {
        case Benzin_ID:
            p = new Engine(); break;
        case Dizel_ID:
            p = new DizelEngine(); break;
        case Gas_ID:
            p = new GasEngine(); break;
        case Electric_ID:
            p = new ElectricEngine(); break;
        default:
            break;
    }
    return p;
}

#endif //ENGINE_OVERHEATING_ENGINE_H
