#include"creatures.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <cstdlib> 
#include <cwchar>
#include <windows.h>
#include <iostream>

using namespace std;

void combat_struct()
{
	//HERO DATA
	struct hero_data hero;
	hero.combat.attack_max = 11;
	hero.combat.hp = 100;
	hero.combat.armor = 1;
	hero.coins = 0;
	hero.lvl = 0;
	hero.xp = 0;

	//srand(time(NULL));(to remember)
	struct monster_data goblin[100];
	
	//GOBLIN DATA
	for (int i = 0; i < 100; i++)		
	{														
		goblin[i].combat.attack_max = 20;
		goblin[i].combat.hp = 100;				
		goblin[i].combat.armor = 10;			
	} 
	//HERO INFO AT START
		
	printf("\t\t\t|------------------------------------------|\n");
	printf("\t\t\t|Your health is %d HP.                    |\n", hero.combat.hp);
	printf("\t\t\t|Your suit has a defense of %d HP.          |\n", hero.combat.armor);
	printf("\t\t\t|You have %d coins.                         |\n", hero.coins);
	printf("\t\t\t|You have %d XP.                            |\n", hero.xp);
	printf("\t\t\t|You are level %d.                          |\n", hero.lvl);
	printf("\t\t\t|------------------------------------------|\n\n");

	//MARKET INFO
	printf("|---------------------------------------------------------------------------------------------|\n");
	printf("|You can exchange your coins for better armors, better weapons or potions at the market.      |\n");
	printf("|---------------------------------------------------------------------------------------------|\n\n");

		printf( "I won't let you wake up until you kill those Goblins!!\n");
		getchar();

	//GOBLIN GENERATOR, ROUNDS AND MARKET
	for (int i = 1; i < 100; i++)
	{
		printf("|-------------|\n");
		if (i < 10)
		{
			printf("|Goblin  %d    |\n", i);
		}
		else
		{
			printf("|Goblin  %d   |\n", i);
		}
		printf("|-------------|\n\n");
		getchar();

		//DRAWINGS & GOBLIN PROPERTIES

		//ROUNDS 1,2 AND 3
		if (i <= 3)		
		{
			srand(time(NULL));
			goblin[i].combat.attack_max = 4 + rand() % 7 + 1;		//max goblin damage = 11
			goblin[i].combat.hp = 10 + rand() % 20 + 1;				//max goblin health = 30
			goblin[i].combat.armor = 0 + rand() % 3 + 1;			//max goblin protection = 3
			goblin_srawing();
		}
		//ROUNDS 4,5 AND 6
		if (i > 3 && i<7)
		{
			if (i == 4)
			{
				printf("A new Goblin!\n");
				printf("This is getting harder...\n\n");
			}
			goblin[i].combat.attack_max = 9 + rand() % 7 + 1;		//max goblin damage = 16
			goblin[i].combat.hp = 20 + rand() % 20 + 1;				//max goblin health = 40
			goblin[i].combat.armor = 1 + rand() % 3 + 1;			//max goblin protection = 4
			goblin_drawing();
		}
		//ROUNDS 7,8 AND 9
		if (i >= 7 && i < 10)
		{
			if (i == 7)
			{
				printf("A new Goblin!\n");
				printf("This is so hard now...\n\n");
			}
			goblin[i].combat.attack_max = 12 + rand() % 14 + 1;		//max goblin damage = 26
			goblin[i].combat.hp = 25 + rand() % 15 + 1;				//max goblin health = 40
			goblin[i].combat.armor = 2 + rand() % 3 + 1;			//max goblin protection = 3
			goblin_drawing();
		}
		//ROUNDS 10 AND 11
		if (i > 9 && i < 12)
		{
			goblin[i].combat.attack_max = 14 + rand() % 17 + 1;		//max goblin damage = 31
			goblin[i].combat.hp = 35 + rand() % 10 + 1;				//max goblin health = 45
			goblin[i].combat.armor = 3 + rand() % 3 + 1;			//max goblin protection = 3
			goblin_drawing();
		}
		//BOSS ROUND 12
		if (i == 12)	
		{
			printf("A Boss!\n");
			printf("This must be the end...\n\n");
			goblin[i].combat.attack_max = 30 + rand() % 10 + 1 + rand() % 10 + 1;		//max 40
			goblin[i].combat.hp = 65 + rand() % 15 + 1;									//max 80 
			goblin[i].combat.armor = 4 + rand() % 3 + 1;								//max 5
			goblin_boss_draw();
		}
		//ROUND 13 TO 19
		if (i > 12 && i < 20)
		{
			goblin[i].combat.attack_max = 20 + rand() % 25 + 1;		//max goblin damage = 45
			goblin[i].combat.hp = 40 + rand() % 10 + 1;				//max goblin health = 50
			goblin[i].combat.armor = 5 + rand() % 3 + 1;			//max goblin protection = 8
			goblin_drawing();
		}
		//BOSS ROUND 20
		if (i == 20)
		{
			printf("The final Boss!\n");
			printf("This is the end...\n\n");
			goblin[i].combat.attack_max = 30 + rand() % 10 + 1 + rand() % 10 + 1;		//max 50
			goblin[i].combat.hp = 65 + rand() % 15 + 1;									//max 80 
			goblin[i].combat.armor = 4 + rand() % 3 + 1;								//max 5
			goblin_boss_draw();
		}

		if (i > 20)
		{
				goblin[i].combat.attack_max = 20;
				goblin[i].combat.hp = 100;
				goblin[i].combat.armor = 10;
				goblin_drawing();
				
		}

		//GOBLIN INFO
		printf("\n|----------------------------------------------------|\n");
		printf("|The health of this goblin is %d HP.                 |\n", goblin[i].combat.hp);
		printf("|The armor of this Goblin has a defense of %d HP.     |\n", goblin[i].combat.armor);
		printf("|----------------------------------------------------|\n\n");
		getchar();

		//WHILE THE GOBLIN IS ALIVE AND MARKET
		while (goblin[i].combat.hp > 0)   
		{
			printf("\nThe goblin attacks you! %d HP of Damage.\n", goblin[i].combat.attack_max); //goblin attacks

			hero.combat.hp = hero.combat.hp + hero.combat.armor - goblin[i].combat.attack_max;
			getchar();

			//GAME OVER

			if (hero.combat.hp <= 0)
			{
				hero.combat.hp = 0;

				printf("\n\n|----------------|\n");
				printf("|You died: %d HP  |\n", hero.combat.hp);
				printf("|----------------|\n\n");

				//IF USER HAS REVIVE POTION
				if (hero.combat.revive == 1)
				{
					printf("But you have a Revive Potion!\n\n");
					printf("Do you want to drink the potion and live? [1]\n");
					printf("Or don't drink the revive potion and die? [2]\n\n");

					int answer;
					scanf("%d", &answer);
					getchar();
						do 
						{
							switch (answer)
							{
							case 1:
								printf("You drink the Revive Potion!");
								hero.combat.hp = 100;
								printf("Your health is full again , %d HP", hero.combat.hp);
								break;
							case 2:
								game_over();
								break;
							default:
								printf("[1] or [2]");
							}
						} 
						while (answer > 0 && answer < 3);
				}

				else
				{
					game_over();
				}
			
			}


			//ARMORS
			if (hero.combat.armor == 1)
			{
				printf("Your suit protects 1 HP\n");
			}
			if (hero.combat.armor == 5)
			{
				printf("The Wooden Armor protects 5 HP.\n");
			}
			if (hero.combat.armor == 10)
			{
				printf("The Steel Armor protects 10 HP.\n");
			}
			if (hero.combat.armor == 20)
			{
				printf("The Diamond Armor protects 20 HP.\n");
			}

			printf("\nYour health is now %d HP.\n\n", hero.combat.hp);

			//YOU ATTACK
			goblin[i].combat.hp = goblin[i].combat.hp + goblin[i].combat.armor - hero.combat.attack_max;	
			getchar();

			if (goblin[i].combat.hp < 0)
			{
				goblin[i].combat.hp = 0;
			}

			//WEAPONS ATTACK
			
			if (hero.combat.attack_max == 11)	//hand
			{ 
				printf("You hit the Goblin! %d HP of Damage.\n", hero.combat.attack_max);
				getchar();
			}
			if (hero.combat.attack_max == 17)	//stick
			{
				printf("You hit the Goblin with the stick! %d HP of Damage.\n", hero.combat.attack_max);
				getchar();
			}
			if (hero.combat.attack_max == 22)	//sword
			{
				printf("You hit the Goblin with the sword! %d HP of Damage.\n", hero.combat.attack_max);
				getchar();
			}
			if (hero.combat.attack_max == 31)	//gun
			{
				printf("You shoot the Goblin with the gun! %d HP of Damage.\n", hero.combat.attack_max);
				printf("Green blood everywhere\n");
				getchar();
			}

			printf("The armor of the Goblin protects %d HP.\n", goblin[i].combat.armor = 1 + rand() % 1 + 1);	
			printf("\nThe health of the Goblin is now: %d HP\n\n", goblin[i].combat.hp);
			getchar();

			//WHEN THE GOBLIN IS DEAD
			if (goblin[i].combat.hp <= 0)
			{
				if (i != 12 && i != 20) //THE NON BOSSES GOBLINS
				{
					printf("\nGood, you have killed the Goblin.\n");
					getchar();

					//ORDINARY GOBLINS COINS AND XP

					//COINS
					goblin[i].coins = 1 + rand() % 5 + 1;
					printf("The dead goblin dropped %d coins!\n\n", goblin[i].coins);
					hero.coins = hero.coins + goblin[i].coins;
					//EXP
					goblin[i].xp = 10;
					printf("You earned %d XP.\n\n", goblin[i].xp);
					hero.xp = hero.xp + goblin[i].xp;

					//LEVEL UP WHEN KILLING GOBLIN
					if (hero.xp == 30)
					{
						hero.lvl = hero.lvl + 1;
						printf("|---------|\n");
						printf("|Level up!|\n");
						printf("|---------|\n\n");

						hero.combat.hp = hero.combat.hp + 30;
						printf("|--------|\n");
						printf("|+30 HP  |\n");
						printf("|--------|\n\n");

						hero.xp = 0;
					}
				}

				else //THE BOSSES GOBLIN XP AND COINS
				{
					printf("\nGreat, you have killed the Boss!\n");
					getchar();

					//COINS
					goblin[i].coins = 10 + rand() % 9 + 1;
					printf("The dead Boss dropped %d coins!\n\n", goblin[i].coins);
					hero.coins = hero.coins + goblin[i].coins;

					//EXP
					goblin[i].xp = 30;
					printf("You earned %d XP.\n\n", goblin[i].xp);
					hero.xp = hero.xp + goblin[i].xp;

					//LEVEL UP WHEN KILLING BOSS
					if (hero.xp > 30)
					{
						hero.lvl = hero.lvl + 1;
						printf("|---------|\n");
						printf("|Level up!|\n");
						printf("|---------|\n\n");

						hero.combat.hp = hero.combat.hp + 30;
						printf("|--------|\n");
						printf("|+30 HP  |\n");
						printf("|--------|\n\n");

						hero.xp = hero.xp - 30;
					}
				}

				printf("\t\t\t|-----------------------------------------|\n");
				printf("\t\t\t|Your health is %d HP.                    |\n", hero.combat.hp);
				printf("\t\t\t|Your armor has a defense of %d HP.        |\n", hero.combat.armor);
				if (hero.coins < 10)
				{
					printf("\t\t\t|You have %d coins.                        |\n", hero.coins);
				}

				else
				{
					printf("\t\t\t|You have %d coins.                       |\n", hero.coins);
				}

				if (hero.xp < 10)
				{
					printf("\t\t\t|You have %d XP.                           |\n", hero.xp);
				}

				else
				{
					printf("\t\t\t|You have %d XP.                          |\n", hero.xp);
				}
				printf("\t\t\t|You are level %d.                         |\n", hero.lvl);
				printf("\t\t\t|-----------------------------------------|\n\n");

				printf("You will have to kill more Goblins if you want to awake...\n");
				getchar();
				
				//MARKET

					printf("\nDo you want to acces the market?\n\n");
					printf("|--------------------------------------------------------|\n");
					printf("|Type 5 key for entering the market or 1 to continue.    |\n");
					printf("|--------------------------------------------------------|\n\n");

					int option;

					while (10)
					{
						cin >> option;
						getchar();

							if (option == 1) //exit the market
							{
								break;
							}

							if (option == 5) //enter the mrket
							{
								int mkt = 0;

								printf("\t|------------------------|\n");
								printf("\t|You entered the market  |\n");
								printf("\t|------------------------|\n\n");

								do
									{				
										printf("\nYou have %d Coins.\n\n", hero.coins);

										printf("What do you want to buy?\n\n");
										printf("\t Type 1 for Armors\n");
										printf("\t Type 2 for Weapons\n");
										printf("\t Type 3 for Potions\n");
										printf("\n\t Type 4 if you want to exit the market\n");

										int a = 0;
										scanf_s("%d", &a);

										if (a == 1)		//b variable
										{
											printf("Armors:\n\n");
											printf("\t Type 1 for Wooden Armor: Protects 5 HP.		       |05 Coins|\n");
											printf("\t Type 2 for Steel Armor: Protects 10 HP.		       |12 Coins|\n");
											printf("\t Type 3 for Diamond Armor: Protects 20 HP.		       |20 Coins|\n");

											printf("\nWhich armor do you want to buy?\n\n");

											int b = 0;
											scanf_s("%d", &b);

											if (b == 1) //wooden armor
											{
												if (hero.coins < 5)
												{
													printf("\nYou can't buy this product.\n");
													printf("\nYou have only %d Coins and this product costs 5 Coins\n", hero.coins);
													getchar();
												}

												else
												{
													printf("\nYou bought the Wooden Armor.\n");
													hero.coins = hero.coins - 5;
													hero.combat.armor = 5;

													if (hero.coins == 1)
													{
														printf("\nYou now have %d Coin.\n", hero.coins);
													}
													else
													{
														printf("\nYou now have %d Coins.\n", hero.coins);
													}
												}
											}

											if (b == 2)	//steel armor
											{
												if (hero.coins < 12)
												{
													printf("\nYou can't buy this product.\n");
													printf("\nYou have only %d Coins and this product costs 12 Coins\n", hero.coins);
													getchar();
												}

												else
												{
													printf("\nYou bought the Steel Armor.\n");
													hero.coins = hero.coins - 12;
													hero.combat.armor = 10;
													if (hero.coins == 1)
													{
														printf("\nYou now have %d Coin.\n", hero.coins);
													}
													else
													{
														printf("\nYou now have %d Coins.\n", hero.coins);
													}
												}
											}
											if (b == 3)	//diamond armor
											{
												if (hero.coins < 20)
												{
													printf("\nYou can't buy this product.\n");
													printf("\nYou have only %d Coins and this product costs 20 Coins\n", hero.coins);
													getchar();
												}

												else
												{
													printf("\nYou bought the Diamond Armor.\n");
													hero.coins = hero.coins - 20;
													hero.combat.armor = 20;
													if (hero.coins == 1)
													{
														printf("\nYou now have %d Coin.\n", hero.coins);
													}
													else
													{
														printf("\nYou now have %d Coins.\n", hero.coins);
													}
												}
											}

											int y;					//another shop?

											printf("\nPress 5 to keep on shoping.\n");
											printf("\nPress 1 to exit the market.\n");
											scanf_s("%d", &y);

											if (y == 5)
											{
												mkt = 0;
											}
											if (y == 1)
											{
												mkt = 1;
											}

										}

										if (a == 2)		//c variable
										{
											printf("Weapons:\n\n");
											printf("\t Type 1 for Stick: Damage 6 HP.				           |04 Coins|\n");
											printf("\t Type 2 for Sword: Damage 11 HP.				   |10 Coins|\n");
											printf("\t Type 3 for Gun: Damage 20 HP.					   |20 Coins|\n");

											printf("\nWhich weapon do you want to buy?\n\n");

											int c = 0;
											scanf_s("%d", &c);

											if (c == 1)		//stick
											{
												if (hero.coins < 4)
												{
													printf("\nYou can't buy this product.\n");
													printf("\nYou have only %d Coins and this product costs 4 Coins\n", hero.coins);
													getchar();
												}

												else
												{
													printf("\nYou bought the Stick.\n");
													hero.coins = hero.coins - 4;
													hero.combat.attack_max = hero.combat.attack_max + 6;

													if (hero.coins == 1)
													{
														printf("\nYou now have %d Coin.\n", hero.coins);
													}
													else
													{
														printf("\nYou now have %d Coins.\n", hero.coins);
													}
												}
											}

											if (c == 2)		//sword
											{
												if (hero.coins < 10)
												{
													printf("\nYou can't buy this product.\n");
													printf("\nYou have only %d Coins and this product costs 10 Coins\n", hero.coins);
													getchar();
												}

												else
												{
													printf("\nYou bought the Sword.\n");
													hero.coins = hero.coins - 10;
													hero.combat.attack_max = hero.combat.attack_max + 11;
													if (hero.coins == 1)
													{
														printf("\nYou now have %d Coin.\n", hero.coins);
													}
													else
													{
														printf("\nYou now have %d Coins.\n", hero.coins);
													}
												}
											}

											if (c == 3)		//gun
											{
												if (hero.coins < 20)
												{
													printf("\nYou can't buy this product.\n");
													printf("\nYou have only %d Coins and this product costs 20 Coins\n", hero.coins);
													getchar();
												}

												else
												{
													printf("\nYou bought the Gun.\n");
													hero.coins = hero.coins - 20;
													hero.combat.attack_max = hero.combat.attack_max + 20;
													if (hero.coins == 1)
													{
														printf("\nYou now have %d Coin.\n", hero.coins);
													}
													else
													{
														printf("\nYou now have %d Coins.\n", hero.coins);
													}
												}
											}

											int y;					//another shop?

											printf("\nPress 5 to keep on shoping.\n");
											printf("\nPress 1 to exit the market.\n");
											scanf_s("%d", &y);

											if (y == 5)
											{
												mkt = 0;
											}
											if (y == 1)
											{
												mkt = 1;
											}

										}

										if (a == 3)		//d variable
										{
											printf("Potions:\n\n");
											printf("\t Type 1 for Health Potion: Recovers 50 HP.                 |07 Coins|\n");
											printf("\t Type 2 for Experience Potion: +10 XP.			   |10 Coins|\n");
											printf("\t Type 3 for Revive Potion: Recovers Live.	           |30 Coins|\n");

											printf("\nWhich potion do you want to buy?\n\n");

											int d = 0;
											scanf_s("%d", &d);

											if (d == 1)
											{
												if (hero.coins < 7)		//health potion
												{
													printf("\nYou can't buy this product.\n");
													printf("\nYou have only %d Coins and this product costs 7 Coins\n", hero.coins);
													getchar();
												}

												else
												{
													printf("\nYou bought the Health Potion.\n");
													hero.coins = hero.coins - 7;
													hero.combat.hp = hero.combat.hp + 50;
													printf("You drink the Health Potion.");
													printf("Now you have %d HP.", hero.combat.hp);

													if (hero.coins == 1)
													{
														printf("\nYou now have %d Coin.\n", hero.coins);
													}
													else
													{
														printf("\nYou now have %d Coins.\n", hero.coins);
													}
												}
											}
											if (d == 2)				//exp potion
											{
												if (hero.coins < 10)
												{
													printf("\nYou can't buy this product.\n");
													printf("\nYou have only %d Coins and this product costs 10 Coins\n", hero.coins);
													getchar();
												}

												else
												{
													printf("\nYou bought the Experience Potion.\n");
													hero.coins = hero.coins - 10;
													hero.xp = hero.xp + 10;
													printf("You drink the Experience Potion.");
													printf("Now you have %d XP.", hero.xp);

													if (hero.xp >= 30)
													{
														hero.lvl = hero.lvl + 1;
														printf("|---------|\n");
														printf("|Level up!|\n");
														printf("|---------|\n\n");

														hero.combat.hp = hero.combat.hp + 30;
														printf("|--------|\n");
														printf("|+30 HP  |\n");
														printf("|--------|\n\n");

														hero.xp = 0;
													}

													if (hero.coins == 1)
													{
														printf("\nYou now have %d Coin.\n", hero.coins);
													}
													else
													{
														printf("\nYou now have %d Coins.\n", hero.coins);
													}
												}

											}
											if (d == 3)			//revive potion
											{
												if (hero.coins < 30)
												{
													printf("\nYou can't buy this product.\n");
													printf("\nYou have only %d Coins and this product costs 30 Coins\n", hero.coins);
													getchar();
												}

												else
												{
													printf("\nYou bought the Revive Potion.\n");
													printf("\nThis potion can only be used if you die.\n");
													hero.coins = hero.coins - 30;
													hero.combat.revive = 1;
													if (hero.coins == 1)
													{
														printf("\nYou now have %d Coin.\n", hero.coins);
													}
													else
													{
														printf("\nYou now have %d Coins.\n", hero.coins);
													}
												}

											}

											int y;					//another shop?

											printf("\nPress 5 to keep on shoping.\n");
											printf("\nPress 1 to exit the market.\n");
											scanf_s("%d", &y);

											if (y == 5)
											{
												mkt = 0;
											}
											if (y == 1)
											{
												mkt = 1;
											}
										}

										if (a == 4)
										{
											mkt = 1;
										}
									}

								while (mkt == 0);

								if (mkt == 1)
								{
									break;
								}
							}	
					}
				}//WHEN THE GOBLIN IS DEAD
			}//WHILE THE GOBLIN IS ALIVE AND MARKET
		}//GOBLIN GENERATOR, ROUNDS AND MARKET CLAUDATOR
}

void hero_name()
{
	char name[100];
	printf("This is a dream...\n");
	getchar();
	printf("Well, lets say a nightmare, a bad one...\n");
	getchar();
	printf("Hey you! Are you listening? Do you have a name?\n\n");
	printf("Insert your name:");
	scanf_s("%s", &name, 100);
	printf("\nOh! So you are %s?\n", name);
	printf("What a coincidence... I'm %s too!\n", name);
	printf("In fact, I'm your subconscious!\n\n");
	getchar();
	printf("You know, I can feel your fear right now...\n");
	getchar();
}
	

void goblin_srawing()
{
	printf("\t       _      _        \n");
	printf("\t      (_\\    /_)       \n");
	printf("\t        ))  ((         \n");
	printf("\t     .-'''''''-.        \n");
	printf("\t /^\\/  _.   _.  \\/^\\    \n");
	printf("\t \\(   /__\\ /__\\   )/    \n");
	printf("\t  \\,  \\o_/_\\o_/  ,/     \n");
	printf("\t    \\    (_)    /       \n");
	printf("\t     `-.'==='.-'        \n");
	printf("\t      __) - (__         \n");
	printf("\t     /  `~~~`  \\   \n");
	printf("\t    /  /     \\  \\  \n");
	printf("\t    \\ :       ; /  \n");
	printf("\t     \\|==(*)==|/   \n");
	printf("\t      :       :    \n");
	printf("\t       \\  |  /     \n");
	printf("\t     ___)=|=(___   \n");
	printf("\t    {____/ \\____}  \n");
}
void goblin_drawing()
{
	
	printf("\t       ^      ^        \n");
	printf("\t      /_\\    /_\\       \n");
	printf("\t        ))  ((         \n");
	printf("\t      .-'''''''-.        \n");
	printf("\t /^\\/  _.   _.  \\/^\\    \n");
	printf("\t \\(   /__\\ /__\\   )/    \n");
	printf("\t  \\,  \\x_/_\\x_/  ,/     \n");
	printf("\t    \\    (_)    /       \n");
	printf("\t     `-.'WWW'.-'        \n");
	printf("\t      __) - (__         \n");
	printf("\t     /  |===|  \\   \n");
	printf("\t    /  /     \\  \\  \n");
	printf("\t    \\ :       ; /  \n");
	printf("\t     \\|NN(X)NN|/   \n");
	printf("\t      :       :    \n");
	printf("\t       \\  |  /     \n");
	printf("\t     ___)=|=(___   \n");
	printf("\t    {____/ \\____}  \n");

}
void goblin_boss_draw()
{
	printf("\t     ,-.        ____										  \n");
	printf("\t   ,-. /       ()__ \\____									  \n");
	printf("\t  /  //           _-()__ \\-_								  \n");
	printf("\t  \\  ||  ,-.    _-     , /  -_							  \n");
	printf("\t   \\  \\/  |   _-      ./     -_							 \n");
	printf("\t    \\ ,-. /   /'\\ /''\\        _-							 \n");
	printf("\t   ,--. //    \\x/  \\x/       _-							 \n");
	printf("\t  /  // `.     ,-.         _-							 \n");
	printf("\t  \\  ||`.,-.   `._;       _-								 \n");
	printf("\t   \\  \\/  |`.   -_      _-								 \n");
	printf("\t    \\  /  /`. `. /////\\\\\\\\\								 \n");
	printf("\t     \\   /   `. /  ,--,  /                                 \n");
	printf("\t      \\  `.    |   `,  \ |								 \n");
	printf("\t       `.  `.  /    :  / /        _-.						 \n");
	printf("\t         `.  `.    ,` / |      _- . \\                     \n");
	printf("\t           `.  `.,`  /  /    _- . \\ /						  \n");
	printf("\t             `.     |  |   _- .  \\ /					      \n");
	printf("\t             | `.   /  / _- .  \\  /						 \n");
	printf("\t            /    `._)  /-  . \\   /						\n");
	printf("\t           |           `.   \\  ,`							\n");
	printf("\t          /              \   ,`							 \n");
	printf("\t          |                ,`								\n");
	printf("\t          /              ,`								 \n");
	printf("\t          \\             /								    \n");
	printf("\t            |           |                                  \n");
	printf("\t            \\         / \\                               \n");
	printf("\t             \\       /   \\								\n");
	printf("\t              |     |     \\								\n");
	printf("\t              |     |\\     \\								 \n");
	printf("\t              |     | \\     \\							     \n");
	printf("\t              |     |  \\     \\							  \n");
	printf("\t             /      |   \\     \\							  \n");
	printf("\t  .-=':`-._ /       |    |     \\						     \n");
	printf("\t (.-=':.   `        | _.`       \\							 \n");
	printf("\t  (.-=':.           \\           \\						\n");
	printf("\t   (.-=':.           \\          /                        \n");
	printf("\t    (___________________________/							\n\n");
}

int game_over()
{
	printf("\n\n");
	printf("Oh! What a nightmare...");
	printf("\n\n\n");
	printf("GAME OVER");
	getchar();
	getchar();
	getchar();
	exit(0);
}

int you_win()
{
	printf("\nCongratulations! You win!!\n");
	getchar();
	exit(0);
}

void type_color()
{
	//COLOR
	system("Color B ");

	//TYPE
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 20;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Chiller"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}