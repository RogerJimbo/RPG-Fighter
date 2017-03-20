#ifndef __CREATURES_H__
#define __CREATURES_H__

void hero_name();
void goblin_srawing();
void goblin_drawing();
void goblin_boss_draw();
int game_over();
int you_win();
void type_color();
void combat_struct();

// find here the main data structure for the game
// feel free to expand it to suit your improvements

struct combat_data
{
	int hp;
	int attack_min;
	int attack_max;
	int armor;
	int revive;
};

struct hero_data
{
	char* name;
	struct combat_data combat;
	int coins;
	int xp;
	int lvl;
};

struct monster_data
{
	struct combat_data combat;
	int coins;
	int xp;
};

#endif // __CREATURES_H__