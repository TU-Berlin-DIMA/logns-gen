// auto-generatad C++ file for `node`

#ifndef BASENODEMETA_H_
#define BASENODEMETA_H_

#include "record/AbstractRecord.h"

namespace LogNSGen {

// forward declarations
class Node;

class BaseNodeMeta : public Myriad::RecordMeta<Node>
{
public:

    BaseNodeMeta(const Myriad::EnumSetPool& enumSets) : 
        label(enumSets.get("node.label").values())
    {
    }

    // enum set refecences
    const vector<String>& label;
};

} // namespace LogNSGen

#endif /* BASENODEMETA_H_ */
