#ifndef HEROPATH_H_INCLUDED
#define HEROPATH_H_INCLUDED
#include "InTown.h"
#include "enemyBattle.h"

class HeroPath {
    friend class InTown;
    Battle DemonLord;
    int berHp;
    int msHp;
    std::string className;
    std::string classWeap;
	public:
        std::string choicePath;
	    int choice;
		void KingRequest() {
			std::cout << "Light blinds you for a moment, and you find yourself standing in the middle of a lavishly decorated\n"
					  << "medieval court. Atop a wide-seated gold throne, you see an obese white-haired man with a well-groomed \n"
					  << "beard sitting with an arm on each armrest, his layers of fat jiggling as he breathes in to speak.\n"
					  << "   \"Hero, you have been summoned by the 13 most powerful mages of our land, to be blessed with unimaginable  \n"
					  << "   power and courage. As you have been summoned by my mage order, you are my subject.  And I, King Taulkaton, \n"
					  << "   beseech thee to save us humans from the encroaching swarms of demonic spawn invading our world. \n "
					  << "   Hero, save the world from the Demon Lord!\" \n\n";
		}
		void ClassChoose(int choice) {
            switch (choice) {
				case 1:
				className = "Knight";
				classWeap = "Holy Sword Excantibur";
				break;
				case 2:
				className = "Mage";
				classWeap = "Staff of All-Powerful Magics";
				break;
				case 3:
				className = "Ranger";
				classWeap = "Power V Infinity Bow";
				break;
				case 4:
				className = "Berserker";
				classWeap = "Bigger Holy Sword Excouldibur";
				berHp = 5000;
				break;
				case 5:
				className = "Homeboy Weeb";
				classWeap = "book titled Yuusha ga Onnanoko ni Sarechau Hon";
				break;
				default:
				className = "Bard";
				classWeap = "Flute of Magical Potential";
				break;
            }
        }
		void KingDecree() {
            std::cout << "   \"Wonderful! There is no time to waste; go to the royal barracks. Our Head Commander Sucmahpi \n"
                 << "   shall teach you ancient royal swordplay, High Lead Mage Elmo shall train your magical talents, \n"
                 << "   Head Tracker Nightsound shall test and sharpen your keen aim, Demon Killer Niccage shall help \n"
                 << "   you discover and control your inner latent powers and refine them for true battle and carnage,\n"
                 << "   and the librarian... well I personally don't understand what she does, but her intellectual ability\n"
                 << "   is rivaled by none else. In your time here, I hope you choose to find your true talents given our \n"
                 << "   resources. So Hero! Slay the vile demons, and smite the notorious Demon Lord in his castle of horrors!\" \n"
                 << "You are ushered out and trained vigorously under the masters, finally realizing your talent as a...\n"
                 << " 1) Knight\n"
                 << " 2) Mage\n"
                 << " 3) Ranger\n"
                 << " 4) Berserker\n"
                 << " 5) Homeboy\n\n";
        }
        int makeChoice(int &choice) {
            choice = 0;
            std::cout << "Choose:  ";
            std::cin >> choice;
            this->choice = choice;
            return choice;
        }
        void DecisionMade() {
            std::cout << "You find your talents in being a " << className << " and declare such to King Taulkaton. His Highness nods and motions \n"
                 << "to his advisor, who steps forward and hands you the " << classWeap << ", then backs away. A few \n"
                 << "days later, you set off, accompanied by Elmo and Sucmahpi as well as a thousand troops to massacre the \n"
                 << "million-strong demon swarm allegedly invading Human territory.\n";
        }
		void ClassSet(int choice) {
            switch (choice) {
                case 1:
                    DemonLord.setUser(5000,1500,2000,100,100,0,classWeap,className,0);
                break;
                case 2:
                    DemonLord.setUser(3000,100,1500,4000,500,10,classWeap,className,0);
                break;
                case 3:
                    DemonLord.setUser(4000,100,1600,100,4000,0,classWeap,className,0);
                break;
                case 4:
                    DemonLord.setUser(5000,2000,1200,100,100,0,classWeap,className,0);
                break;
                case 5:
                    DemonLord.setUser(1000,100,20000,100,100,0,classWeap,className,1);
                break;
                default:
                    DemonLord.setUser(4000,700,1200,100,100,9001,classWeap,className,0);
                break;
            }
}
        void EnemySet() {
            DemonLord.setEnemy(15000,1300,900,100,100,100,"Deirmavien","Demon Lord",0);
        }
        int EnemyDeath() {
            std::cout << "As you deal the final blow, the Demon Lord cries out,\n"
                 << " 	\"I congratulate you, Hero, for slaying an just man in his house, and slaughtering innocents in your wake. \n"
                 << "   Your so-called righteous King sent you here, a groomed assassin, to kill me, the Demon Lord Tabaxas. For\n"
                 << "   what purpose? Peace? You have only brought destruction, you fiend. You have been swayed by blind greed and\n"
                 << "   have spilt unneeded blood. For your crimes, I curse you Hero! Atone for your sins and transgressions in the\n"
                 << "   past!\" \n"
                 << "With that, he explodes into a whirling mass of dark magic and consumes and burns through your flesh. Your vision fades\n"
                 << "into darkness.\n\n"
                 << "As you awaken... ";
                 EnemySet();
                 KingRequest();
                 return 0;
        }
        void turnCheck() {
            while (DemonLord.enHp > 0 && DemonLord.hp > 0) {
                if (className == "Berserker") {
                    msHp = berHp - DemonLord.hp;
                    DemonLord.atk = DemonLord.atk + (0.5 * msHp);
                }
                DemonLord.userAtk();
                DemonLord.enemyAtk();
                if (DemonLord.enBl == 1) {
                    DemonLord.enHp = 0;
                }
            }
            if (DemonLord.enBl == 1) {
                std::cout << "The Demon Lord takes a look into your book and dissolves into magic particles before exploding in all \n"
                        << "directions. As you return triumphantly from vanquishing the Demon Lord, you see demon children being \n"
                        << "skewered by farmers as humans invade demon lands.\n"
                        << "The King thanks you for your work, then locks you in the dungeons for the attempting to murder him.\n"
                        << "The humans thus create an empire and champion the genocide of all non-humans, ultimately leading to ruin.\n\n";
            } else if (DemonLord.enHp <= 0) {
                EnemyDeath();
            } else if (DemonLord.hp <= 0) {
                    std::cout << "You, the Hero, has died. No one cares.\n\n";
            }
        }
        void BattleInit() {
            std::cout << "You cut through masses of demonic creatures running at you without armor, your comrades all dying in the melee.\n"
                 << "and confront the Demon Lord. As he had just finished his evening bath, he is unprepared and undressed, but manages\n"
                 << "to summon a pitch-black sword out of nowhere.\n"
                 << "   \"You! Who are you to break into my home and draw a holy weapon against me?!\" \n"
                 << "You remain silent, as there is no need to parlay with the Demon Lord, and charge at him.\n";
                 turnCheck();
        }
};

#endif // HEROPATH_H_INCLUDED
