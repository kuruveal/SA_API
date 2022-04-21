#include "Wire.h"
#include "WireVersions.h"
#include <fstream>
#include "..\Core\StringUtils.h"
#include "..\DataReader\DataObjectReader.h"
#include "..\DataReader\\DataReaderRegistrant.h"

using namespace std;

std::string Wire_VersionToken = "Wire_Version:";
std::string Wire_DistanceToken = "Wire_Distance:";


void* ReadWireVersion2(std::ifstream& streamObject);
void* ReadWireVersion3(std::ifstream& streamObject);

Wire* VersionUpWireVersion2(Wire2 *oldFeature);

static DataReaderRegistrant wire2registrant("Wire2", ReadWireVersion2);
static DataReaderRegistrant wire3registrant("Wire3", ReadWireVersion3);



Wire::Wire(std::string distance)
	: m_distance(distance)
{

}
std::string Wire::GetVersion()
{
	return "3";
}

void ReadInWire(std::ifstream& streamObject)
{

	cout << "    ProcessWire" << endl;
	string line;
	getline(streamObject, line);

	//IExtrude* extrudeReadIn = nullptr;
	void* wireReadIn = nullptr;

	std::string version = line.substr(Wire_VersionToken.size(), line.size() - Wire_VersionToken.size());
	cout << "    " << Wire_VersionToken << " " << version << endl;

	std::string WireVersionToken = "Wire" + version;

	dataReaderFunction readerFunc = nullptr;

	readerFunc = DataObjectReader::GetInstance().GetReader(WireVersionToken);

	if (readerFunc != nullptr)
	{
		wireReadIn = readerFunc(streamObject);
	}


	IWire* wireReadInterface = (IWire*)wireReadIn;

	Wire* retVal = dynamic_cast<Wire*>(wireReadInterface);

	if (dynamic_cast<Wire*>(wireReadInterface) == nullptr)
	{
		if (version == "1")
		{

		}
		else if (version == "2")
		{
			Wire2* wireVersion2 = dynamic_cast<Wire2*>(wireReadInterface);
			retVal = VersionUpWireVersion2(wireVersion2);
		}
		// need to upgrade to latest Version
		
	}
	else
	{
		return; // We woudl probably like to return this retVal
	}

}

void * ReadWireVersion2(std::ifstream& streamObject)
{
	string line;

	std::string distance;


	bool done = false;
	while (!done)
	{
		getline(streamObject, line);
		cout << line << '\n';



		if (startsWith(line, EndRoutingFeatureToken))
		{
			done = true;
		}

		else if (startsWith(line, Wire_DistanceToken))
		{
			distance = line.substr(Wire_DistanceToken.size(), line.size() - Wire_DistanceToken.size());
			cout << "    " << Wire_DistanceToken << " " << distance << endl;
		}

	}

	// TODO no validation we read in all the right fields 

	return new Wire2(distance);

}


void * ReadWireVersion3(std::ifstream& streamObject)
{

	throw new exception("NIY");

	return nullptr;

}


Wire* VersionUpWireVersion2(Wire2 * oldFeature)
{
	Wire* retval = nullptr;

	//Old Items
	const std::string distance = oldFeature->GetDistance();

	//New Items
	std::string isAddition;
	std::string isSubtraction;

	cout << "    VersionUpExtrudeVersion2" <<  endl;


	retval = new Wire(distance);

	return retval;

}
