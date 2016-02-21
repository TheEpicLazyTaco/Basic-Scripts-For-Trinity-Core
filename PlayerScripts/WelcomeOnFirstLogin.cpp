/*
	The custom function is kinda pointless here.
	However i figured it would make a good example.
	As custom functions are amazing for shorting code and keeping your scripts cleaner.
	Please note that atm the message is colorless and will be sent out as default which is yellow. 
	The message will send before the players enter any chat channels and after the motd. So look for it there.
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
		std::string plrName;

		// Here we are setting the variable to the players name get function for easy use.
		plrName = plr->GetName().c_str();
		// Here is where we build the string.
		myString << "We welcome our new player " << plrName << "!";
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