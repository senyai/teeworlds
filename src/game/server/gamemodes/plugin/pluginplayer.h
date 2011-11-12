/* hello plugin system */
#ifndef GAME_SERVER_GAMEMODES_PLUGIN_PLUGINPLAYR_H
#define GAME_SERVER_GAMEMODES_PLUGIN_PLUGINPLAYR_H

#include<game/server/gamemodes/plugin/plugincontext.h>

class CPluginPlayer : public CPlayer
{
public:
    CPluginPlayer(CGameContext *pGameServer, int ClientID, int Team);
};

#endif