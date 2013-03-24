//See header

#include "backpropHiddenNode.h"

BackpropHiddenNode::BackpropHiddenNode(Rand& rand):BackpropNode(rand)
{
}

BackpropHiddenNode::~BackpropHiddenNode()
{
}

void BackpropHiddenNode::calculateOutput()
{
    double net = getNetValue();
    if(net==0)
        output = 0;
    else
        output =  1.0/(1.0 + exp(-1*net));
    //printf("Hidden Node at 0x%x: Output is %f\n",this,output);
}

void BackpropHiddenNode::calculateError()
{
    //find the weights and errors of all of my outputs
    double weightedSum = 0;
    for(size_t i=0;i<outputs.size();i++)
    {
        BackpropNode* out = outputs[i];
        weightedSum += out->getError()*out->whatsMyWeight(this);
        //printf("weighted sum = %f * %f\n",out->getError(),out->whatsMyWeight(this));
    }
    error = weightedSum*output*(1 - output);
    //printf("Hidden Node at 0x%x: error is %f\n",this,error);
}


