//
// Created by Ben Dickson on 5/29/17.
//

#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H

#include <cstdlib>
#include <string>
#include <map>

#include "General.h"

using namespace std;

class Element;

class Entity {
private:
    Point pos;
    map<unsigned short,Element*> childNodes;
public:
    static Rotation* angle = new Rotation();

    inline Point getGlobalPosition()
    {
        return pos;
    }
};


#endif //UNTITLED_ENTITY_H
