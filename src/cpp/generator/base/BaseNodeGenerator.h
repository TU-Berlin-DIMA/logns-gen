// auto-generatad C++ generator for `node`

#ifndef BASENODEGENERATOR_H_
#define BASENODEGENERATOR_H_

#include "generator/RandomSequenceGenerator.h"
#include "runtime/setter/NodeSetterChain.h"

namespace LogNSGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseNodeGenerator: public Myriad::RandomSequenceGenerator<Node>
{
public:

    BaseNodeGenerator(const string& name, Myriad::GeneratorConfig& config, NotificationCenter& notificationCenter) :
        Myriad::RandomSequenceGenerator<Node>(name, config, notificationCenter)
    {
    }

    void prepare(Stage stage, const Myriad::GeneratorPool& pool)
    {
        // call generator implementation
        Myriad::RandomSequenceGenerator<Node>::prepare(stage, pool);

        if (stage.name() == name())
        {
            registerTask(new Myriad::PartitionedSequenceIteratorTask< Node > (*this, _config));
        }
    }

    NodeSetterChain setterChain(Myriad::BaseSetterChain::OperationMode opMode, Myriad::RandomStream& random)
    {
        return NodeSetterChain(opMode, random, _config);
    }
};

} // namespace LogNSGen

#endif /* BASENODEGENERATOR_H_ */
