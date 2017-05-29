//
// Created by Ben Dickson on 5/20/17.
//

#include "Element.h"

inline Point Element::getGlobalPosition()
{
    Point parentPos;
    if(parentElement==nullptr)
    {
        parentPos = entity->getGlobalPosition();
    }
    else
    {
        parentPos = parentElement->getGlobalPosition();
    }
    Point r;
    r.a = (parentPos.a + a)%360;
    if(r.a<0)
    {
        r.a += 360;
    }
    double cos = Entity::angle->cos(parentPos.a);
    double sin = Entity::angle->cos(parentPos.a);
    r.x = parentPos.x + x*cos - y * sin;
    r.y = parentPos.y + x*sin - y * cos;
    return r;
}