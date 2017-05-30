//
// Created by Ben Dickson on 5/30/17.
//

#include "Game.h"





inline void CollisionPipeline::testCollision(Entity* movingParent,CollisionModel* moving,Entity* stationaryParent, CollisionModel* stationary)
{

}

inline void CollisionPipeline::handleCollisions(double deltaTime)
{
    for(vector<CollisionModel*>::iterator movingIt = moving.begin();movingIt!=movingEnd;++movingIt)
    {
        Entity* thisEntity = (*movingIt)->belongsTo();
        // compare against everything stationary
        for(vector<CollisionModel*>::iterator stationaryIt = stationary.begin();stationaryIt!=stationaryEnd;++stationaryIt)
        {
            Entity* collidesWith = (*stationaryIt)->belongsTo();

        }

        // compare against everything moving that has been moved
        for(vector<CollisionModel*>::iterator movingComp = moving.begin();movingComp!=movingIt;++movingComp)
        {
            Entity* collidesWith = (*movingComp)->belongsTo();


        }


    }
}