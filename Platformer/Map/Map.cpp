#include <string.h>
#include "Map.h"

using namespace std;
using namespace sf;

Map::Map()
{
	//blue
	blueSquare.setSize(Vector2f(32, 32));
	blueSquare.setFillColor(Color::Blue);
	//green
	greenSquare.setSize(Vector2f(32, 32));
	greenSquare.setFillColor(Color::Green);
}

Map::~Map()
{
	for (int i = 0; i < 1125; ++i)
		delete pointTable[i];
}

bool Map::Create(int mapNumber)
{
	string path = "Assets\\Maps\\Map" + to_string(mapNumber) + ".txt";
	int ctr = 0;
	int ctrPosX = 0;
	int ctrPosY = 0;
	ifstream map(path);
	if (map.is_open())
	{
		string line;
		while (getline(map, line))
		{
			int codeType;
			stringstream elem(line);

			while (elem >> codeType)
			{
				pointTable[ctr] = new Point(ctrPosX, ctrPosY, getType(codeType));
				ctr++;
				if (ctr % 45 == 0)
				{
					ctrPosY += 32;
					ctrPosX = 0;
				}
				else
					ctrPosX += 32;
			}
		}

		return true;
	}
	else
		return false;
}

blocType Map::getType(int codeType)
{
	switch (codeType)
	{
	case 0: return blocType::sky;
		break;
	case 1: return blocType::grass;
		break;
	}
}

void Map::Draw(RenderWindow &mainWin)
{
	for (int i = 0; i < 1125; ++i)
	{
		switch (pointTable[i]->GetType())
		{
		case blocType::sky:	blueSquare.setPosition(pointTable[i]->GetX(), pointTable[i]->GetY());
			mainWin.draw(blueSquare);
			break;
		case blocType::grass:	greenSquare.setPosition(pointTable[i]->GetX(), pointTable[i]->GetY());
			mainWin.draw(greenSquare);
			break;
		}
	}
}