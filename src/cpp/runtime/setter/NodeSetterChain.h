#ifndef NODESETTERCHAIN_H_
#define NODESETTERCHAIN_H_

#include "runtime/setter/base/BaseNodeSetterChain.h"

namespace LogNSGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class NodeSetterChain : public BaseNodeSetterChain
{
public:

    NodeSetterChain(Myriad::BaseSetterChain::OperationMode& opMode, Myriad::RandomStream& random, Myriad::GeneratorConfig& config) :
        BaseNodeSetterChain(opMode, random, config)
    {
    }

    virtual ~NodeSetterChain()
    {
    }

    I64u setParentID(const AutoPtr<Node>& recordPtr, Myriad::RandomStream& random)
    {
        const I64u blockID = recordPtr->genID() / 10000;
        const I64u sequenceID = recordPtr->genID() % 10000;

        if (sequenceID < 1)
        {
            return 0 * random.next() + 1;
        }
        else if (sequenceID < 11)
        {
            return 0 * random.next() + 1;
        }
        else if (sequenceID < 111)
        {
            return (blockID * 10000) + (1 + 10 * random.next()) + 1;
        }
        else if (sequenceID < 1111)
        {
            return (blockID * 10000) + (11 + 100 * random.next()) + 1;
        }
        else // (sequenceID < 10000)
        {
            return (blockID * 10000) + (111 + 1000 * random.next()) + 1;
        }
    }
};

} // namespace LogNSGen

#endif /* BASENODEGENERATOR_H_ */
