/*
	The custom function is kinda pointless here.
	However i figured it would make a good example.
	As custom functions are amazing for shorting code and keeping your scripts cleaner.
*/

#include "ScriptMgr.h"
#include "Player.h"

class welcomeOnFirstLogin : public PlayerScript
{
public:
	welcomeOnFirstLogin() : PlayerScript("welcomeOnFirstLogin") {}

	// This is a custom function that is void meaning it returns nothing just executes what it is told to do.
	void sendMessage(Player* plr)
	{
		std::ostringstream myString;
		std::string color, serverName, plrName;

		color = "|cffffffff";
		serverName = "ChangeMe";
		plrName = plr->GetName().c_str();
		// Here is where we build the message the message is set to be only 255 characters long which is the normal size of a player message I believe. 
		// So you need to keep your message below that or change it.
		myString << color << plrName << ", Welcome to " << serverName << "!|r";

		// This is where the message is sent to the world.
		sWorld->SendServerMessage(SERVER_MSG_STRING, myString.str().c_str(), 0);
	}

	// This is the function that is called when a player logs in.
	void OnLogin(Player* plr, bool firstLogin)
	{
		// This tells the script if this is a players first time logging in.
		if (firstLogin)
		{
			// Calls our custom function to send the message without calling it the function is never used that is why we need to do this.
			sendMessage(plr);
		}
	}
};

void AddSC_welcomeOnFirstLogin()
{
	new welcomeOnFirstLogin();
}