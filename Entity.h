//
// Created by Ben Dickson on 5/29/17.
//

#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H

#include <cstdlib>
#include <string>
#include <map>
#include <list>
#include <vector>

#include "General.h"

using namespace std;

class Element;

class CollisionAction
{

};


class Entity {
public:
    enum EntityType {PLAYER,PLATFORM,TRIGGER,NPC,PROJECTILE};
    enum CollisionDirection {ALL,LEFT,RIGHT,BOTTOM,TOP};
private:
    Point pos;
    Point momentum;
    EntityType type;
    map<unsigned short,Element*> childNodes;
    map<CollisionDirection,map<EntityType,vector<CollisionAction*>>> collisionRules;
public:
    static Rotation* angle = new Rotation();

    inline Point getGlobalPosition()
    {
        return pos;
    }
    inline Point getMomentum()
    {
        return momentum;
    }


    /**
     * Returns a linked list of CollisionAction pointers
     * @param direction
     * @param with
     * @return
     */
    inline list<CollisionAction*> onCollision(CollisionDirection direction,EntityType with)
    {
        list<CollisionAction*> r;
        map<CollisionDirection,map<EntityType,vector<CollisionAction*>>>::iterator ite = collisionRules.end();
        map<CollisionDirection,map<EntityType,vector<CollisionAction*>>>::iterator all = collisionRules.find(CollisionDirection::ALL);
        if(all!=ite)
        {
            map<EntityType,vector<CollisionAction*>>::iterator eit = ((*all).second).find(with);
            if(eit!=((*all).second).end())
            {
                vector<CollisionAction*>::iterator rite = ((*eit).second).end();
                for(vector<CollisionAction*>::iterator rit = ((*eit).second).begin();rit!=rite;++rit)
                {
                    r.push_back(*rit);
                }
            }
        }
        map<CollisionDirection,map<EntityType,vector<CollisionAction*>>>::iterator it = collisionRules.find(direction);
        if(it!=ite)
        {
            map<EntityType,vector<CollisionAction*>>::iterator eit = ((*it).second).find(with);
            if(eit!=((*all).second).end())
            {
                vector<CollisionAction*>::iterator rite = ((*eit).second).end();
                for(vector<CollisionAction*>::iterator rit = ((*eit).second).begin();rit!=rite;++rit)
                {
                    r.push_back(*rit);
                }
            }
        }
        return r;
    }



    inline void render();
};


#endif //UNTITLED_ENTITY_H
