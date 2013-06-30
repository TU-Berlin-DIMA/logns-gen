// auto-generatad base generator config C++ file

#include "generator/base/BaseGeneratorSubsystem.h"
#include "generator/NodeGenerator.h"

using namespace std;
using namespace Poco;

namespace Myriad {

// the initial stage ID should always be zero
I32u AbstractSequenceGenerator::Stage::NEXT_STAGE_ID = 0;

// register the valid stages for the Myriad generator extension
AbstractSequenceGenerator::StageList initList()
{
    AbstractSequenceGenerator::StageList tmp;

    tmp.push_back(AbstractSequenceGenerator::Stage("node"));

    return tmp;
}

const AbstractSequenceGenerator::StageList AbstractSequenceGenerator::STAGES(initList());

// register the record sequence generators
void BaseGeneratorSubsystem::registerGenerators()
{
    registerGenerator<LogNSGen::NodeGenerator>("node");
}

} // namespace Myriad
