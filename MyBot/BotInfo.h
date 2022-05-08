#pragma once
#include <dpp/dpp.h>

class BotInfo
{
private:
	const std::string Token = "OTU3NDExNDc5NjY4MjYwODg0.Yj-Y7A.MYgeRFGxlBQdORIc247oU-K_SCE";
	const dpp::snowflake Guild = 941463674361622578;
	const std::string Password = "Forixaim#3810";
public:
	auto GetToken() -> std::string;
	auto GetGuildId() -> dpp::snowflake;
	BotInfo(std::string InputPassword);
	/**
	 * \Destructor
	 */
	~BotInfo();
};

