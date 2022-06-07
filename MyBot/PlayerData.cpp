#include "PlayerData.h"
#include <fstream>


PlayerData::PlayerData()
{

}

PlayerData::~PlayerData()
{
	PlayerDataFiles.open(R"(C:\Users\thebe\OneDrive\Documents\Tetra Database\PlayerData.txt)", std::ofstream::out | std::ofstream::trunc);
	PlayerDataFiles.close();
}

auto PlayerData::NewPlayer(dpp::snowflake UserID) -> void
{
	PlayerDataFiles.open(R"(C:\Users\thebe\OneDrive\Documents\Tetra Database\PlayerData.txt)");
	PlayerDataFiles << std::to_string(ID) << " " << std::to_string(UserID) << "\n";
	std::cout << "Successfully Wrote to PlayerBase.txt\n";
	PlayerDataFiles.close();
	ID++;
}
