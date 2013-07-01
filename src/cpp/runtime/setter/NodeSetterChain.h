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
        BaseNodeSetterChain(opMode, random, config),
        _baseCardinality(config.parameter<I64u>("node.sequence.base_cardinality")),
        _nodeLevelPr(config.function< Myriad::CombinedPrFunction<I16u> >("Pr[node.level]"))
    {
    }

    virtual ~NodeSetterChain()
    {
    }

    I64u setParentID(const AutoPtr<Node>& recordPtr, Myriad::RandomStream& random)
    {
        const I64u blockID = recordPtr->genID() / _baseCardinality;
        const I64u sequenceID = recordPtr->genID() % _baseCardinality;

        double r = random.next();
        if (sequenceID < _baseCardinality * _nodeLevelPr.cdf(0))
        {
            return Myriad::nullValue<I64u>();
        }
        else if (sequenceID < _baseCardinality * _nodeLevelPr.cdf(1))
        {
            return (_baseCardinality * blockID) + (_baseCardinality * (_nodeLevelPr.pdf(0) * r)) + 1;
        }
        else if (sequenceID < _baseCardinality * _nodeLevelPr.cdf(2))
        {
            return (_baseCardinality * blockID) + (_baseCardinality * (_nodeLevelPr.cdf(0) + _nodeLevelPr.pdf(1) * r)) + 1;
        }
        else // (sequenceID < baseCardinality * _nodeLevelPr.cdf(3))
        {
            return (_baseCardinality * blockID) + (_baseCardinality * (_nodeLevelPr.cdf(1) + _nodeLevelPr.pdf(2) * r)) + 1;
        }
    }

private:
    const I64u _baseCardinality;
    const Myriad::CombinedPrFunction<I16u>& _nodeLevelPr;
};

} // namespace LogNSGen

#endif /* BASENODEGENERATOR_H_ */
