#pragma once

#include "AutomationBinding.h"
#include <string>


namespace AutomationAPI
{
	class Part;
	class AUTOMATIONBINDING_API Session
	{
		public :
			static Session* GetSession();

			/**
			*<summary> Generates the Part File at the path specificed</summary>
			* To save the part afterward  use [Part.Save()](@ref Part.Save())
			*/
			Part* MakePart(std::string partFilePath);

			/**
			* <summary>Opens an existing the Part File at the path specificed</summary>
			* To save the part afterware use [Save Method](@ref Part.Save())

			*/
			Part* OpenPart(std::string partFilePath);

		private:
			Session() = default;
			virtual ~Session();
			Session(const Session&) = delete;
			Session& operator=(const Session&) = delete;
	};

}


