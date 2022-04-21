#include "Feature.h"
#include "Block.h"
#include "Extrude.h"

using namespace std;

void ProcessFeature(std::string featureType, std::ifstream& streamObject)
{

	if (featureType == "Extrude")
	{
		ReadInExtrude(streamObject);
	}
	else if (featureType == "Block")
	{
		ProcessBlock(streamObject);
	}

}
