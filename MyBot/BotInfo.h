#pragma once
#include <dpp/dpp.h>

class BotInfo
{
private:
	std::string Token{};
	const dpp::snowflake Guild = 941463674361622578;
public:
	auto GetToken() -> std::string;
	auto GetGuildId() -> dpp::snowflake;
	BotInfo(std::string InputPassword);
	/**
	 * \Destructor
	 */
	~BotInfo();
};

