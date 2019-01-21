//
// Created by fahr on 18.01.19.
//

#ifndef ENGINE_OVERHEATING_ENGINE_H
#define ENGINE_OVERHEATING_ENGINE_H

#include "entity.h"
#include <unordered_map>
#include <bits/unordered_map.h>

class Engine : public Entity {
public:
    // конструктор по умолчанию
    explicit Engine (double ambientTemp = 0, double mI = 0.1) : engineTemp(engineTemp), engine_mInertia(mI) {};

    // присваивание
    Engine& operator = (Engine& );

    // задать температуру двигателя
    void set_temp (double temp) {
        engineTemp = temp;
    }

    // отобразить температуру двигателя
    double get_temp () {
        return engineTemp;
    }

    // задать момент инерции двигателя
    void set_mInertia (double mI) {
        engine_mInertia = mI;
    }

    ~Engine() {
        // TODO реализовать в деструкторе удаление map - таблицы
    }

private:
    // нельзя копировать двигатель
    Engine (const Engine& );

    // температура двигателя
    double engineTemp;

    // момент инерции двигателя
    double engine_mInertia;

    // кусочно-линейная зависимость крутящего момента М, вырабатываемого двигателем, от скорости вращения коленвала V
    std::unordered_map <int, int> engine_M_V_dep;

    // температура перегрева

};

#endif //ENGINE_OVERHEATING_ENGINE_H
