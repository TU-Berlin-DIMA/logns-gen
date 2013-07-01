// auto-generatad C++ file for `node`

#ifndef BASENODEUTIL_H_
#define BASENODEUTIL_H_

#include "record/Node.h"

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record field inspection structures
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

// node_id
template<>
struct RecordFieldTraits<RecordTraits<LogNSGen::Node>::NODE_ID, LogNSGen::Node>
{
    typedef I64u FieldType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefSetter FieldSetterType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefGetter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&LogNSGen::Node::nodeId);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&LogNSGen::Node::nodeId);
    }
};

// batch_id
template<>
struct RecordFieldTraits<RecordTraits<LogNSGen::Node>::BATCH_ID, LogNSGen::Node>
{
    typedef I64u FieldType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefSetter FieldSetterType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefGetter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&LogNSGen::Node::batchId);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&LogNSGen::Node::batchId);
    }
};

// level
template<>
struct RecordFieldTraits<RecordTraits<LogNSGen::Node>::LEVEL, LogNSGen::Node>
{
    typedef I16u FieldType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefSetter FieldSetterType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefGetter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&LogNSGen::Node::level);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&LogNSGen::Node::level);
    }
};

// label
template<>
struct RecordFieldTraits<RecordTraits<LogNSGen::Node>::LABEL, LogNSGen::Node>
{
    typedef Enum FieldType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefSetter FieldSetterType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefGetter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&LogNSGen::Node::label);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&LogNSGen::Node::label);
    }
};

// parent_id
template<>
struct RecordFieldTraits<RecordTraits<LogNSGen::Node>::PARENT_ID, LogNSGen::Node>
{
    typedef I64u FieldType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefSetter FieldSetterType;
    typedef MethodTraits<LogNSGen::Node, FieldType>::RefGetter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&LogNSGen::Node::parentId);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&LogNSGen::Node::parentId);
    }
};

} // namespace Myriad

#endif /* BASENODEUTIL_H_ */
