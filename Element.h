//
// Created by Ben Dickson on 5/20/17.
//

#ifndef UNTITLED_ELEMENT_H
#define UNTITLED_ELEMENT_H

#include <cstdlib>
#include <string>
#include <map>
#include "General.h"
#include "Entity.h"

using namespace std;

class PhysicalModel;

class Element {
private:
    // parent Element
    Element* parentElement = nullptr;
    map<unsigned short,Element*> childNodes;
    map<unsigned short,PhysicalModel*> parts;
    unsigned short uniqueID;
    Entity* entity = nullptr;

    // relative positions
    double x,y;
    short a;


    // for articulation
    bool limitedRotation;
    short minAngle,maxAngle;

    // for animation
    bool animating = false;
    short anim_r_start, anim_r_end;
    unsigned short anim_f_total,anim_f_remaining;
    double anim_x_start,anim_x_end,anim_y_start,anim_y_end;
public:
    inline unsigned short uid()
    {
        return uniqueID;
    }
    inline bool hasParent()
    {
        return parentElement!=nullptr;
    }
    inline Element* parent()
    {
        return parentElement;
    }
    inline bool setParent(Element* newParent)
    {
        return ((!hasParent()||leaveParent())&&(parentElement = newParent));
    }
    inline bool adopt(Element* newChild)
    {
        if(newChild->setParent(this))
        {
            childNodes.insert(pair<unsigned short,Element*>(newChild->uid(),newChild));
            return true;
        }
        else
        {
            return false;
        }
    }
    inline bool removeChild(Element* formerChild)
    {
        map<unsigned short,Element*>::iterator it=childNodes.find(formerChild->uid());
        if(it != childNodes.end())
        {
            childNodes.erase(it);
            return true;
        }
        else
        {
            return false;
        }
    }
    inline bool leaveParent()
    {
        // will return false if it can leave Parent and does leave parent
        parentElement->removeChild(this);
    }


    // positional stuff
    inline Point getGlobalPosition();

};


#endif //UNTITLED_ELEMENT_H
