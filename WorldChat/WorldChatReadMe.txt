This script is a very simple world chat script which you would add like any other custom script however you also need to do the following steps.

0. After adding the script to cmakelist.txt and scriptloader.cpp
1. Open RBAC.H which is located in src\server\game\Accounts.
2. Search the file for RBAC_PERM_MAX.
3. Above RBAC_PERM_MAX add the following line
    RBAC_PERM_COMMAND_CHAT = 1001,
4. Save the file.
5. You may now compile your source.
6. While your waiting for that find the file called WorldChatPermissions.sql
7. Execute that inside of your auth database.

Now your done and the world chat should work.