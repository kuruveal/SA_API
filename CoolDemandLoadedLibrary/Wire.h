#pragma once
#include "CoolDemandLoadedLibraryExports.h"
#include "RoutingFeature.h"
#include <iostream>
#include <fstream>


void ReadInWire(std::ifstream& streamObject);

class COOLDEMANDLOADEDLIBRARY_API IWire
{
public:
	virtual std::string GetVersion() = 0;

};

class COOLDEMANDLOADEDLIBRARY_API Wire : public RoutingFeature, public IWire
{
public:
	Wire(std::string distance);
	std::string GetVersion() override;

	const std::string& GetDistance()
	{
		return m_distance;
	};


private:
	std::string m_distance;

};




