#pragma once
#include "AppLibrary.h"
#include "Feature.h"
#include <iostream>
#include <fstream>


void ReadInExtrude(std::ifstream& streamObject);

class APPLIBRARY_API IExtrude 
{
public:
	virtual std::string GetVersion() = 0;

};

class APPLIBRARY_API Extrude : public Feature, public IExtrude
{
public:
	Extrude(std::string distance, std::string targetFace, std::string vectorObject, std::string isAddition, std::string isSubtraction);
	std::string GetVersion() override;

	const std::string& GetDistance()
	{
		return m_distance;
	};
	const std::string & GetTargetFace()
	{
		return m_targetFace;
	};
	const std::string & GetVectorObject()
	{
		return m_vectorObject;
	};
	const std::string & GetIsAddition()
	{
		return m_isAddition;
	};
	const std::string & GetIsSubtraction()
	{
		return m_isSubtraction;
	};

private:
	std::string m_distance;
	std::string m_targetFace;
	std::string m_vectorObject;
	std::string m_isAddition;
	std::string m_isSubtraction;
};




