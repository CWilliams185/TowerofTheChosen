#include "TotC.h"
int main()
{
	//Main Menu
	int choice;
	character c;
	do{
		cout << "=====  TOWER OF THE CHOSEN   =====\n\t(1) New Game\n\t(2) Load Game\n\t(3) Statistic Explanation\n\t(0) Exit\n===================================\n";
		cin >> choice;
		switch(choice)
		{
		case 1:
			c.CreateCharacter();
			c.Play();
			break;
		case 2:
			c.LoadCharacter();
			c.Play();
			break;
		case 3:
			c.ExplainStatistics();
			break;
		default:
			choice = 0;
			cout << "\nThank you for playing Tower of the Chosen!" << endl;
			system("pause");
			break;
		}
		system("cls");
	}while(choice != 0);
	return 0;
}
//=========================
//_X_Character Creation
//_X_Character Save Spot
//_X_Explain Statistics
//___Enemy Generation
//___Battle System
//_X_Floor Advancement
//=========================
//_X_Multiple Save Spots
//___Magic System
//___Critical System
//___Backpack System?
//___Fury/Spirit system
//___Equipment?
//=========================
//Floor Environment (Walkable Maze?)
//Bosses, elements, hard classes?
//Party of Characters
//=========================