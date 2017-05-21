//
// Created by Ben Dickson on 5/21/17.
//

#ifndef UNTITLED_PHYSICALMODEL_H
#define UNTITLED_PHYSICALMODEL_H


class PhysicalModel {
public:
    enum Type{RECTANGLE,CIRCLE,ALIGNED_RECTANGLE};
    virtual inline bool overlap(PhysicalModel* other);
    virtual inline Type getType();
};


/**
 * Rectangle is a non aligned rectangle
 */
class PhysicalRectangle : public PhysicalModel
{
private:
public:
    inline bool overlap(PhysicalModel* other)
    {

    }
    static inline Type getType() const
    {
        return RECTANGLE;
    }
};
class PhysicalAlignedRectangle : public PhysicalModel
{
private:
public:
    inline bool overlap(PhysicalModel* other)
    {
    }
    static inline Type getType() const
    {
        return ALIGNED_RECTANGLE;
    }
};

class PhysicalCircle : public PhysicalModel
{
private:
public:
    inline bool overlap(PhysicalModel* other)
    {
        if(other->getType()==CIRCLE)
        {

        }
        else if(other->getType()==ALIGNED_RECTANGLE)
        {

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
#endif //UNTITLED_PHYSICALMODEL_H
