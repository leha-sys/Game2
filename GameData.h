#pragma once

#ifndef _GAMEDATA_H
#define _GAMEDATA_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


class Entity
{
public:
	std::string name;
	int health;
	int damage;
	bool isEnemy;
};

struct GameTile
{
	int x, y;
	bool isEndGameTile = false;
	std::string RoomDesc;
	std::vector<Entity*> EntityList;
	GameTile *NorthTile = NULL;
	GameTile *SouthTile = NULL;
	GameTile *EastTile = NULL;
	GameTile *WestTile = NULL;
};


class Player : public Entity
{
public:
	GameTile * currentTile = NULL;

	Player(std::string n, int h, int d, GameTile *gT)
	{
		name = n;
		health = h;
		damage = d;
		currentTile = gT;
	}
};

class Enemy : public Entity
{
public:
	//bool isDead;
	Enemy(std::string n, int h, int d, bool b)
	{
		name = n;
		health = h;
		damage = d;
		//isDead = b;
		isEnemy = b;
	}
};

class Shrine : public Entity
{
public:
	bool used;
	Shrine(std::string n, int h, int d, bool b)
	{
		name = n;
		health = h;
		damage = d;
		used = b;
	}
};


std::vector<GameTile> GameMap3x1;

GameTile *EastTile = NULL, *WestTile = NULL, *NorthTile = NULL, *SouthTile = NULL;

enum { NODOOR, EAST, WEST, NORTH, SOUTH };

#endif