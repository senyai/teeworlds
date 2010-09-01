#ifndef GAME_SERVER_GAMEWORLD_H
#define GAME_SERVER_GAMEWORLD_H

#include <game/gamecore.h>
#include <list>

class CEntity;
class CCharacter;

/*
	Class: Game World
		Tracks all entities in the game. Propagates tick and
		snap calls to all entities.
*/
class CGameWorld
{
	void Reset();
	void RemoveEntities();

	enum
	{
		NUM_ENT_TYPES=10, // TODO: are more exact value perhaps? :)
	};

	// TODO: two lists seams kinda not good, shouldn't be needed
	CEntity *m_pFirstEntity;
	CEntity *m_apFirstEntityTypes[NUM_ENT_TYPES];
	
	class CGameContext *m_pGameServer;
	class IServer *m_pServer;

public:
	class CGameContext *GameServer() { return m_pGameServer; }
	class IServer *Server() { return m_pServer; }

	bool m_ResetRequested;
	bool m_Paused;
	CWorldCore m_Core;
	
	CGameWorld();
	~CGameWorld();
	
	void SetGameServer(CGameContext *pGameServer);
	
	CEntity *FindFirst() { return m_pFirstEntity; }
	CEntity *FindFirst(int Type);
	
	/*
		Function: find_entities
			Finds entities close to a position and returns them in a list.
			
		Arguments:
			pos - Position.
			radius - How close the entities have to be.
			ents - Pointer to a list that should be filled with the pointers
				to the entities.
			max - Number of entities that fits into the ents array.
			type - Type of the entities to find. -1 for all types.
			
		Returns:
			Number of entities found and added to the ents array.
	*/
	int FindEntities(vec2 Pos, float Radius, CEntity **ppEnts, int Max, int Type = -1);

	/*
		Function: InterserctCharacters
			Finds the CCharacters that intersects the line. // made for types lasers=1 and doors=0

		Arguments:
			pos0 - Start position
			pos2 - End position
			radius - How for from the line the CCharacter is allowed to be.
			new_pos - Intersection position
			notthis - Entity to ignore intersecting with

		Returns:
			Returns a pointer to the closest hit or NULL of there is no intersection.
	*/
	class CCharacter *IntersectCharacter(vec2 Pos0, vec2 Pos1, float Radius, vec2 &NewPos, class CEntity *pNotThis = 0);
	
	/*
		Function: closest_CCharacter
			Finds the closest CCharacter to a specific point.
			
		Arguments:
			pos - The center position.
			radius - How far off the CCharacter is allowed to be
			notthis - Entity to ignore
			
		Returns:
			Returns a pointer to the closest CCharacter or NULL if no CCharacter is close enough.
	*/
	class CCharacter *ClosestCharacter(vec2 Pos, float Radius, CEntity *ppNotThis);

	/*
		Function: insert_entity
			Adds an entity to the world.
			
		Arguments:
			entity - Entity to add
	*/
	void InsertEntity(CEntity *pEntity);

	/*
		Function: remove_entity
			Removes an entity from the world.
			
		Arguments:
			entity - Entity to remove
	*/
	void RemoveEntity(CEntity *pEntity);

	/*
		Function: destroy_entity
			Destroys an entity in the world.
			
		Arguments:
			entity - Entity to destroy
	*/
	void DestroyEntity(CEntity *pEntity);
	
	/*
		Function: snap
			Calls snap on all the entities in the world to create
			the snapshot.
			
		Arguments:
			snapping_client - ID of the client which snapshot
			is being created.
	*/
	void Snap(int SnappingClient);
	
	/*
		Function: tick
			Calls tick on all the entities in the world to progress
			the world to the next tick.
		
	*/
	void Tick();
	
	/*
		Function: interserct_CCharacter
			Finds all CCharacters that intersect the line.
			
		Arguments:
			pos0 - Start position
			pos2 - End position
			radius - How for from the line the CCharacter is allowed to be.
			new_pos - Intersection position
			notthis - Entity to ignore intersecting with
			
		Returns:
			Returns list with all Characters on line.
	*/
	std::list<class CCharacter *> IntersectedCharacters(vec2 Pos0, vec2 Pos1, float Radius, vec2 &NewPos, class CEntity *pNotThis = 0);
};

#endif
