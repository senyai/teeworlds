/* hello plugin system */
#include<game/server/gamemodes/plugin/plugincontext.h>

void CPluginContext::OnClientEnter(int ClientID)
{
    CGameContext::OnClientEnter(ClientID);
    //SendChatTarget(ClientID, "Hello plugin");
};
