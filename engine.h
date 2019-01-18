//
// Created by fahr on 18.01.19.
//

#include "entity.h"

#ifndef ENGINE_OVERHEATING_ENGINE_H
#define ENGINE_OVERHEATING_ENGINE_H

class Engine : public Entity {
public:
    // конструктор по умолчанию
    explicit Engine (double ambientTemp = 0) : engineTemp(engineTemp) {};

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

private:
    // нельзя копировать двигатель
    Engine (const Engine& );
    //
    double engineTemp;

};

#endif //ENGINE_OVERHEATING_ENGINE_H
