//See header

#include "backpropInputNode.h"

BackpropInputNode::BackpropInputNode(Rand& rand):BackpropNode(rand)
{
}

BackpropInputNode::~BackpropInputNode()
{
}

void BackpropInputNode::setInputValue(double val)
{
    this->output = val;
}

void BackpropInputNode::calculateOutput()
{
    //Do nothing
}


