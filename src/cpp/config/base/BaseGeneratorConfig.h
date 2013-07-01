// auto-generatad base generator config C++ file

#ifndef BASEGENERATORCONFIG_H_
#define BASEGENERATORCONFIG_H_

#include "config/AbstractGeneratorConfig.h"

namespace Myriad {

class BaseGeneratorConfig: public AbstractGeneratorConfig
{
public:

    BaseGeneratorConfig(GeneratorPool& generatorPool) : AbstractGeneratorConfig(generatorPool)
    {
    }

protected:

    virtual void configurePartitioning()
    {
        // TODO: this piece of auto-generating code / Config API needs to be rewritten

        // setup linear scale estimator for node
        setString("partitioning.node.base-cardinality", toString<I64u>(parameter<I64u>("node.sequence.base_cardinality")));
        computeLinearScalePartitioning("node");
    }

    virtual void configureFunctions()
    {
        // register prototype functions
        function(new Myriad::UniformPrFunction<I64u>("Pr[node.batch_id]", 1, static_cast<I64u>(parameter<I64u>("node.sequence.cardinality") / parameter<I64u>("node.sequence.base_cardinality") + 1)));
        function(new Myriad::ConditionalCombinedPrFunction<I16u, I16u>("Pr[node.delay]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/hierarchy/node/delay.distribution")));
        function(new Myriad::UniformPrFunction<Enum>("Pr[node.label]", 0, 9));
        function(new Myriad::CombinedPrFunction<I16u>("Pr[node.level]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/hierarchy/node/level.distribution")));
        function(new Myriad::UniformPrFunction<I64u>("Pr[node.node_id]", 1, static_cast<I64u>(parameter<I64u>("node.sequence.cardinality") + 1)));
    }

    virtual void configureSets()
    {
        // bind string sets to config members with the bindStringSet method
        enumSet(new MyriadEnumSet("node.label", static_cast<String>(parameter<String>("ENV.config-dir") + "/domains/hierarchy/node/label.domain")));
    }
};

} // namespace Myriad

#endif /* BASEGENERATORCONFIG_H_ */
