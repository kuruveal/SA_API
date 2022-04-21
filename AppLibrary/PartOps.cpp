#include "PartOps.h"
#include <iostream>
#include "..\Journaling\Journaling.h"
#include "..\Core\GuidObject.h"
#include "Feature.h"
#include "..\Core\StringUtils.h"

using namespace std;

PartFile* Journaling_OpenPart(std::string partFilePath)
{
	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("OpenPart", JournalCallData::CannedGlobals::SESSION);
		JournalStringInParam(partFilePath, "partFilePath");
	}
	PartFile* retVal = nullptr;
	retVal = PartFile::OpenPartFile(partFilePath);

	if (IsJournaling())
	{
		JournalReturnClass(retVal, "AutomationAPI::Part", "Part");
		JournalEndCall();
	}

	return retVal;

}

PartFile* Journaling_MakePart(std::string partFilePath)
{
	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("MakePart", JournalCallData::CannedGlobals::SESSION);
		JournalStringInParam(partFilePath, "partFilePath");
	}
	PartFile* retVal = nullptr;
	retVal = PartFile::CreatePartFile(partFilePath);

	if (IsJournaling())
	{
		JournalReturnClass(retVal, "AutomationAPI::Part", "Part");
		JournalEndCall();
	}

	return retVal;

}

void Journaling_Part_Save(PartFile* partFile)
{


	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("Save", partFile);
	}
	partFile->SavePart();

	if (IsJournaling())
	{
		JournalEndCall();
	}

}

void Journaling_Part_MakeWidgetFeature(PartFile* partFile, bool option1, int values)
{

	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("MakeWidgetFeature", partFile);
		JournalBoolInParam(option1, "option1");
		JournalIntInParam(values, "values");
	}
	partFile->MakeWidgetFeature(option1, values);

	if (IsJournaling())
	{
		JournalEndCall();
	}
	
}

PartFile::PartFile(std::string partFilePath, int guid) : GuidObject(guid),  m_partFilePath(partFilePath)
{
	cout << "    PartFile::PartFile called with " << partFilePath << " " << guid << endl;
}



void PartFile::SavePart()
{
	cout << "    PartFile::SavePart called" << endl;
}

void PartFile::MakeWidgetFeature(bool option1, int values)
{
	cout << "    MakeWidgetFeature called with " << option1 << " " << values << endl;
}

PartFile* PartFile::CreatePartFile(std::string partFilePath)
{
	int guid = 123424; 

	PartFile* partFile = new PartFile( partFilePath, guid);
	GuidObjectManager::GetGuidObjectManager().SetObjectFromGUID(guid, partFile);
	
	return partFile;
}

PartFile* PartFile::OpenPartFile(std::string partFilePath)
{
	int guid = -1;
	
	ReadInPartFile(guid, partFilePath);


	PartFile* partFile = new PartFile(partFilePath, guid);
	GuidObjectManager::GetGuidObjectManager().SetObjectFromGUID(guid, partFile);

	return partFile;
}



std::string PartFileNameToken = "PartFileName:";
std::string SchemaVersionToken = "SchemaVersion:";



void ReadInPartFile(int & guid, std::string partFilePath)
{
	guid = 54321;
	string line;
	ifstream localPartFile(partFilePath);
	if (localPartFile.is_open())
	{
		while (getline(localPartFile, line))
		{
			cout << line << '\n';

			if (startsWith(line, PartFileNameToken))
			{
				std::string partFileName = line.substr(PartFileNameToken.size(), line.size() - PartFileNameToken.size());
				cout << "    "<< PartFileNameToken << " " << partFileName << endl;
			}
			else if (startsWith(line, SchemaVersionToken))
			{
				std::string partFileName = line.substr(SchemaVersionToken.size(), line.size() - SchemaVersionToken.size());
				cout << "    "<< SchemaVersionToken <<" " << partFileName << endl;
			}
			else if(startsWith(line, FeatureToken))
			{
				std::string featureType = line.substr(FeatureToken.size(), line.size() - FeatureToken.size());
				ProcessFeature(featureType, localPartFile);
			}


		}
		localPartFile.close();
	}


}













