//
// Created by Ben Dickson on 5/20/17.
//

#ifndef UNTITLED_ELEMENT_H
#define UNTITLED_ELEMENT_H

#include <cstdlib>
#include <string>
#include <map>

using namespace std;

class PhysicalModel;

class Element {
private:
    // parent Element
    Element* parentElement = nullptr;
    map<unsigned short,Element*> childNodes;
    map<unsigned short,PhysicalModel*> parts;
    unsigned short uniqueID;

    // relative positions
    double x,y,r;
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


};


#endif //UNTITLED_ELEMENT_H
