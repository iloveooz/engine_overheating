//
// Created by fahr on 18.01.19.
//

#ifndef ENGINE_OVERHEATING_ENVIRONMENT_H
#define ENGINE_OVERHEATING_ENVIRONMENT_H

// класс - окружающая среда (в единственном экземпляре)
class Environment {
public:
    // конструктор по умолчанию
    explicit Environment (double ambientTemp = 0) : ambientTemp(ambientTemp) {};

    // задать температуру окружающей среды
    void set_temp (double temp) {
        ambientTemp = temp;
    }

    // отобразить температуру окружающей среды
    double get_temp () {
        return ambientTemp;
    }
private:
    // нельзя копировать окружающую среду
    Environment (const Environment& );

    // нельзя присваивать
    Environment& operator = (Environment& );

    // температура окружающей среды
    double ambientTemp;
};

#endif //ENGINE_OVERHEATING_ENVIRONMENT_H
