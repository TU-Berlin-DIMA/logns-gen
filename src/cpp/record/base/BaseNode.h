// auto-generatad C++ file for `node`

#ifndef BASENODE_H_
#define BASENODE_H_

#include "record/AbstractRecord.h"
#include "record/NodeMeta.h"

namespace LogNSGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// forward declarations
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Node;
class NodeConfig;
class NodeGenerator;
class NodeSetterChain;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// base record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseNode: public Myriad::AbstractRecord
{
public:

    BaseNode(const NodeMeta& meta) : 
        _meta(meta)
    {
    }

    const NodeMeta& meta() const
    {
        return _meta;
    }

    void nodeId(const I64u& v);
    const I64u& nodeId() const;

    void batchId(const I64u& v);
    const I64u& batchId() const;

    void level(const I16u& v);
    const I16u& level() const;

    void delay(const I16u& v);
    const I16u& delay() const;

    void label(const Enum& v);
    const Enum& label() const;
    const String& labelEnumValue() const;

    void parentId(const I64u& v);
    const I64u& parentId() const;

protected:

    // fields
    I64u _node_id;
    I64u _batch_id;
    I16u _level;
    I16u _delay;
    Enum _label;
    I64u _parent_id;

    // meta
    const NodeMeta& _meta;
};

inline void BaseNode::nodeId(const I64u& v)
{
    _node_id = v;
}

inline const I64u& BaseNode::nodeId() const
{
    return _node_id;
}

inline void BaseNode::batchId(const I64u& v)
{
    _batch_id = v;
}

inline const I64u& BaseNode::batchId() const
{
    return _batch_id;
}

inline void BaseNode::level(const I16u& v)
{
    _level = v;
}

inline const I16u& BaseNode::level() const
{
    return _level;
}

inline void BaseNode::delay(const I16u& v)
{
    _delay = v;
}

inline const I16u& BaseNode::delay() const
{
    return _delay;
}

inline void BaseNode::label(const Enum& v)
{
    _label = v;
}

inline const Enum& BaseNode::label() const
{
    return _label;
}

inline const String& BaseNode::labelEnumValue() const
{
    if (_label == Myriad::nullValue<Enum>())
    {
        return Myriad::nullValue<String>();
    }
    else
    {
        return _meta.label[_label];
    }
}

inline void BaseNode::parentId(const I64u& v)
{
    _parent_id = v;
}

inline const I64u& BaseNode::parentId() const
{
    return _parent_id;
}

} // namespace LogNSGen

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record traits specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
struct RecordTraits<LogNSGen::Node>
{
    typedef LogNSGen::NodeMeta MetaType;
    typedef LogNSGen::NodeGenerator GeneratorType;
    typedef LogNSGen::NodeSetterChain SetterChainType;
    typedef RecordFactory<LogNSGen::Node> FactoryType;

    enum Field { UNKNOWN, GEN_ID, NODE_ID, BATCH_ID, LEVEL, DELAY, LABEL, PARENT_ID };
};

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void AbstractOutputCollector<LogNSGen::BaseNode>::serialize(std::ostream& out, const LogNSGen::BaseNode& record)
{
    write(out, record.batchId(), false);
    out << '|';
    write(out, record.nodeId(), false);
    out << '|';
    write(out, record.labelEnumValue(), true);
    out << '|';
    write(out, record.delay(), false);
    out << '|';
    write(out, record.parentId(), false);
    out << '|';
    out << '\n';
}

} // namespace Myriad

#endif /* BASENODE_H_ */
