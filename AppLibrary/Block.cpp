#include "Block.h"
#include <fstream>
#include "..\Core\StringUtils.h"

using namespace std;

void ProcessBlock(std::ifstream& streamObject)
{
	cout << "    ProcessBlock" << endl;

	string line;
	bool done = false;
	while (!done)
	{
		getline(streamObject, line);
		cout << line << '\n';

		if (startsWith(line, EndFeatureToken))
		{
			done = true;
		}
		//else if (startsWith(line, ""))
		//{
		//	std::string partFileName = line.substr(EndFeatureToken.size(), line.size() - EndFeatureToken.size());
		//	cout << "    " << EndFeatureToken << " " << partFileName << endl;
		//}

	}
}