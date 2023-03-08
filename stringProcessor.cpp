#include "stringProcessor.h"
#include <fstream>

std::string lang = "C:/Coding/cpp projects/Smart Tables/Resources/lang/rus.txt";

std::string parseText(int stringNum, std::string path)
{
	using namespace std;

	ifstream fin(path);
	string result, thrash;
	int strNumber;

	while (!fin.eof())
	{
		fin >> strNumber;
		fin.get();

		if (strNumber == stringNum)
		{
			getline(fin, result);
			break;
		}
		else
			getline(fin, thrash);
	}
	
	return result;
}
