#pragma once

#ifndef _GAMEMAP_H
#define _GAMEMAP_H

#include "GameData.h"

void CreateMap3x1()
{
	// Tile 1
	GameMap3x1.push_back(GameTile{ 0,0,false, "A well lit room with a strange statue in the center." });
	GameMap3x1[0].EntityList.push_back(new Shrine("Health Shrine", 0, 0, false));

	// Tile 2
	GameMap3x1.push_back(GameTile{ 0,0,false, "A damp vile room." });
	GameMap3x1[1].EntityList.push_back(new Enemy("Slime", 30, 10, false));

	// Tile 3
	GameMap3x1.push_back(GameTile{ 0,0,true, "You escape." });
	
	GameMap3x1[0].EastTile = &GameMap3x1[1];
	GameMap3x1[1].WestTile = &GameMap3x1[0];
	GameMap3x1[1].EastTile = &GameMap3x1[2];
}

#endif