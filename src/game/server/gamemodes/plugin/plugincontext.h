/* hello plugin system */
#ifndef GAME_SERVER_GAMEMODES_PLUGIN_PLUGINCONTEXT_H
#define GAME_SERVER_GAMEMODES_PLUGIN_PLUGINCONTEXT_H

#include <game/server/gamecontext.h>

class CPluginContext : public CGameContext
{
public:
    void OnClientEnter(int ClientID);
    void OnClientConnected(int ClientID);
};

typedef CPluginContext CGameContextCass;
#endif