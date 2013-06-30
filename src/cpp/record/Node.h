#ifndef NODE_H_
#define NODE_H_

#include "record/base/BaseNode.h"

namespace LogNSGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Node: public BaseNode
{
public:

    Node(const NodeMeta& meta)
        : BaseNode(meta)
    {
    }

};

} // namespace LogNSGen

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void AbstractOutputCollector<LogNSGen::Node>::serialize(std::ostream& out, const LogNSGen::Node& record)
{
    AbstractOutputCollector<LogNSGen::BaseNode>::serialize(out, record);
}

} // namespace Myriad

#endif /* NODE_H_ */
