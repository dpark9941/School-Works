/*#include "HeroPath.h"
#include "InTown.h"
#include "enemyBattle.h"
#include <iostream>

using namespace std;
HeroPath Yes;
InTown No;
Battle DemonL;

void pathDefine() {
    int decision = 0;
    string choicePath;
    cout << "Answer:  ";
    cin >> choicePath;
    if (choicePath == "No" || choicePath == "no") {
        No.sendoffScript();
        No.makeChoice(decision);
        No.choiceMade();
        No.classChoose();
        No.status();
    } else {
        Yes.KingDecree();
        Yes.makeChoice(decision);
        Yes.ClassChoose(decision);
        Yes.ClassSet(decision);
        Yes.DecisionMade();
        Yes.EnemySet();
        Yes.BattleInit();
    }
}


int main()
{
    Yes.KingRequest();
    pathDefine();

    return 0;
}

*/
