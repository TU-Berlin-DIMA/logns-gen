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

    I16u setParentID(const AutoPtr<Node>& recordPtr, Myriad::RandomStream& random)
    {
        return 42;
    }
};

} // namespace LogNSGen

#endif /* BASENODEGENERATOR_H_ */
