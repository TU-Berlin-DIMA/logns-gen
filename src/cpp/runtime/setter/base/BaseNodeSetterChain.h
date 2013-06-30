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
    // runtime components for setter `set_level`
    typedef Myriad::ConstRangeProvider< I64u, Node > RangeProvider02Type;
    typedef Myriad::ClusteredValueProvider< I16u, Node, Myriad::CombinedPrFunction<I16u>, RangeProvider02Type > ValueProvider02Type;
    typedef Myriad::FieldSetter< Node, Myriad::RecordTraits<Node>::LEVEL, ValueProvider02Type > SetLevelType;
    // runtime components for setter `set_label`
    typedef Myriad::RandomValueProvider< Enum, Node, Myriad::ConditionalCombinedPrFunction<I16u, Enum>, Myriad::RecordTraits<Node>::LEVEL > ValueProvider03Type;
    typedef Myriad::FieldSetter< Node, Myriad::RecordTraits<Node>::LABEL, ValueProvider03Type > SetLabelType;
    // runtime components for setter `set_parent_id`
    typedef Myriad::CallbackValueProvider< I16u, Node, BaseNodeSetterChain > ValueProvider04Type;
    typedef Myriad::FieldSetter< Node, Myriad::RecordTraits<Node>::PARENT_ID, ValueProvider04Type > SetParentIdType;

    BaseNodeSetterChain(Myriad::BaseSetterChain::OperationMode& opMode, Myriad::RandomStream& random, Myriad::GeneratorConfig& config) :
        Myriad::SetterChain<Node>(opMode, random),
        _sequenceCardinality(config.cardinality("node")),
        _rangeProvider01(0, config.parameter<I64u>("node.sequence.cardinality")),
        _valueProvider01(config.function< Myriad::UniformPrFunction<I64u> >("Pr[node.batch_id]"), _rangeProvider01),
        _setBatchId(_valueProvider01),
        _rangeProvider02(0, config.parameter<I64u>("node.sequence.base_cardinality")),
        _valueProvider02(config.function< Myriad::CombinedPrFunction<I16u> >("Pr[node.level]"), _rangeProvider02),
        _setLevel(_valueProvider02),
        _valueProvider03(config.function< Myriad::ConditionalCombinedPrFunction<I16u, Enum> >("Pr[node.label]")),
        _setLabel(_valueProvider03),
        _valueProvider04(*this, &BaseNodeSetterChain::setParentID, 0),
        _setParentId(_valueProvider04),
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
        me->_setLevel(recordPtr, me->_random);
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
        _setLevel.filterRange(predicate, result);
        _setLabel.filterRange(predicate, result);
        _setParentId.filterRange(predicate, result);

        return result;
    }

    virtual I16u setParentID(const AutoPtr<Node>& recordPtr, Myriad::RandomStream& random) = 0;

protected:

    // cardinality
    I64u _sequenceCardinality;

    // runtime components for setter `set_batch_id`
    RangeProvider01Type _rangeProvider01;
    ValueProvider01Type _valueProvider01;
    SetBatchIdType _setBatchId;

    // runtime components for setter `set_level`
    RangeProvider02Type _rangeProvider02;
    ValueProvider02Type _valueProvider02;
    SetLevelType _setLevel;

    // runtime components for setter `set_label`
    ValueProvider03Type _valueProvider03;
    SetLabelType _setLabel;

    // runtime components for setter `set_parent_id`
    ValueProvider04Type _valueProvider04;
    SetParentIdType _setParentId;

    // Logger instance.
    Logger& _logger;
};

} // namespace LogNSGen

#endif /* BASENODESETTERCHAIN_H_ */
