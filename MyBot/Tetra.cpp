#include "Tetra.h"

using std::string, dpp::snowflake, dpp::cluster;

std::string Password;

int main()
{
	std::cout << "Authentication Password: ";
	std::cin >> Password;
	std::unique_ptr<BotInfo> const Tetra(new BotInfo(Password));
	std::unique_ptr<PlayerData> const TetraPlayerDatabase(new PlayerData());
	std::unique_ptr<TetraImageRecognition> const ImageRecognition(new TetraImageRecognition());
	
	/* Create bot cluster */
	cluster bot(Tetra->GetToken(), dpp::i_all_intents);

	/* Output simple log messages to stdout */
	bot.on_log(dpp::utility::cout_logger());

	/* Handle slash command */
	bot.on_slashcommand([&bot](const dpp::slashcommand_t& event)
	{
		if (event.command.get_command_name() == "speak") 
		{
			std::string Msg = std::get<std::string>(event.get_parameter("msg"));
			dpp::message myMessage;
			myMessage.content = Msg;
			myMessage.channel_id = event.command.channel_id;
			bot.message_create(myMessage);
			event.cancel_event();
		}
	});
	/* Register slash command here in on_ready */
	bot.on_ready([&bot, &TetraPlayerDatabase](const dpp::ready_t& event) 
	{
		/* Wrap command registration in run_once to make sure it doesn't run on every full reconnection */
		if (dpp::run_once<struct register_bot_commands>()) 
		{
			dpp::slashcommand speak("speak", "say something", bot.me.id);
			speak.add_option(dpp::command_option(dpp::co_string, "msg", "msg to send", true));

			bot.global_command_create(speak);
		}
		if (dpp::run_once<struct RegisterFounder>())
		{
			TetraPlayerDatabase->NewPlayer(309542897743691782);
		}
	});
	bot.on_message_create([&bot, &ImageRecognition](const dpp::message_create_t &event)
	{
		if (event.msg.author.is_bot())
		{
			std::cout << "Bot detected ignoring";
		}
		else
		{
			std::cout << "Message Event Got!" << std::endl;
			if (!event.msg.attachments.empty())
			{
				std::cout << "No Attachments Found!" << std::endl;
			}
			if (event.msg.attachments.size() > 3)
			{
				dpp::guild_member target = dpp::find_guild_member(event.msg.guild_id, event.msg.author.id);
				auto adminrole = [](int i)
				{
					return i = 820863249834442754;
				};
				auto admin = std::find_if(target.roles.begin(), target.roles.end(), adminrole);
				if (admin != target.roles.end())
				{
					std::cout << "Sorry admins for ruining your day.\n";
				}
				else
				{
					event.reply("Your message was automatically deleted due to posting more than 3 attachments.", true);
					bot.message_delete(event.msg.id, event.msg.channel_id);
				}
			}
			if (!ImageRecognition->RecognizeBadWords(event.msg.content))
			{
				event.reply("Your message was automatically deleted due to inappropriate language.", true);
				bot.message_delete(event.msg.id, event.msg.channel_id);
			}
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
