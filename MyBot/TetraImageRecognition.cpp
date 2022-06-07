#include "TetraImageRecognition.h"

bool TetraImageRecognition::RecognizeBadWords(std::string Text)
{
	std::regex bw0("social credit", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_match(Text, bw0))
	{
		std::cout << "Bad Words Found!\n";
		return false;
	}
	std::regex bw1("dick", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_match(Text, bw1))
	{
		std::cout << "Bad Words Found!\n";
		return false;
	}
	std::regex bw2("cum", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_match(Text, bw2))
	{
		std::cout << "Bad Words Found!\n";
		return false;
	}
	std::regex bw3("tits", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_match(Text, bw3))
	{
		std::cout << "Bad Words Found!\n";
		return false;
	}
	std::regex bw4("nigga", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_match(Text, bw4))
	{
		std::cout << "Bad Words Found!\n";
		return false;
	}
	std::regex bw5("faggot", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_match(Text, bw5))
	{
		std::cout << "Bad Words Found!\n";
		return false;
	}
	std::regex bw6("fag", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_match(Text, bw6))
	{
		std::cout << "Bad Words Found!\n";
		return false;
	}
	return true;
}

TetraImageRecognition::TetraImageRecognition()
{
	std::cout << "Constructed\n";
}

TetraImageRecognition::~TetraImageRecognition()
{
	std::cout << "Destructed\n";
}