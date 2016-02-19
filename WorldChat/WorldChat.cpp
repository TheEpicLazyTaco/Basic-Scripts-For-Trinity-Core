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

		Player* plr = handler->GetSession()->GetPlayer();

		std::string message;
		std::ostringstream cstring;
		message = args;

		if (plr->isGMChat())
			cstring << "|cfffebfbe[World] |TInterface\\ChatFrame\\UI-ChatIcon-Blizz.blp:0:2:0:-3|t [" << plr->GetName() << "]: " << message;
		else
			cstring << "|cfffebfbe[World] [" << plr->GetName() << "]: " << message;

		char mess[255];
		snprintf(mess, 255, cstring.str().c_str());
		sWorld->SendGlobalText(mess, NULL);

		return true;
	}
};

void AddSC_worldChat()
{
	new worldChat();
}