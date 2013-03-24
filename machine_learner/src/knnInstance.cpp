//See header for details

#include "knnInstance.h"

KNN_Instance::KNN_Instance(vector<double> attributes, vector<int> types, double label)
{
    assert(attributes.size() == types.size());
    this->attributes = attributes;
    this->attributeTypes = types;
    this->label = label;
}

KNN_Instance::~KNN_Instance()
{
}

vector<double>& KNN_Instance::getAttributes()
{
    return this->attributes;
}

/*
    We're going to use Euclidean distance and with nominal data use a 0 if 
    the two values are equal and 1 if they are different
*/
double KNN_Instance::getDistanceTo(KNN_Instance* other)
{
    vector<double>& otherAttr = other->getAttributes();
    return this->getDistanceTo(otherAttr);
}
double KNN_Instance::getDistanceTo(const vector<double>& otherAttr)
{
    assert(otherAttr.size() == this->attributes.size());
    
    double distanceSquared = 0;
    for(size_t i=0;i<attributes.size();i++)
    {
        double diff = 0;
        if(this->attributeTypes[i] == TYPE_CONTINUOUS)
        {
            if(this->attributes[i]==UNKNOWN_VALUE || otherAttr[i]==UNKNOWN_VALUE)
                diff = 1;
            else
                diff = this->attributes[i] - otherAttr[i];
        }
        else    //Its nominal
        {
            if(this->attributes[i] == otherAttr[i])
                diff = 0;
            else
                diff = 1;
        }
        distanceSquared += diff*diff;
        
    }
    return sqrt(distanceSquared);
}


