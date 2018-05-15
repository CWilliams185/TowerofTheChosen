#include "TotC.h"
character::character()
{
	name = " ";
	level = 0; exp = 0; floor = 0; 
	Strength = 0; maxHP = 0; atk = 0; def = 0; 
	Agility = 0; crt = 0; acc = 0; eva = 0; 
	Magic = 0; maxMP = 0; mag = 0; res = 0;
	hp = 0; mp = 0;
	alpha = 'q';
	xname = " "; xID = 0; xHP = 0; xMax = 0; xatk = 0; xdef = 0; xcrt = 0; xacc = 0; xeva = 0; xmag = 0; xres = 0;
}
void character::CreateCharacter()
{
	system("cls");
	cout << "Please enter your character's Name: ";
		cin >> name;
		level = 1; exp = 0; floor = 1; Strength = 10; Agility = 10; Magic = 10;
	cout << "Which Stat is most important for you? \n\t(S for Strength, A for Agility, and M for Magic): ";
		cin >> alpha;
		alpha = toupper(alpha);
		while (alpha != 'S' && alpha != 'A' && alpha != 'M')
		{
			cout << "\nYour selection was invalid, please enter another choice!" << endl;
			cout << "Which stat is most important?" << endl << "(S for Strength, A for Agility, and M for Magic):";
			cin >> alpha;
			alpha = toupper(alpha);
		}
		if (alpha == 'S') 
		{
			Strength += 2;
			cout << "Which is least important, A for Agility or M for Magic? ";
			cin >> alpha;
			alpha = toupper(alpha);
			while (alpha != 'A' && alpha != 'M')
			{
				cout << "Your selection was invalid, please enter another choice!" << endl;
				cout << "Which is least important, A for Agility or M for Magic? ";
				cin >> alpha;
				alpha = toupper(alpha);
			}
			if (alpha == 'A') Agility -=2;
			if (alpha == 'M') Magic -=2;
			alpha = 'Q';

		}
		if (alpha == 'A')
		{
			Agility += 2;
			cout << "Which is least important, S for Strength or M for Magic? ";
			cin >> alpha;
			alpha = toupper(alpha);
			while (alpha != 'S' && alpha != 'M')
			{
				cout << "Your selection was invalid, please enter another choice!" << endl;
				cout << "Which is least important, S for Strength or M for Magic? ";
				cin >> alpha;
				alpha = toupper(alpha);
			}
			if (alpha == 'S') Strength -=2;
			if (alpha == 'M') Magic -=2;
			alpha = 'Q';
		}
		if (alpha == 'M')
		{
			Magic += 2;
			cout << "Which is least important, S for Strength or A for Agility? ";
			cin >> alpha;
			alpha = toupper(alpha);
			while (alpha != 'S' && alpha != 'A')
			{
				cout << "Your selection was invalid, please enter another choice!" << endl;
				cout << "Which is least important, S for Strength or A for Agility? ";
				cin >> alpha;
				alpha = toupper(alpha);
			}
			if (alpha == 'S') Strength -=2;
			if (alpha == 'A') Agility -=2;
			alpha = 'Q';
		}
	SaveCharacter();
}
void character::SaveCharacter()
{
	cFile.open ("Save1.txt.", ios::out);
	if(cFile.is_open())
	{
		cFile << name  << endl;
		cFile << level << endl;
		cFile << exp << endl;
		cFile << floor << endl;
		cFile << Strength << endl;
		cFile << Agility << endl;
		cFile << Magic << endl;
		cFile.close();
	}
}
void character::LoadCharacter()
{
	string buffer;
	cFile.open ("Save1.txt.", ios::in);
		getline(cFile, buffer);
		name = buffer;
		getline (cFile, buffer);
		level = atoi(buffer.c_str());
		getline (cFile, buffer);
		exp = atoi(buffer.c_str());
		getline (cFile, buffer);
		floor = atoi(buffer.c_str());
		getline (cFile, buffer);
		Strength = atoi(buffer.c_str());
		getline (cFile, buffer);
		Agility = atoi(buffer.c_str());
		getline (cFile, buffer);
		Magic = atoi(buffer.c_str());
	cFile.close();
}
void character::ExplainStatistics()
{
	system("cls");
	cout << "Your character will gain exp with each enemy that is slain. 100 experience\nwill gain a level and automatically increase your base stat points."
		 << "\n\nBase Stats include: \n   Strength - Increases maximum health, physical damage, and physical defense. \n   Agility  - Critical hit chance, accuracy, and evasion."
		 << "\n   Magic    - Increases maximum mana, magical damage, and magical resistance.\n\n"
		 << "Physical attacks can miss based on accuracy and evasion, but they can \nalso critically strike for triple damage."
		 << "\n\nMagical attacks do not take accuracy or evasion into account, thus \nspells cannot miss or fail. "
		 << "They are however consistent in damage, and limited \nin use by the user's mana supply.\n" << endl;
	system("pause");
	system("cls");
}
void character::Play()
{
	bool Cont = false;
	if (floor != NULL) Cont = true;
	while(Cont == true)
	{
		system("cls");
		CalcStats();
		CharacterCard();
		GenerateEnemy();
		Battle();
		if (hp == 0) Cont = false;
		else
		{
			LevelUp();
			floor += 1;
			SaveCharacter();
		}
	}
	system("pause");
}
void character::LevelUp()
{
	while ((exp > 99) && (level < 10))
		{
			exp -= 100; level += 1; //Stats max at [30, 24, 20]
			system("cls");
			cout << "Congratulations, You've leveled up!" << endl;
			cout << "Strength: " << Strength << " > " << (Strength*1.11) << endl;
			cout << "Agility : " << Agility << " > " << (Agility *1.11) << endl;
			cout << "Magic   : " << Magic << " > " << (Magic   *1.11) << endl;
			Strength = ((Strength * 1.11) + 0.5);
			Agility = ((Agility  * 1.11) + 0.5);
			Magic = ((Magic    * 1.11) + 0.5);
			cout << endl;
			CalcStats();
			CharacterCard();
		}
}
void character::CalcStats()
{
	maxHP = ((Strength*Strength)-Strength);
	hp = maxHP;
	atk = (Strength * 2);
	def = (Strength * 1.5);
	crt = (Agility * 0.5);
	if (crt > 99) crt = 100;
	acc = ((Agility)+75);
	eva = (Agility);
	maxMP = ((Magic*Magic)/2);
	mp = maxMP;
	mag = (Magic * 2.5);
	res = (Magic * 1.5);
}
void character::CharacterCard()
{
	cout << "===== " << name << " ====="
		 << "\nLv. " << level << "." << exp << "  \tFloor " << floor
		 << "\nHP: " << hp << "\t/" << maxHP << "\tStrength " << Strength << "  \tAtk " << atk << "  \tDef " << def
		 << "\nMP: " << mp << "\t/" << maxMP << "\tMagic    " << Magic << "  \tMag " << mag << "  \tRes " << res
		 << "\n\t\tAgility  " << Agility << "\tAcc " << acc << "  \tEva " << eva << "  \tCrt " << crt << "\n===================" << endl;
	system("pause");
}
void character::GenerateEnemy()
{
	xname = " "; xID = 0; xHP = 0; xMax = 0; xatk = 0; xdef = 0; xcrt = 0; xacc = 0; xeva = 0; xmag = 0; xres = 0, BaseExp = 0;
	xID = rand() % floor + (floor+1);
	xID = (xID / 2);
	//xID is between [floor+1] & [floor+floor]
	//Floor 21 has boss chance [21], Floor 41 has max chance of boss
	//[X][X][ ][ ][ ]	[ ][ ][ ][ ][ ]		[ ]
	if (xID > 20) xID = 21;
	//xID = 1; //TESTING
	cout << "\n\n========(" << xID << ")========\nYou've encountered ";
	switch(xID)
	{
	case 1:
	case 2:
		{
			xname = "Small Bat";	xID = 1;	cout << "a Small Bat!" << endl;					//3 Name, ID, Display
			xMax = ((level*8)+32);	xHP = xMax;	xatk = ((level*4)+4);	xdef = 0;					//4 Max, HP, Atk, Def
			xcrt = 0;	xacc = 75;	xeva = -10;	xmag = (level*4);	xres = 0;	BaseExp = 60;	//6 Crit, Acc, Eva, Mag, Res, Exp
			break;
		}
	case 3:
	case 4:
		{
			xname = "Goblin Skirmisher";	xID = 1;	cout << "a Goblin Skirmisher!" << endl;					//3 Name, ID, Display
			xMax = ((level * 6) + 54);	xHP = xMax;	xatk = ((level * 5)+4);	xdef = 5;					//4 Max, HP, Atk, Def
			xcrt = 1;	xacc = 85;	xeva = 0;	xmag = (level * 1);	xres = 0;	BaseExp = 90;	//6 Crit, Acc, Eva, Mag, Res, Exp
			break;
		}
	//case 5:
	//case 6:
	//case 7:
	//case 8:
	//case 9:
	//case 10:
	//case 11:
	//case 12:
	//case 13:
	//case 14:
	//case 15:
	//case 16:
	//case 17:
	//case 18:
	//case 19:
	//case 20:
	case 21:
		{
			xname = "Dark Lord";	xID = 1;	cout << "the Dark Lord!" << endl;					//3 Name, ID, Display
			xMax = ((level * 50) + 1000);	xHP = xMax;	xatk = (level * 12);	xdef = 50;					//4 Max, HP, Atk, Def
			xcrt = 10;	xacc = 105;	xeva = 15;	xmag = (level * 16);	xres = 0;	BaseExp = 1600;	//6 Crit, Acc, Eva, Mag, Res, Exp
			break;
		}
	default:
		{
		cout << "A fatal error has occured D: " << endl;
		break;
		}
	}
	cout << "HP: " << xHP << "\t/ " << xMax
		 << "\nAtk:" << xatk << "\tDef:" << xdef << "\tMag:" << xmag << "\tRes:" << xres
		 << "\nAcc:" << xacc << "\tEva:" << xeva << "\tCrt:" << xcrt
		 << "\n===================" << endl;
	system("pause");
}
			  //GenerateEnemy is incomplete!
void character::BattleCard()
{
	cout << "===== " << name << " ====="
		 << "\nHP: " << hp << "\t/" << maxHP << "\t\tAtk " << atk << "  \tDef " << def
		 << "\nMP: " << mp << "\t/" << maxMP << "\t\tMag " << mag << "  \tRes " << res
		 << "\n\t\t\tAcc " << acc << "  \tEva " << eva << "  \tCrt " << crt << endl;
	cout << "===== " << xname << " =====" 
		 << "\nHP: " << xHP << "\t/" << xMax
		 << "\n====================" <<endl;
}
void character::Battle()
{
	bool TurnTaken = false;
	system("cls");
	CalcStats();
	BattleCard();
	char choice[] = "0";
	while((hp>0) && (xHP>0))
	{
		do
		{
			cout << "1: Attack\n2: Defend\n3: Magic Missile\n" << endl;
			cin >> choice;
			system("cls");
			switch (choice[0])
			{
			case '1':
				BattleAttack();
				TurnTaken = 1;
				break;
			case '2':
				BattleDefend();
				TurnTaken = 1;
				break;
			case '3':
				BattleMagic();
				TurnTaken = 1;
				break;
			default:
				cout << "Unknown command" << endl;
			}
		} while (TurnTaken == 0);
		if ((xHP > 0) && (TurnTaken == 1))
		{
			system("pause");
			system("cls");
			BattleEnemy();
			TurnTaken = 0;
		}
	}
	if (hp<1)
	{
		cout << "You have fallen in combat! Your adventure ends here..." << endl;
		system("pause");
		system("cls");
		cout << "=== GAME OVER ===" << endl;
	}
	else if (xHP<1)
	{
		if (level < 10)
		{
			cout << "Victory! You have defeated your enemy and gained " << (BaseExp / level) << " experience!" << endl;
			exp += (BaseExp / level);
			system("pause");
		}
		else
		{
			cout << "Victory! You have defeated your enemy, but can become no stronger from such rudimentary foes." << endl;
			system("pause");
		}
	}
	else
	{
	cout << "...Something broke D:" << endl;
	system("pause");
	}
}
void character::BattleAttack()
{
	int hit;
	//xID = rand() % xID +1;
	hit = rand() % 100 + 1;
	if (((hit + acc) - xeva) > 99)
	{
		int critical = rand() % 100 + (crt + 1);
		if ((critical+crt) > 99)
		{
			xHP -= (((((atk - xdef) + 100) * atk) * 3) / 100);
			if (xHP < 1) xHP = 0;
			BattleCard();
			cout << "==== CRITICAL HIT ====\nYou hit with a (" << hit << " + " << acc << " vs. " << xeva + 100 << "),\n\tand landed a critical hit with a (" << critical << " + " << crt << ")\nThe attack deals a massive " << (((((atk - xdef) + 100) * atk) * 3) / 100) << " damage!\n\n" << endl;
		}
		else
		{
			xHP -= ((((atk - xdef)+100) * atk) / 100);
			if (xHP < 1) xHP = 0;
			BattleCard();
			cout << "You rolled a " << hit << " to attack.\n\nIt's a hit! (" << hit << " + " << acc << " vs. " << xeva+100 << ")\n\t(No critical hit at " << critical << " + " << crt << ")\nThe attack deals " << ((((atk - xdef) + 100) * atk) / 100) << " damage!\n\n" << endl;
		}
	}
	else
	{
		BattleCard();
		cout << "You rolled a " << hit << " to attack.\n\n...but the attack missed! (" << hit << " + " << acc << " vs. " << xeva+100 << ")\n\n" << endl;
	}
}
void character::BattleDefend()
{

}
//What does defend even do??
void character::BattleMagic()
{
	if(mp>=(10*level))
	{
		xHP -= (mag - xres);
		if (xHP < 1) xHP = 0;
		mp -= (10 * level);
		BattleCard();
		cout << "You cast a firball at the enemy for " << (mag-xres) << " damage!" << endl;
	}
	else 
	{
		BattleCard();
		cout << "Your spell fizzles from lack of mana and are left defensless!" << endl;
	}
}
//Implement Spell Book, a closable menu, and the ability to deny a lack of mana
void character::BattleEnemy()
{
	int xhit = rand() % xID + 1;
	switch (xhit)
	{
		case 1:
		{
			xhit = rand() % 100 + 1;
			if (((xhit + xacc) - eva) > 99)
			{
				int critical = rand() % 100 + (crt + 1);
				if ((critical + crt) > 99)
				{
					hp -= (((((xatk - def) + 100) * xatk) * 3) / 100);
					if (hp < 1) hp = 0;
					BattleCard();
					cout << "==== CRITICAL HIT ====\nThe " << xname << " has hit you with a (" << xhit << " + " << xacc << " vs. " << eva + 100 << "),\n\tand landed a critical hit with a (" << critical << " + " << xcrt << ")\nThe attack deals a massive " << (((((xatk - def) + 100) * xatk) * 3) / 100) << " damage!\n\n" << endl;
				}
				else
				{
					hp -= ((((xatk - def) + 100) * xatk) / 100);
					if (hp < 1) hp = 0;
					BattleCard();
					cout << "The " << xname << " strikes! They roll a " << xhit << " to attack.\n\nYou are hit! (" << xhit << " + " << xacc << " vs. " << eva + 100 << ")\n\t(No critical hit at " << critical << " + " << crt << ")\nThe attack deals " << ((((xatk - def) + 100) * xatk) / 100) << " damage!\n\n" << endl;
				}
			}
			else
			{
				BattleCard();
				cout << "The " << xname << " strikes! They roll a " << xhit << " to attack.\n\n...but you evade successfully! (" << xhit << " + " << xacc << " vs. " << eva + 100 << ")\n\n" << endl;
			}
			break;
		}
		//case 2:
		//case 3:
		//case 4:
		default:
			cout << "An error has occured in the enemy's AI!" << endl;
			break;
	}
}
//End Marker [(This line)+(36+51)] = 513
//Switch statement at 279 is invincible; Double check all others to match their strength!!!