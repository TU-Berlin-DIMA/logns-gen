#ifndef NODEGENERATOR_H_
#define NODEGENERATOR_H_

#include "generator/base/BaseNodeGenerator.h"

namespace LogNSGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class NodeGenerator: public BaseNodeGenerator
{
public:

    typedef Myriad::RecordTraits<Node>::SetterChainType SetterChainType;

    NodeGenerator(const string& name, Myriad::GeneratorConfig& config, NotificationCenter& notificationCenter) :
        BaseNodeGenerator(name, config, notificationCenter)
    {
    }
};

} // namespace LogNSGen

#endif /* BASENODEGENERATOR_H_ */
