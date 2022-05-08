#pragma once
#include <dpp/dpp.h>


class PlayerData
{
private:
	std::vector<long> UniqueIds;
	std::vector<dpp::snowflake> UserIds;
	std::vector<short> Warns;
	long ID = 0;
	std::fstream PlayerDataFiles;
public:
	auto GetIndex(std::vector<int> InputVector, int Id) -> long;
	auto GetIndex(std::vector<dpp::snowflake> InputVector, dpp::snowflake UserId) -> long;
	PlayerData();
	~PlayerData();
	auto GetWarns(dpp::snowflake PlayerID) -> int;
	void NewPlayer(dpp::snowflake UserID);
};

