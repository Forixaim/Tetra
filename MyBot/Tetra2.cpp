#include "Tetra.h"

using std::string, dpp::snowflake, dpp::cluster;

/* Be sure to place your token in the line below.
 * Follow steps here to get a token: https://dpp.dev/creating-a-bot-application.html
 * You will also need to fill in your guild id. When you invite the bot, be sure to
 * invite it with the scopes 'bot' and 'applications.commands', e.g.
 * https://discord.com/oauth2/authorize?client_id=940762342495518720&scope=bot+applications.commands&permissions=139586816064
 */
std::string Password;

int main()
{
    std::cout << "Authentication Password: ";
    std::cin >> Password;
    std::unique_ptr<BotInfo> const Tetra(new BotInfo(Password));
    std::unique_ptr<PlayerData> const TetraPlayerDatabase(new PlayerData());
    
    /* Create bot cluster */
    cluster bot(Tetra->GetToken());

    /* Output simple log messages to stdout */
    bot.on_log(dpp::utility::cout_logger());

    /* Handle slash command */
    bot.on_interaction_create([](const dpp::interaction_create_t& event) 
    {
        
    });

    /* Register slash command here in on_ready */
    bot.on_ready([&bot, &TetraPlayerDatabase](const dpp::ready_t& event) 
    {
        /* Wrap command registration in run_once to make sure it doesn't run on every full reconnection */
        if (dpp::run_once<struct register_bot_commands>()) 
        {
			
        }
    });
    bot.on_guild_member_add([&bot, &TetraPlayerDatabase](const dpp::guild_member_add_t& event)
    {
            TetraPlayerDatabase->NewPlayer(event.added.user_id);
    });
    

    /* Start the bot */
    bot.start(false);
    //Delete Pointers
    return 0;
}
