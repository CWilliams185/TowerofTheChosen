#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class character
{
private:
	string name, xname;
	int level, exp, floor, 
		Strength, maxHP, atk, def, 
		Agility, crt, acc, eva, 
		Magic, maxMP, mag, res,
		hp, mp;
	char alpha;
	fstream cFile;
	int xID, xHP, xMax, xatk, xdef, xcrt, xacc, xeva, xmag, xres, BaseExp;
public:
	character();
	void CreateCharacter();		//Name character, create class, assign and save stats.
	void SaveCharacter();		//Save to single txt with private variables. Eventually advance to multiple save spots.
	void LoadCharacter();		//Load from txt onto "character c". Eventually implement choice of 3 files and display contents of each
	void ExplainStatistics();	//Simple wall of text, then goes back to main menu
	void Play();				//Huge while loop that encompasses most everything
	void LevelUp();
	void CalcStats();
	void CharacterCard();
	void GenerateEnemy();
	void BattleCard();

	void Battle();
	void BattleAttack();
	void BattleMagic();
	void BattleDefend();
	void BattleEnemy();
};