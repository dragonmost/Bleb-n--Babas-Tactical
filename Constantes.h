#define SizeX 800
#define SizeY 600
#define NbTileX 16
#define NbTileY 12
#define ScaleX SizeX / NbTileX / 16
#define ScaleY SizeY / NbTileY / 16

//values of the tile. "not" means you can't walk on it. (like walls)
enum GoundValue{Ground, Shallow, Deep, Murky, not};