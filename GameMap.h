#pragma once

#ifndef _GAMEMAP_H
#define _GAMEMAP_H

#include <algorithm>
#include "GameData.h"

void CreateMap3x1() {
	//Tile 1
	GameMap3x1.push_back(GameTile{ 0, 0, false, "A well lit room." });
	GameMap3x1[0].EntityList.push_back(new Shrine("Health Shrine", 0, 0, false));

	//Tile 2
	GameMap3x1.push_back(GameTile{ 0, 0, false, "Dark room." });
	GameMap3x1[1].EntityList.push_back(new Enemy("Slime", 30, 10, true));

	//Tile 3
	GameMap3x1.push_back(GameTile{ 0, 0, true, "You escape." });

	//Tile 4
	GameMap3x1.push_back(GameTile{ 0, 0, false, "Very dark room." });
	GameMap3x1[3].EntityList.push_back(new Enemy("Monster", 10, 10, true));

	//Tile 5
	GameMap3x1.push_back(GameTile{ 0, 0, false, "Underground." });
	GameMap3x1[4].EntityList.push_back(new Enemy("Great Monster", 30, 30, true));

	GameMap3x1[0].EastTile = &GameMap3x1[1];
	GameMap3x1[1].WestTile = &GameMap3x1[0];
	GameMap3x1[1].EastTile = &GameMap3x1[2];

	GameMap3x1[0].NorthTile = &GameMap3x1[3];
	GameMap3x1[3].SouthTile = &GameMap3x1[0];

	GameMap3x1[0].SouthTile = &GameMap3x1[4];
	GameMap3x1[4].NorthTile = &GameMap3x1[0];
}

#endif