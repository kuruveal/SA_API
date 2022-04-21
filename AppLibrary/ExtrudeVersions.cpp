#include "ExtrudeVersions.h"


Extrude2::Extrude2(std::string distance, std::string targetFace, std::string vectorObject, std::string booleanType)
	: m_distance(distance), m_targetFace(targetFace), m_vectorObject(vectorObject), m_booleanType(booleanType)
{

}

std::string Extrude2::GetVersion()
{
	return "2";
}