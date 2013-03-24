//See header

#include "backpropOutputNode.h"

BackpropOutputNode::BackpropOutputNode(Rand& rand):BackpropNode(rand)
{
    expectedOutput = 0;
}

BackpropOutputNode::~BackpropOutputNode()
{
}

void BackpropOutputNode::calculateOutput()
{
    //cout<<"In outputnode::getOutput()"<<endl;
    double net = getNetValue();
    //cout<<"net is "<<net<<endl;
    if(net==0)  //avoid the extremely rare div by 0 error
        output = 0;
    else
        output = 1.0/(1.0 + exp(-1*net));
    //printf("OutputNode at 0x%x: output is %f\n",this,output);
}

void BackpropOutputNode::calculateError()
{
    error = (expectedOutput-output)*output*(1-output);
    //printf("OutputNode at 0x%x: error is %f\n",this,error);
}

void BackpropOutputNode::setExpectedOutput(double num)
{
    this->expectedOutput = num;
}

double BackpropOutputNode::getLastSquaredError()
{
    double diff = expectedOutput-output;
    return diff*diff;
}


