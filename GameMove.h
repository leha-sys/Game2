#pragma once

#ifndef _GAMEMOVE_H
#define _GAMEMOVE_H

#include "GameData.h"

void ClearDoors()
{
	EastTile = NULL;
	WestTile = NULL;
	NorthTile = NULL;
	SouthTile = NULL;
}

void LookForDoors(Player *player)
{
	ClearDoors();

	if (player->currentTile->EastTile != NULL)
	{
		EastTile = player->currentTile->EastTile;
	}
	if (player->currentTile->WestTile != NULL)
	{
		WestTile = player->currentTile->WestTile;
	}
	if (player->currentTile->NorthTile != NULL)
	{
		NorthTile = player->currentTile->NorthTile;
	}
	if (player->currentTile->SouthTile != NULL)
	{
		SouthTile = player->currentTile->SouthTile;
	}
}

void ShowDoors()
{
	std::cout << "\n" << std::endl;
	if (EastTile != NULL)
	{
		std::cout << "  There is a door to the East." << std::endl;
	}
	if (WestTile != NULL)
	{
		std::cout << "  There is a door to the West." << std::endl;
	}
	if (NorthTile != NULL)
	{
		std::cout << "  There is a door to the North." << std::endl;
	}
	if (SouthTile != NULL)
	{
		std::cout << "  There is a door to the South." << std::endl;
	}
}

int AskWhichDirection()
{
	std::string dir;
	std::cout << "\n Which way do you want to go?" << std::endl;
	std::cin >> dir;

	std::transform(dir.begin(), dir.end(), dir.begin(), ::tolower);
	if (dir == "east" && EastTile != NULL)
	{
		std::cout << " Moving East!" << std::endl;
		return EAST;
	}
	if (dir == "west" && WestTile != NULL)
	{
		std::cout << " Moving West!" << std::endl;
		return WEST;
	}
	if (dir == "north" && NorthTile != NULL)
	{
		std::cout << " Moving North!" << std::endl;
		return NORTH;
	}
	if (dir == "south" && SouthTile != NULL)
	{
		std::cout << " Moving South!" << std::endl;
		return SOUTH;
	}
	return NODOOR;
}

void ChangeTiles(Player *player, int door)
{
	switch (door)
	{
	case EAST:
		player->currentTile->EastTile;
		break;
	case WEST:
		player->currentTile->WestTile;
		break;
	case NORTH:
		player->currentTile->NorthTile;
		break;
	case SOUTH:
		player->currentTile->SouthTile;
		break;
	default:
		std::cout << " There isn't a door there." << std::endl;
		break;
	}
}

#endif