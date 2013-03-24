/*
    Inherits from backpropNode. Represents a hidden node.
*/

#ifndef BACK_PROP_HIDDEN_NODE
#define BACK_PROP_HIDDEN_NODE

#include "backpropNode.h"
#include <math.h>

class BackpropHiddenNode : public BackpropNode
{
public:
    BackpropHiddenNode(Rand& rand);
    virtual ~BackpropHiddenNode();

    virtual void calculateOutput();
    virtual void calculateError();
};

#endif
