#include "WireVersions.h"


Wire2::Wire2(std::string distance)
	: m_distance(distance)
{

}

std::string Wire2::GetVersion()
{
	return "2";
}