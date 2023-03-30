#ifndef ENEMYBATTLE_H_INCLUDED
#define ENEMYBATTLE_H_INCLUDED

#include <iostream>
#include <string>
#include "HeroPath.h"

class Battle {
    friend class HeroPath;
    friend class InTown;
    friend class DataNPC;
    friend class MapData;
public:
    int userChoice;
    int hp;
    int atk;
    int def;
    int mag;
    int dex;
    int bard;
    int bl;
    std::string weap;
    std::string name;
    int enHp;
	int enAtk;
	int enDef;
	int enMag;
	int enDex;
	int enBard;
	int enBl;
	int damageDealt;
	std::string enWeap;
	std::string enName;
	void setUser(int thp, int tatk, int tdef, int tmag, int tdex, int tbard, std::string tweap, std::string tname, int tbl) {
		hp = thp;
		atk = tatk;
		def = tdef;
		mag = tmag;
		dex = tdex;
		bard = tbard;
		weap = tweap;
		name = tname;
		bl = tbl;
	}
	void setEnemy(int thp, int tatk, int tdef, int tmag, int tdex, int tbard, std::string tweap, std::string tname, int tbl) {
		enHp = thp;
		enAtk = tatk;
		enDef = tdef;
		enMag = tmag;
		enDex = tdex;
		enBard = tbard;
		enWeap = tweap;
		enName = tname;
		enBl = tbl;
	}
	void initCheck() {

	    while (hp > 0 && enHp > 0) {
            userAtk();
            enemyAtk();
            if (enBl == 1) {
                enHp = 0;
            }
	    }
	    death();
	}
    void userAtk() {
		std::cout << "You are facing the " << enName << ".\n"
                  << "You have " << hp << "HP.\n"
                  << "1) Melee Attack\n"
                  << "2) Magic~\n"
                  << "3) Ranged Shot\n"
                  << "4) Sing\n"
                  << "Choose:  ";
        std::cin >> userChoice;
        if (userChoice == 1) {
            std::cout << "You swing your weapon at the " << enName << ", slashing into their flesh.\n";
            damageDealt = atk - (0.5*enDef);
                if ( damageDealt <= 0) {
                    damageDealt = 1;
                }
            enHp = enHp - damageDealt;
        } else if (userChoice == 2) {
            std::cout << "You fire a magic bolt at the " << enName << "!\n";
            damageDealt = mag - enDex;
                if ( damageDealt <= 0) {
                    damageDealt = 1;
                }
                enHp = enHp - damageDealt;
        } else if (userChoice == 3) {
            std::cout << "You fire an arrow at the " << enName << "'s eyes.\n";
            damageDealt = dex - (0.5*enDef);
                if ( damageDealt <= 0) {
                    damageDealt = 1;
                }
            enHp = enHp - damageDealt;
        } else if (userChoice == 5 && enName == "Demon Lord") {
            if ( bl != 1 ) {
                    std::cout << "You don't have a book to share.\n\n";
                } else {
                    std::cout << "You give your copy of " << weap << "to the Demon Lord.\n\n";
                    enBl = 1;
                }
        } else {
            std::cout << "You sling beautifully-worded insults towards the " << enName << " as you prance around.\n";
            enHp = enHp - bard;
        }
        std::cout << std::endl;
    }
    void enemyAtk() {
        if (enAtk > enMag && enAtk > enDex) {
            std::cout << "The " << enName << " swings at you with their " << enWeap << ".\n";

            hp = hp - (enAtk - (def*0.5));
        } else if (enDex > enMag) {
            std::cout << "The " << enName << " shoots your good leg with an arrow.\n";
            hp = hp - (enDex - (def*0.5));
        } else if (enMag > enBard) {
            std::cout << "The " << enName << " throws a fireball at your hair!\n";
            hp = hp - (mag - dex);
        } else {
            std::cout << "The " << enName << " screeches into your ears.\n";
            hp = hp - enBard;
        }
        std::cout << std::endl;
    }
    void death() {
        if (hp <= 0) {
            std::cout << "You died. Nice try.\n";
        } else {
	        std::cout << "The " << enName << " died.\n";
	    }
    }
};

#endif // ENEMYBATTLE_H_INCLUDED
