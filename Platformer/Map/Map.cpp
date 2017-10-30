#include <string.h>
#include "Map.h"

using namespace std;

Map::Map()
{
	if (spriteSheetTexture.loadFromFile("Assets\\Sprites\\spriteGame.png"))
	{
		spriteSheet.setTexture(spriteSheetTexture);
	}
}

void Map::Create(int mapNumber)
{
	string path = "Assets\\Maps\\Map" + to_string(mapNumber) + ".txt";

	ifstream map(path);
	if (!map.is_open())
		cout << "you got NUKED" << endl;
	else
		cout << "you are alive" << endl;
}