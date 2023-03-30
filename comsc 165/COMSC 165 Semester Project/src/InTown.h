#ifndef INTOWN_H_INCLUDED
#define INTOWN_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include "enemyBattle.h"
#include "MapData.h"

class InTown {
public:
    friend class Mapping;
    Mapping Map;
    Battle Town;
    void sendoffScript() {
        std::cout << "The king proclaims, \n"
             << "   \"Wonderful! There is-\" \n"
             << "then stops to look at you, his eyes burning with indignant rage.\n"
             << "   \"You DARE reject my command, turn away the order of the King himself?!\n"
             << "   What insolence is this, that my subject denies his duty to the Kingdom!\n"
             << "   If you wish to waste your time despite all my efforts, then so be it.\n"
             << "   Guards! Escort this man out into the streets; he is no longer welcome\n"
             << "   in my abode.\"\n"
             << "And so, the guards took you by the arms and forced you out of the throne room.\n"
             << "They stop by the barracks, as if searching for something, while leaving you \n"
             << "alone in the room. You look around and see three things: a small pouch, a sword,\n"
             << "and a lyre.\n\n"
             << "What do you do?\n"
             << "1) Take the pouch\n"
             << "2) Take the key\n"
             << "3) Take the lyre\n"
             << "4) Do nothing\n";
    }
    int makeChoice(int &choice) {
        std::cout << "Choose:  ";
        std::cin >> choice;
        this->choiceStart = choice;
        std::cout << std::endl;
        return choiceStart;
    }
    void choiceMade() {
        switch(choiceStart) {
            case 1:
                wealth += 30;
                break;
            case 2:
                hasKey = true;
                break;
            case 3:
                hasLyre = true;
                break;
            default:
                break;
        }
        std::cout << "The guards return carrying a set of leather armor and a few weapons. One of them hands you\n"
                  << "the armor and says,\n"
                  << "  \"You'll need some form of self-protection. It's our kingdom law to make sure every person\n"
                  << "  can at least protect themselves at all times. Here's some armor, and you can pick a weapon.\"\n"
                  << "He motions to the now-cleared off table where a selection of fine-looking weapons lay.\n"
                  << "1) Longsword\n"
                  << "2) Staff\n"
                  << "3) Bow and Quiver\n";
                  armor_set = "leather armor";
                  makeChoice(choiceStart);
    }
    void classChoose() {
        switch(choiceStart) {
        case 1:
            Town.setUser(50,15,15,0,10,0,"sword","Hero",0);
            break;
        case 2:
            Town.setUser(30,5,15,20,10,0,"staff","Hero",0);
            break;
        case 3:
            Town.setUser(40,10,15,10,20,0,"bow","Hero",0);
            break;
        default:
            Town.setUser(40,5,15,0,10,0,"fists","Hero",0);
            std::cout << "The guard looks at you strangely, but says nothing.\n";
            break;
        }
        if (hasLyre) {
            Town.bard = 25;
        }
        std::cout << "Once you are equipped and ready to be kicked out, you are promptly dropped off in the\n"
                  << "main street.\n\n";
        Map.Street();
    }
    void status() {
    std::cout << Town.name << "'s Status\n"
              << "HP: " << Town.hp << "\n"
              << "ATK: " << Town.atk << "\n"
              << "DEF: " << Town.def << "\n"
              << "MAG: " << Town.mag << "\n"
              << "DEX: " << Town.dex << "\n"
              << "MUS: " << Town.bard << "\n"
              << "Equipped: " << Town.weap << ", " << armor_set << "\n"
              << "Wealth: " << wealth << " gold\n"
              << "Press any key to go back." << std::endl;
    std::cin >> gameChoice;
    }
    void gotoMap(int location) {
        if (location == 2) Map.Inn();
        if (location == 3) Map.Forest();
        if (location == 4) Map.Alleyway();
        if (location == 5) Map.Street();
    }

    std::string gameChoice;
    int choiceStart;
    bool hasKey;
    int wealth;
    bool hasLyre;
    bool hasSword;
    bool hasBownArrow;
    bool hasGreatSword;
    bool hasStaff;
    bool hasNote;
    bool hasClue;
    bool hasEvidence;
    int timesSlept;
    std::string armor_set;
};

#endif // INTOWN_H_INCLUDED
