#include "RoutingFeature.h"
#include "Wire.h"


using namespace std;

void ProcessRoutingFeature(std::string featureType, std::ifstream& streamObject)
{

	if (featureType == "Wire")
	{
		ReadInWire(streamObject);
	}


}
