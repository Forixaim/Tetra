#include "PlayerData.h"
#include <fstream>



auto GetIndex(std::vector<int> InputVector, int Id) -> long
{
    auto const Person = find(InputVector.begin(), InputVector.end(), Id);

    // If element was found
    if (Person != InputVector.end())
    {

        // calculating the index
        // of K
        const long Index = Person - InputVector.begin();
        return Index;
    }
    else 
    {
        std::cout << "Player Not Found!\n";
        return -1;
    }
}

auto GetIndex(std::vector<dpp::snowflake> InputVector, dpp::snowflake UserId) -> long
{
    auto const Person = find(InputVector.begin(), InputVector.end(), UserId);

    // If element was found
    if (Person != InputVector.end())
    {

        // calculating the index
        // of K
        const long Index = Person - InputVector.begin();
        return Index;
    }
    else
    {
        std::cout << "Player Not Found!\n";
        return -1;
    }
}

auto PlayerData::GetWarns(dpp::snowflake PlayerID) -> int
{
	return Warns.at(PlayerID);
}

PlayerData::PlayerData()
{

}

PlayerData::~PlayerData()
{

}

auto PlayerData::NewPlayer(dpp::snowflake UserID) -> void
{
	UniqueIds.push_back(ID);
	ID++;
	UserIds.push_back(UserID);
    PlayerDataFiles.open( "PlayerBase.txt");
    PlayerDataFiles << std::to_string(ID) << std::to_string(UserID) << "\n";
    PlayerDataFiles.close();
}
