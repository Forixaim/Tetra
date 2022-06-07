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
	Token = InputPassword;
}

BotInfo::~BotInfo()
{
	std::cout << "Tetra has been deactivated.\n";
}