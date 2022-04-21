// CoolDemandLoadedLibrary.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "CoolDemandLoadedLibrary.h"


// This is an example of an exported variable
COOLDEMANDLOADEDLIBRARY_API int nCoolDemandLoadedLibrary=0;

// This is an example of an exported function.
COOLDEMANDLOADEDLIBRARY_API int fnCoolDemandLoadedLibrary(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CCoolDemandLoadedLibrary::CCoolDemandLoadedLibrary()
{
    return;
}
