//
// Created by Ben Dickson on 5/30/17.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

#include <vector>
#include "Entity.h"
#include "Element.h"
#include "PhysicalModel.h"

using namespace std;

class CollisionPipeline
{
private:
    vector<CollisionModel*> stationary;
    vector<CollisionModel*> moving;
    vector<CollisionModel*>::iterator stationaryEnd = stationary.end();
    vector<CollisionModel*>::iterator movingEnd = moving.end();
public:
    /**
     * this returns a vector that the parent Entity will need to be adjusted by
     * @return
     */
    inline void testCollision(Entity* parent,CollisionModel* moving,CollisionModel* stationary);

    inline void handleCollisions(double deltaTime);
};

class Game
{
private:
    vector<vector<Entity*>> renderList;
    CollisionPipeline collisionPipeline;
public:
    inline void renderScene()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        vector<vector<Entity*>>::iterator layerEnd = renderList.end();
        for(vector<vector<Entity*>>::iterator layerIt = renderList.begin();layerIt!=layerEnd;++layerIt)
        {
            vector<Entity*>::iterator entEnd = (*layerIt).end();
            for(vector<Entity*>::iterator entIt = (*layerIt).begin();entIt != entEnd;++entIt)
            {
                (*entIt)->render();
            }
        }

        glFlush();
    }

};


#endif //UNTITLED_GAME_H
