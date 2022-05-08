#include "BotInfo.h"
#include <iostream>

auto BotInfo::GetToken() -> std::string
{
	return Token;
}

auto BotInfo::GetGuildId() -> dpp::snowflake
{
	return Guild;
}

BotInfo::BotInfo(std::string InputPassword)
{
	if (InputPassword == Password)
	{
		std::cout << "Authentication Success! Tetra's credentials has been assigned.\n";
	}
	else
	{
		throw "Authentication Failure, You stink";
		exit(1);
	}

}

BotInfo::~BotInfo()
{
	std::cout << "Tetra has been deactivated.\n";
}