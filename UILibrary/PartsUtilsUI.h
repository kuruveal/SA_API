#pragma once

#include <string>
#include "..\AppLibrary\PartOps.h"



PartFile* OpenPartUI(std::string);

PartFile* MakePartUI(std::string);

void SavePartUI(PartFile* partFile);


