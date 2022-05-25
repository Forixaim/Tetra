#pragma once
#include <dpp/dpp.h>

class PlayerData
{
private:
	std::map<dpp::snowflake, long> Player;
	long ID = 0;
	std::fstream PlayerDataFiles;
public:
	auto GetIndex(std::vector<int> InputVector, int Id) -> long;
	auto GetIndex(std::vector<dpp::snowflake> InputVector, dpp::snowflake UserId) -> long;
	PlayerData();
	~PlayerData();
	auto GetWarns(dpp::snowflake PlayerID) -> int;
	auto NewPlayer(dpp::snowflake UserID) -> void;
};

