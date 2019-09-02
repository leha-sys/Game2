#include "GameHeaders.h"

/*
TODO:
show health in the main room (console out)
take health in the main room from shrine (new function)
choice to go or to take a health
move RoomAction() to the separate file


*/

int RoomAction(Player *player)
{
	for (int i = 0; i < player->currentTile->EntityList.size(); i++)
	{
		std::cout << "There is a " << player->currentTile->EntityList[i]->name << " in the room." << std::endl;
		//if (player.currentTile->EntityList[i]->name == "Slime")
		if (player->currentTile->EntityList[i]->isEnemy == true)
		{
			while (player->health > 0 && player->currentTile->EntityList[i]->health > 0)
			{

				std::cout << player->name << " is attacked by a " << player->currentTile->EntityList[i]->name << "." << std::endl;
				player->health -= player->currentTile->EntityList[i]->damage;
				std::cout << player->name << "'s health is now at: " << player->health << std::endl;
				if (player->health < 0)
				{
					std::cout << "You Died..." << std::endl;
					system("pause");
					return 1;
				}
				std::cout << player->name << " attacks the " << player->currentTile->EntityList[i]->name << "." << std::endl;
				player->currentTile->EntityList[i]->health -= player->damage;
				std::cout << "The " << player->currentTile->EntityList[i]->name << "'s health is now at: " << player->currentTile->EntityList[i]->health << "\n" << std::endl;
				system("pause");
				system("cls");
			}
			if (player->health < 0)
			{
				std::cout << "You Died..." << std::endl;
				system("pause");
				return 1;
			}
			else
			{
				std::cout << "The " << player->currentTile->EntityList[i]->name << " is dead." << "\n" << std::endl;
			}
		}
	}
	return 0;
}

int main()
{
	CreateMap3x1();
	Player player{ "Hero", 100, 5, &GameMap3x1[0] };

	while (player.health > 0 && player.currentTile->isEndGameTile != true)
	{
		system("cls");
		std::cout << player.currentTile->RoomDesc << std::endl;

		if (RoomAction(&player) == 1) return 0;

		LookForDoors(&player);
		ShowDoors();
		int door = NODOOR;
		while (!door)
		{
			door = AskWhichDirection();
			ChangeTiles(&player, door);
		}
	}
	if (player.health < 0)
	{
		system("cls");
		std::cout << "You Died..." << std::endl;
		system("pause");
		return 0;
	}
	system("cls");
	std::cout << " You Win!" << std::endl;
	system("pause");
	return 0;
}


