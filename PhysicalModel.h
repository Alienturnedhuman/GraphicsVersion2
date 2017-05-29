//
// Created by Ben Dickson on 5/21/17.
//

#ifndef UNTITLED_PHYSICALMODEL_H
#define UNTITLED_PHYSICALMODEL_H

#include "General.h"
#include "Element.h"
#include "Entity.h"

class CollisionModel {
private:
    double x,y;
    short a;
    Element* parent;
public:
    inline Point getGlobalPosition()
    {

    }
    enum Type{RECTANGLE,CIRCLE,ALIGNED_RECTANGLE};
    virtual inline bool overlap(PhysicalModel* other);
    virtual inline Type getType();

    virtual inline unsigned short getRadius();
    virtual inline double getTop();
    virtual inline double getBottom();
    virtual inline double getLeft();
    virtual inline double getRight();

    static inline bool circleAlignedRectOverlap(CollisionModel* circle, Point circleOrigin , CollisionModel* alignedRect, Point rectOrigin);
};


/**
 * Rectangle is a non aligned rectangle
 */
class CollisionRectangle : public CollisionModel
{
private:
    short a;
    unsigned short top,bottom,left,right;
public:
    inline bool overlap(CollisionModel* other)
    {

    }
    static inline Type getType() const
    {
        return RECTANGLE;
    }
};

/**
 * AlignedRectangle is an axis aligned rectangle
 */
class CollisionAlignedRectangle : public CollisionModel
{
private:
    double top,bottom,left,right;
public:
    inline double getTop()
    {
        return top;
    }
    inline double getBottom()
    {
        return bottom;
    }
    inline double getLeft()
    {
        return left;
    }
    inline double getRight()
    {
        return right;
    }
    inline bool overlap(CollisionModel* other)
    {
        Point origin = getGlobalPosition();
        Point otherOrigin = other->getGlobalPosition();
        if(other->getType()==CIRCLE)
        {
            return CollisionModel::circleAlignedRectOverlap(other,otherOrigin,this,origin);
        }
        else if(other->getType()==ALIGNED_RECTANGLE)
        {
            double t = origin.y + top;
            double b = origin.y + bottom;
            double l = origin.x + left;
            double r = origin.x + right;

            double oT = otherOrigin.y + other->getTop();
            double oB = otherOrigin.y + other->getBottom();
            double oL = otherOrigin.x + other->getLeft();
            double oR = otherOrigin.x + other->getRight();

            return !(t<oB && b>oT && r<oL && l>oR);
        }
        else if(other->getType()==RECTANGLE)
        {
            // not yet implemented
        }
        else
        {
            return false;
        }
    }
    static inline Type getType() const
    {
        return ALIGNED_RECTANGLE;
    }
};

/**
 * Circle is a circle
 */
class CollisionCircle : public CollisionModel
{
private:
    unsigned short radius;
public:
    inline unsigned short getRadius()
    {
        return radius;
    }
    inline bool overlap(CollisionModel* other)
    {
        Point origin = getGlobalPosition();
        Point otherOrigin = other->getGlobalPosition();
        if(other->getType()==CIRCLE)
        {
            unsigned short rr = radius + other->getRadius();
            double xx = otherOrigin.x - origin.x;
            double yy = otherOrigin.y - origin.y;
            return (rr*rr) <= (xx*xx + yy*yy);
        }
        else if(other->getType()==ALIGNED_RECTANGLE)
        {
            return CollisionModel::circleAlignedRectOverlap(this,origin,other,otherOrigin);
        }
        else if(other->getType()==RECTANGLE)
        {

        }
        else
        {
            return false;
        }
    }
    static inline Type getType() const
    {
        return CIRCLE;
    }
};







class RenderModel
{
private:
    double x,y;
    short a;
    Element* parent;
public:
    inline Point getGlobalPosition();
    inline Element* getParent()
    {
        return parent;
    }
    virtual inline void render();

};

class RenderCircle : public RenderModel
{
private:
    unsigned short radius;
public:
    inline void render()
    {

    }

};
class RenderAlignedRectangle : public RenderModel
{
private:
    double top,bottom,left,right;
public:
    inline void render()
    {
        Point parentPos = getParent()->getGlobalPosition();


        glPushMatrix();
            // glTranslatef(30,0,0);
            glRotatef(-parentPos.a, 0.0, 0.0, 1.0);
            glColor3f(1.0,0.0,0.0);
            glBegin(GL_POLYGON);
            glVertex2f(left,bottom);
            glVertex2f(left,top);
            glVertex2f(right,top);
            glVertex2f(right,bottom);
            glEnd();
        glPopMatrix();
    }

};
class RenderRectangle : public RenderModel
{
private:
    double top,bottom,left,right;
public:
    inline void render()
    {

    }

};



class PhysicalModel {
private:
    CollisionModel* collisionModel = nullptr;
    RenderModel* renderModel = nullptr;
public:
    void inline render();
};
#endif //UNTITLED_PHYSICALMODEL_H
