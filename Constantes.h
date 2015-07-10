#define SizeX 800
#define SizeY 600
#define NbTileX 16
#define NbTileY 12
#define ScaleX SizeX / NbTileX / 16
#define ScaleY SizeY / NbTileY / 16

enum ScreenOrder{STARTSCREEN, MAPSCREEN, LOADSCREEN, NEWSCREEN, OPTIONSCREEN, GAMESCREEN};	//Name of the screen
enum AreaState{WILD, CITY, ALLIED, HOSTILE};	//State of the Area on the map
enum GoundValue{GROUND, WALL, SHALLOW, DEEP, MURKY};	//Value of a tile