// auto-generatad C++ setter chain for `node`

#ifndef BASENODESETTERCHAIN_H_
#define BASENODESETTERCHAIN_H_

#include "config/GeneratorConfig.h"
#include "runtime/setter/SetterChain.h"
#include "record/Node.h"
#include "record/NodeUtil.h"
#include "runtime/provider/range/ConstRangeProvider.h"
#include "runtime/provider/value/CallbackValueProvider.h"
#include "runtime/provider/value/ClusteredValueProvider.h"
#include "runtime/provider/value/RandomValueProvider.h"
#include "runtime/setter/FieldSetter.h"

namespace LogNSGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

/**
 * SetterChain specialization for User.
 */
class BaseNodeSetterChain : public Myriad::SetterChain<Node>
{
public:

    // runtime component typedefs
    // runtime components for setter `set_batch_id`
    typedef Myriad::ConstRangeProvider< I64u, Node > RangeProvider01Type;
    typedef Myriad::ClusteredValueProvider< I64u, Node, Myriad::UniformPrFunction<I64u>, RangeProvider01Type > ValueProvider01Type;
    typedef Myriad::FieldSetter< Node, Myriad::RecordTraits<Node>::BATCH_ID, ValueProvider01Type > SetBatchIdType;
    // runtime components for setter `set_node_id`
    typedef Myriad::ConstRangeProvider< I64u, Node > RangeProvider02Type;
    typedef Myriad::ClusteredValueProvider< I64u, Node, Myriad::UniformPrFunction<I64u>, RangeProvider02Type > ValueProvider02Type;
    typedef Myriad::FieldSetter< Node, Myriad::RecordTraits<Node>::NODE_ID, ValueProvider02Type > SetNodeIdType;
    // runtime components for setter `set_level`
    typedef Myriad::ConstRangeProvider< I64u, Node > RangeProvider03Type;
    typedef Myriad::ClusteredValueProvider< I16u, Node, Myriad::CombinedPrFunction<I16u>, RangeProvider03Type > ValueProvider03Type;
    typedef Myriad::FieldSetter< Node, Myriad::RecordTraits<Node>::LEVEL, ValueProvider03Type > SetLevelType;
    // runtime components for setter `set_delay`
    typedef Myriad::RandomValueProvider< I16u, Node, Myriad::ConditionalCombinedPrFunction<I16u, I16u>, Myriad::RecordTraits<Node>::LEVEL > ValueProvider04Type;
    typedef Myriad::FieldSetter< Node, Myriad::RecordTraits<Node>::DELAY, ValueProvider04Type > SetDelayType;
    // runtime components for setter `set_label`
    typedef Myriad::RandomValueProvider< Enum, Node, Myriad::UniformPrFunction<Enum>, 0 > ValueProvider05Type;
    typedef Myriad::FieldSetter< Node, Myriad::RecordTraits<Node>::LABEL, ValueProvider05Type > SetLabelType;
    // runtime components for setter `set_parent_id`
    typedef Myriad::CallbackValueProvider< I64u, Node, BaseNodeSetterChain > ValueProvider06Type;
    typedef Myriad::FieldSetter< Node, Myriad::RecordTraits<Node>::PARENT_ID, ValueProvider06Type > SetParentIdType;

    BaseNodeSetterChain(Myriad::BaseSetterChain::OperationMode& opMode, Myriad::RandomStream& random, Myriad::GeneratorConfig& config) :
        Myriad::SetterChain<Node>(opMode, random),
        _sequenceCardinality(config.cardinality("node")),
        _rangeProvider01(0, config.parameter<I64u>("node.sequence.cardinality")),
        _valueProvider01(config.function< Myriad::UniformPrFunction<I64u> >("Pr[node.batch_id]"), _rangeProvider01),
        _setBatchId(_valueProvider01),
        _rangeProvider02(0, config.parameter<I64u>("node.sequence.cardinality")),
        _valueProvider02(config.function< Myriad::UniformPrFunction<I64u> >("Pr[node.node_id]"), _rangeProvider02),
        _setNodeId(_valueProvider02),
        _rangeProvider03(0, config.parameter<I64u>("node.sequence.base_cardinality")),
        _valueProvider03(config.function< Myriad::CombinedPrFunction<I16u> >("Pr[node.level]"), _rangeProvider03),
        _setLevel(_valueProvider03),
        _valueProvider04(config.function< Myriad::ConditionalCombinedPrFunction<I16u, I16u> >("Pr[node.delay]")),
        _setDelay(_valueProvider04),
        _valueProvider05(config.function< Myriad::UniformPrFunction<Enum> >("Pr[node.label]")),
        _setLabel(_valueProvider05),
        _valueProvider06(*this, &BaseNodeSetterChain::setParentID, 0),
        _setParentId(_valueProvider06),
        _logger(Logger::get("node.setter.chain"))
    {
    }

    virtual ~BaseNodeSetterChain()
    {
    }

    /**
     * Applies the setter chain to the given record instance.
     */
    void operator()(AutoPtr<Node> recordPtr) const
    {
        ensurePosition(recordPtr->genID());

        BaseNodeSetterChain* me = const_cast<BaseNodeSetterChain*>(this);

        // apply setter chain
        me->_setBatchId(recordPtr, me->_random);
        me->_setNodeId(recordPtr, me->_random);
        me->_setLevel(recordPtr, me->_random);
        me->_setDelay(recordPtr, me->_random);
        me->_setLabel(recordPtr, me->_random);
        me->_setParentId(recordPtr, me->_random);
    }

    /**
     * Predicate filter function.
     */
    virtual Myriad::Interval<I64u> filter(const Myriad::EqualityPredicate<Node>& predicate)
    {
        Myriad::Interval<I64u> result(0, _sequenceCardinality);

        // explicitly mimic inverse setter logic for gen_id
        if (predicate.bound(Myriad::RecordTraits<Node>::GEN_ID))
        {
            const AutoPtr<Node>& valueHolder = predicate.valueHolder();
            result.intersect(Myriad::Interval<I64u>(valueHolder->genID(), valueHolder->genID()+1));
        }

        // apply inverse setter chain, setters are applied in the same order
        _setBatchId.filterRange(predicate, result);
        _setNodeId.filterRange(predicate, result);
        _setLevel.filterRange(predicate, result);
        _setDelay.filterRange(predicate, result);
        _setLabel.filterRange(predicate, result);
        _setParentId.filterRange(predicate, result);

        return result;
    }

    virtual I64u setParentID(const AutoPtr<Node>& recordPtr, Myriad::RandomStream& random) = 0;

protected:

    // cardinality
    I64u _sequenceCardinality;

    // runtime components for setter `set_batch_id`
    RangeProvider01Type _rangeProvider01;
    ValueProvider01Type _valueProvider01;
    SetBatchIdType _setBatchId;

    // runtime components for setter `set_node_id`
    RangeProvider02Type _rangeProvider02;
    ValueProvider02Type _valueProvider02;
    SetNodeIdType _setNodeId;

    // runtime components for setter `set_level`
    RangeProvider03Type _rangeProvider03;
    ValueProvider03Type _valueProvider03;
    SetLevelType _setLevel;

    // runtime components for setter `set_delay`
    ValueProvider04Type _valueProvider04;
    SetDelayType _setDelay;

    // runtime components for setter `set_label`
    ValueProvider05Type _valueProvider05;
    SetLabelType _setLabel;

    // runtime components for setter `set_parent_id`
    ValueProvider06Type _valueProvider06;
    SetParentIdType _setParentId;

    // Logger instance.
    Logger& _logger;
};

} // namespace LogNSGen

#endif /* BASENODESETTERCHAIN_H_ */
