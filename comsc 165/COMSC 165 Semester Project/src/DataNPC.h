#ifndef DATANPC_H_INCLUDED
#define DATANPC_H_INCLUDED
#include "enemyBattle.h"

class Location {
    friend class Mapping;
    Battle NPC;
public:
    void DrunkFighter() {
        NPC.setEnemy(40,20,5,0,10,0,"Greatsword","Jeff the Fighter",0);
    }
    void Priest() {
    	NPC.setEnemy(30,10,20,20,10,0,"Scepter","Priest Hip O'Crit",0);
    }
    void Wolf() {
    	NPC.setEnemy(20,15,5,0,15,0,"claws","wolf",0);
    }
    void Beggar() {
    	NPC.setEnemy(10,6,5,0,5,0,"fists","beggar",0);
    }
    void Bard() {
    	NPC.setEnemy(20,5,10,0,20,30,"banjo","Wandering Bard",1);
    }
    void Spy() {
    	NPC.setEnemy(50,25,15,0,20,10,"dagger","Unknown Spy",0);
    }

};

#endif // DATANPC_H_INCLUDED
