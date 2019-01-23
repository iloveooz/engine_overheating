//
// Created by fahr on 18.01.19.
//

#ifndef ENGINE_OVERHEATING_ENTITY_H
#define ENGINE_OVERHEATING_ENTITY_H

enum DVS_ID {
    Benzin_ID = 0,
    Dizel_ID,
    Gas_ID,
    Electric_ID
};

class Entity {
public:

    Entity () {}
    virtual ~Entity() {}
    virtual void info() = 0;
    // для введения в программу новых типов двигателей
    static Entity* createDVS(DVS_ID id);
};



#endif //ENGINE_OVERHEATING_ENTITY_H
