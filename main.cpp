#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

//Hit enter to progress the game.

using namespace std;
//Parent class
class Creature{
	protected:
		int type;//0 = human, 1= cyberdemon, 2 = barlog, 3 = elf.
		int strength;// how much damage we can inflict.
		int hitpoints; //how much damage we can sustaine
		int size;// size is how hard or easy a creature/demo is to hit. A smaller creature is harder to hit thana a larger creature.
		// size =1 is a small creature and gets +2 added to its armor class making it 14 to hit creature,
		// size = 2 is a medium sized crature and gets +0 and remains at AC 12;, size =3 is a large crature and gets a -2 to its armorclass becuase it is large and easier to hit.
		int armorClass; // armor class is the number that must be met or surpassed to actually hit a creature/demon.
		//armor class is calculated by a randol number of 1-20, to simulate a 20 sided die. any random number over over the value of the armor class is a hit and damage
		// then can be taken from the indivdual creature.

	public:
		Creature();
		//initialize to human, 10 str, 10 hp
		Creature(int newType, int newStrength, int newHit, int newSize, int newArmorClass);
		//initialize creature to new type, strength, hit points

		//accessor, mutator prottypes
		void setType(int);
		int getType();
		void setStrength(int);
		int getStrength();
		void setHitpoints(int);
		int getHitpoints();
		void setSize(int);
		int getSize();
		void setArmorClass(int);
		int getArmorClass();

		int getDamage(){
			string getSpecies();

           int damage;
           //All creatures inflict damage which is a random number uo to their strength
	       damage = (rand() % strength) + 1;
	       		//Elves inflict double magical damage with a 10% chance
        		if(type == 3){
                	if(rand() % 50 == 0){
	             		damage = damage * 2;
        			}
    			}
			 //Demons can inflict damage of 50 with 5% chance
         	if(type ==2 || type == 1){
	        	if((rand() % 100) < 25){
		        	damage = damage + 50;
                }
	       }
        //Barlogs are so fast they get two attacks per round
        if(type == 2){
            int damage2 = (rand() % strength + 1);
            damage = damage + damage2;
        }
        cout << "Creature damage is "<< damage<<endl;
	return damage;
}

 		// gets the species for cretures(Human,elf)
		string getSpecies(){
			switch(type){
				case 0: return "Human";
				case 1: return "Cyberdemon";
				case 2: return "Barlog";
				case 3: return "Elf";
			}
			return "Unknown";
		}
};
//constructor
Creature::Creature(int newType, int newStrength, int newHit, int newSize, int newArmorClass){
	type = newType;
	strength = newStrength;
	hitpoints =newHit;
	size = newSize;
	armorClass = newArmorClass;
}
//default constructor
Creature::Creature(){
	type = 0;
	strength = 10;
	hitpoints = 10;
	size = 2;
	armorClass = 12;
}

//Parent class
//demon/creture
class Demon:public Creature{
	public:
		Demon();
		Demon(int newType, int newStrength, int newHit, int newSize, int newArmorClass):Creature(newType, newStrength, newHit, newSize, newArmorClass){}// nob-default constructor with initializer list.

    int getDamage(){
            int damage;

        //All creatures inflict damage which is a random number uo to their strength
        damage = (rand() % strength) + 1;
        //Demons can inflict damage of 50 with 5% chance
        if(type ==2 || type == 1){
            if((rand() % 100) < 25){
                damage = damage + 50;
            }
        }
        //Barlogs are so fast they get two attacks per round
        if(type == 2){
            int damage2 = (rand() % strength + 1);
            damage = damage + damage2;
        }
           cout << "Demon damage is "<< damage<<endl;     
	   return damage;
   }
};

//sets and gets, mutators and accessors
void Creature::setType(int type){
	this->type = type;
}
int Creature::getType(){
	return type;
}

void Creature::setStrength(int strength){
	this->strength = strength;
}
int Creature::getStrength(){
	return strength;
}

void Creature::setHitpoints(int hitpoints){
	this->hitpoints = hitpoints;
}
int Creature::getHitpoints(){
	return hitpoints;
}

void Creature::setSize(int size){
	this->size = size;
}
int Creature::getSize(){
	return size;
}

void Creature::setArmorClass(int armorClass){
	this->armorClass = armorClass;
}

int Creature::getArmorClass() {
	return armorClass;
}
// end mutator/accessors

//child classes start
//human/creature class
class Human:public Creature{
	public:
		Human();
		Human(int newType, int newStrength, int newHit, int newSize, int newArmorClass):Creature(newType, newStrength, newHit, newSize, newArmorClass){}

		int getDamage(){
            int damage;
	        //All creatures inflict damage which is a random number to their strength
         	damage = (rand() % strength) + 1;
	        return damage;
        }
};

//elf/creature
class Elf:public Creature{
	public:
		Elf();
		Elf(int newType, int newStrength, int newHit, int newSize, int newArmorClass):Creature(newType, newStrength, newHit, newSize, newArmorClass){}

		int getDamage(){
               int damage;
  	         damage = (rand() % strength) + 1;
  	         if(type == 3){
   	        	if(rand() % 10 == 0){
			          damage = damage * 2;
            	}
              }
          return damage;
      }
};

//cyberdemon/demo
class Cyberdemon:public Demon{
	public:
		Cyberdemon();
		Cyberdemon(int newType, int newStrength, int newHit, int newSize, int newArmorClass):Demon(newType, newStrength, newHit, newSize, newArmorClass){}

		int getDamage(){
            int damage;

	        //All creatures inflict damage which is a random number uo to their strength
	        damage = (rand() % strength) + 1;

	        //Demons can inflict damage of 50 with 5% chance
	        if(type ==2 || type == 1){
	        	if((rand() % 100) < 5){
		     	damage = damage + 50;
               }
	       }
	       return damage;
      }
};
//barlog/demon
class Barlog:public Demon{
	public:
		Barlog();
		Barlog(int newType, int newStrength, int newHit, int newSize, int newArmorClass):Demon(newType, newStrength, newHit, newSize, newArmorClass){}

		int getDamage(){
            int damage;

	        //All creatures inflict damage which is a random number uo to their strength
	        damage = (rand() % strength) + 1;

	        //Demons can inflict damage of 50 with 5% chance
	        if(type ==2 || type == 1){
		        if((rand() % 100) < 5){
                    damage = damage + 50;
                }
	        }

	        //Barlogs are so fast they get two attacks per round
	        if(type == 2){
		        int damage2 = (rand() % strength + 1);
		        damage = damage + damage2;
            }
	      return damage;
      }
};
//child classes end

//function prototype foo battleSimulation.
int battleSim(Barlog *barlog2, Elf *elf2);

//int main
int main(int argc, char** argv) {
	 srand(time(NULL));
	 //class objects
	 Elf elf(3, 130, 500, 1, 14);
	 Human human(0, 10, 10, 2, 12);
     Cyberdemon cyberdemon(1, 10, 10, 3, 10);
	 Barlog barlog(2, 100, 500, 3, 10);
	 //object pointers
	 Barlog *barlog2;
	 barlog2 = &barlog;
	 Elf *elf2;
	 elf2 = &elf;
    //function call
	 battleSim(barlog2, elf2);
	return 0;
}

// function to handle the combat simulation
int battleSim(Barlog *barlog2, Elf *elf2){
	//couts for the LOLs
	cout<<"Lets get readyyy to ruuuuuuuumbleeee.\n";
	cout<<"This first contest is a death match.\n "
		<<"Two men enter, one man leaves.\n";
	cout<<"to my right in the green trunks.\n"
		<<"fighting out of the Woodland Realm of Northern Mirkwood.\n"
		<<"He's mean, loves green, and makes a mean pot pie.\n"
		<<"Please put your hands together for Prince Legolas."<<endl;
	cout<<"*\n";
	cout<<"*\n";
	cout<<"Now for our next contestant.\n"
	    <<"to my left in the red trunks.\n"
		<<"He's also mean and one of the ugliest demons you'll ever see\n"
		<<"please put your hands together for the reigning,"
		<< "undisputed Middle Earth champion\n"
		<<"Balrog, elf bane"<<endl;
	cout<<"*\n";
	cout<<"*\n";
	cout<<"Referee: Ok, I want a clean fight. No hitting below the belt\n"
		<<"no eye poking, spiting or stomping toes\n"
		<<" Ok, lets get it on.\n"
		<<"Ring side bell: Ding, Ding"<<endl<<endl;

		int firstAttack = rand() % 2 + 1;//if firstAttack = 1 barlogattacks first, 2 elf attacks first.

		while(barlog2->getHitpoints() != 0 || elf2->getHitpoints() != 0){// the -> is replacing the pointer asterisk and the dot in one, allowing me to use the pointer as the object.
			//variables for attack, damage, and healthpoints for elf and barlog
			int damage = barlog2->getDamage();
			int health = barlog2->getHitpoints();
			int damage2 = elf2->getDamage();
			int health2 = elf2->getHitpoints();
			int attack1 = rand() % 20 + 1;//barlog2 attack
			int attack2 = rand() % 20 + 1;//elf2 attack
			int totalHealth;
			// determines who will attack first
			switch(firstAttack){

				case 1:
				    // if barlogs attack value is greater than the elfs armorclass there is a hit
   				 if(attack1 >= elf2->getArmorClass()){
				    	cout<<"Barlog attacks the elf for "<<damage<<" points!"<<endl;// get damage
			    		totalHealth = health2 - damage;//calculates the elfs health after the barlogs attack
			    		elf2->setHitpoints(totalHealth);// sets elfs hitpoints.
					}
					else{
						cout<<"Balrogog Misses"<<endl;// output for the miss
					}
					firstAttack++; //if firstAttack = 1 this incrementer adds one, making it 2 so the elf will get his attack;
					break;
			   case 2:
			   		// ifelfs attack value is greater than the barlogs armorclass there is a hit
					if (attack2 >= barlog2->getArmorClass()) {
						cout <<"Elf attacks the Balrog for "<<damage2<<" points! "<<endl;// get damage
						totalHealth = health - damage2;//calculates the barlog health after the elfs attack
						barlog2->setHitpoints(totalHealth);// sets elfs hitpoints.
					}
					else{
						cout<<"Elf Misses"<<endl;// output for the miss
					}
					firstAttack--;//if firstAttack = 2 this decrementer subtracts one, making it 1 so the barlog will get his attack;
					break;
			}
			//hitpoint output for each contestant
			cout<<"*\n";
			cout<<"*\n";
			cout<<"*\n";
			cout<<barlog2->getSpecies()<<" hit points are "<< barlog2->getHitpoints()<<endl;
			cout<<elf2->getSpecies()<<" hit points are "<< elf2->getHitpoints()<<endl;
			cout<<"*\n";
			cout<<"*\n";


			// determines the winner and outputs appropriate
			if(barlog2->getHitpoints() <= 0){
    			cout<<"Elf wins"<<endl;
    			break;
			}
			else if(elf2->getHitpoints() <= 0){
				cout<<"Barlog wins"<<endl;
				break;
			}
			cin.ignore();
    	}
    	return firstAttack;
}