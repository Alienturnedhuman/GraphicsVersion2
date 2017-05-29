//
// Created by Ben Dickson on 5/21/17.
//

#include "PhysicalModel.h"



inline Point CollisionModel::getGlobalPosition()
{
    Point relativeOrigin = parent->getGlobalPosition();
    Point r;
    r.a = (relativeOrigin.a + a)%360;
    if(r.a<0)
    {
        r.a += 360;
    }
    double cos = Entity::angle->cos(relativeOrigin.a);
    double sin = Entity::angle->cos(relativeOrigin.a);
    r.x = relativeOrigin.x + x*cos - y * sin;
    r.y = relativeOrigin.y + x*sin - y * cos;
    return r;
}


inline bool CollisionModel::circleAlignedRectOverlap(CollisionModel* circle, Point circleOrigin , CollisionModel* alignedRect, Point rectOrigin)
{
    // real world positions of top/bottom/left/right
    double t = rectOrigin.y + alignedRect->getTop();
    double b = rectOrigin.y + alignedRect->getBottom();
    double l = rectOrigin.x + alignedRect->getLeft();
    double r = rectOrigin.x + alignedRect->getRight();

    // real world position of top/bottom/left/right extended by circle radius
    unsigned short rad = circle->getRadius();
    double tt = t+rad;
    double bb = b-rad;
    double ll = l - rad;
    double rr = r + rad;

    // check if circle origin is within the "cross" shape of the rectangle extended by radius (but not corners)
    if(
            circleOrigin.x>=ll && circleOrigin.x<=rr && circleOrigin.y<=t && circleOrigin.y>=b
            ||
            circleOrigin.x>=l && circleOrigin.x<=r && circleOrigin.y<=tt && circleOrigin.y>=bb
            )
    {
        return true;
    }

    // reuse these for circle origin distance to sides
    tt = t-circleOrigin.y;
    ll = l-circleOrigin.x;

    tt = tt*tt;
    ll = ll*ll;
    rad = rad*rad;
    if(rad<=tt+ll)
    {
        return true;
    }

    bb = b-circleOrigin.y;
    bb = bb*bb;
    if(rad<=bb+ll)
    {
        return true;
    }

    rr = r-circleOrigin.x;
    rr = rr*rr;
    return rad<=tt+rr || rad<=bb+rr;
}






// render methods below


inline Point RenderModel::getGlobalPosition()
{
    Point relativeOrigin = parent->getGlobalPosition();
    Point r;
    r.a = (relativeOrigin.a + a)%360;
    if(r.a<0)
    {
        r.a += 360;
    }
    double cos = Entity::angle->cos(relativeOrigin.a);
    double sin = Entity::angle->cos(relativeOrigin.a);
    r.x = relativeOrigin.x + x*cos - y * sin;
    r.y = relativeOrigin.y + x*sin - y * cos;
    return r;
}


inline void PhysicalModel::render()
{
    if(renderModel != nullptr)
    {
        renderModel->render();
    }
}

inline void Element::render()
{
    Point parentPos = getGlobalPosition();
    glPushMatrix();
        glTranslatef(parentPos.x,parentPos.y,0);
        glRotatef(parentPos.a, 0.0, 0.0, 1.0);
        map<unsigned short,Element*>::iterator ite = childNodes.end();
        for(map<unsigned short,Element*>::iterator it = childNodes.begin();it != ite ; ++it)
        {
            (*it).second->render();
        }

        map<unsigned short,PhysicalModel*>::iterator itpe = parts.end();
        for(map<unsigned short,PhysicalModel*>::iterator itp = parts.begin();itp != itpe ; ++itp)
        {
            (*itp).second->render();
        }


    glPopMatrix();
}

inline void Entity::render()
{
    glPushMatrix();
        glTranslatef(pos.x,pos.y,0);
        glRotatef(pos.a, 0.0, 0.0, 1.0);
        map<unsigned short,Element*>::iterator ite = childNodes.end();
        for(map<unsigned short,Element*>::iterator it = childNodes.begin();it != ite ; ++it)
        {
            (*it).second->render();
        }
    glPopMatrix();
}