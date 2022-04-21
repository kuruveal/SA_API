#pragma once

#include "Feature.h"

#include <iostream>
#include <fstream>


void ProcessBlock(std::ifstream& streamObject);

class APPLIBRARY_API Block : public Feature
{
};
