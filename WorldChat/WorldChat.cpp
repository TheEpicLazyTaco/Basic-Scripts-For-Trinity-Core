#include "ScriptMgr.h"
#include "Chat.h"
#include "Player.h"

class worldChat : public CommandScript
{
public:
	worldChat() : CommandScript("worldChat") { }

	std::vector<ChatCommand> GetCommands() const override
	{
		static std::vector<ChatCommand> commandTable =
		{
			{ "w", rbac::RBAC_PERM_COMMAND_CHAT, false, &HandleChatCommand, "" },
			{ "world", rbac::RBAC_PERM_COMMAND_CHAT, false, &HandleChatCommand, "" },
		};
		return commandTable;
	}

	static bool HandleChatCommand(ChatHandler * handler, char const* args)
	{
		if (!*args)
			return false;

		// This gives us a variable to use instead of typing it out the entire thing over and over. 
		// Which might be a lil dumb here because i only use it once. But who knows maybe you will edit this script and use it.
		Player* plr = handler->GetSession()->GetPlayer();

		// Our other variables.
		std::string plrName, color, message;
		std::ostringstream myString;

		// Here we are setting the variable to the players name get function for easy use.
		plrName = plr->GetName().c_str();
		// This is the color variable Change this if you want to change the color of the messages.
		color = "|cfffebfbe";
		// This just tells the script to assign the text players type to the message variable so we can use it.
		message = args;

		// This is where we build our string to send to the world.
		if (plr->isGMChat())
			myString << color << "[World] |TInterface\\ChatFrame\\UI-ChatIcon-Blizz.blp:0:2:0:-3|t [" << plrName << "]: " << message;
		else
			myString << color << "[World] [" << plrName << "]: " << message;

		// This is where the message is sent to the world.
		sWorld->SendServerMessage(SERVER_MSG_STRING, myString.str().c_str(), 0);
		return true;
	}
};

void AddSC_worldChat()
{
	new worldChat();
}