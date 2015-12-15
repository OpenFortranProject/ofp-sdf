#include "SgUntypedNodes.hpp"

namespace sage {

SgUntypedFile::SgUntypedFile(sage::SgUntypedGlobalScope * SgUntypedGlobalScope)
{
   p_SgUntypedGlobalScope = SgUntypedGlobalScope;
}

SgUntypedFile:: ~SgUntypedFile()
{
   if (p_SgUntypedGlobalScope != NULL) delete p_SgUntypedGlobalScope;
}

} // namespace sage
