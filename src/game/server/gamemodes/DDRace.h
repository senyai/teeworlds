/* copyright (c) 2007 rajh and gregwar. Score stuff */

#ifndef DDRACE_H
#define DDRACE_H
#include <game/server/gamecontroller.h>
#include <game/server/teams.h>
#include <game/server/entities/door.h>
#include <game/server/entities/trigger.h>

#include <vector>


class CGameControllerDDRace : public IGameController
{
	vec2 *m_pTele1D;
	int m_TotalTele;
	int m_ArraySize;
public:
	
	CGameControllerDDRace(class CGameContext *pGameServer);
	~CGameControllerDDRace();
	
	CGameTeams m_Teams;

	int *m_pNumTele;
	vec2 **m_pTele2D;
	
	void InitTeleporter();
	void InitSwitcher();
	int m_Size;

	struct SDoors
	{
		int m_Number;
		vec2 m_Pos;
		CDoor * m_Address;
	};

	std::vector < SDoors > m_SDoors;

	virtual void Tick();
};
#endif
