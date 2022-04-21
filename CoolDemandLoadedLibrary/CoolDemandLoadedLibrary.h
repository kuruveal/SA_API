#pragma once

#include "CoolDemandLoadedLibraryExports.h"

// This class is exported from the dll
class COOLDEMANDLOADEDLIBRARY_API CCoolDemandLoadedLibrary {
public:
	CCoolDemandLoadedLibrary(void);
	// TODO: add your methods here.
};

extern COOLDEMANDLOADEDLIBRARY_API int nCoolDemandLoadedLibrary;

COOLDEMANDLOADEDLIBRARY_API int fnCoolDemandLoadedLibrary(void);
