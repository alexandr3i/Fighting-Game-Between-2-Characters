#include <iostream>
#include <cstring>
using namespace std;
class Character{

public:

    virtual void displayCharacterInfo(){};
    virtual void actions(Character &c){};

    void setName(string n){
        this->name = n;
    }

    void setHealth(int h){
        this->health = h;
    }

    void setMana(int m){
        this->mana = m;
    }

    void setStamina(int s){
        this->stamina = s;
    }

    void setDamage(int d){
        this->damage = d;
    }

    string getName(){
        return this->name;
    }

    int getHealth(){
        return this->health;
    }

    int getMana(){
        return this->mana;
    }

    int getStamina(){
        return this->stamina;
    }

    int getDamage(){
        return this->damage;
    }

    void modifyName(){
        string n;
        cout<<"Enter a name for your character:";
        cin>>n;
        this->setName(n);
    }

    void modifyStamina(){
        int s;
        cout<<"Enter stamina for your character:";
        cin>>s;
        this->setStamina(s);
    }

    void modifyHealth(){
        int h;
        cout<<"Enter health for your character:";
        cin>>h;
        this->setHealth(h);
    }

    void modifyDamage(){
        int d;
        cout<<"Enter damage for your character:";
        cin>>d;
        this->setDamage(d);
    }

    void modifyMana(){
        int m;
        cout<<"Enter mana for your character:";
        cin>>m;
        this->setMana(m);
    }


protected:
    string name;
    int health;
    int mana;
    int stamina;
    int damage;

};

class Hero: public Character{

public:

    int healingPotions;
    int healingPotionsPoints;

    Hero(){
        cout<<"We are now creating the Hero!"<<endl;
        this->modifyName();
        this->modifyHealth();
        this->modifyStamina();
        this->modifyDamage();
        this->modifyMana();
        this->modifyPotionsNo();
        this->modifyPotionsPoints();
    }

    void heal(){
        this->setHealth(this->getHealth() + this->getHealingPotionsPoints());
        this->setHealingPotions(this->getHealingPotions() - 1);
    }

    void attack(Character &c){
        c.setHealth(c.getHealth() - this->getDamage());
    }

    void actions(Character &c) override{

        int action;
        do{
            cout<<"Enter what action do you want to execute: "<<endl;
            cout<<"1. Sword Attack"<<endl;
            cout<<"2. Heal Yourself"<<endl;
            cout<<"3. Show Stats"<<endl;
            cin>>action;

            if(action < 1 || action > 3)
                cout<<"Wrong action. Try again";
        }while(action < 1 || action > 3);

        switch(action){
            case 1:
                attack(c);
                break;
            case 2:
                heal();
                break;
            case 3:
                this->displayCharacterInfo();
                break;
            default:
                break;
        }
    }

    void setHealingPotions(int h){
        this->healingPotions = h;
    }

    void setHealingPotionsPoints(int hpp){
        this->healingPotionsPoints = hpp;
    }

    int getHealingPotions(){
        return this->healingPotions;
    }

    int getHealingPotionsPoints(){
        return this->healingPotionsPoints;
    }

    void modifyPotionsNo(){
        int numPotions;
        cout<<"Enter number of potions:";
        cin>>numPotions;
        this->setHealingPotions(numPotions);
    }

    void modifyPotionsPoints(){
        int potionsPower;
        cout<<"Enter potion power:";
        cin>>potionsPower;
        this->setHealingPotionsPoints(potionsPower);
    }

    void displayCharacterInfo() override{
        cout<<endl<<"================"<<endl;
        cout<<"Name: "<<this->getName()<<endl;
        cout<<"Health: "<<this->getHealth()<<endl;
        cout<<"Damage: "<<this->getDamage()<<endl;
        cout<<"Stamina: "<<this->getStamina()<<endl;
        cout<<"Mana: "<<this->getMana()<<endl;
        cout<<"Number of healing potions: "<<this->getHealingPotions()<<endl;
        cout<<"The HP points you will get by consuming one potion: "<<this->getHealingPotionsPoints()<<endl;
        cout<<"================"<<endl;
    };

};

class Enemy: public Character{

public:

    int numberOfArrows = 10;
    int arrowDamage = 10;

    void setNumberOfArrows(int a){
        this->numberOfArrows = a;
    }

    void setArrowDamage(int ad){
        this->arrowDamage = ad;
    }

    int getNumberOfArrows(){
        return this->numberOfArrows;
    }

    int getArrowDamage(){
        return this->arrowDamage;
    }

    Enemy(){
        cout<<"We are now creating the Enemy"<<endl;
        this->modifyName();
        this->modifyHealth();
        this->modifyStamina();
        this->modifyDamage();
        this->modifyMana();
        this->modifyArrowsNo();
        this->modifyArrowsDmg();
    }
    void bowAttack(Character &c){
        c.setHealth(c.getHealth() - this->getArrowDamage());
        this->setNumberOfArrows(this->getNumberOfArrows() - 1);
    }

    void daggerAttack(Character &c){
        c.setHealth(c.getHealth() - this->getDamage());
    }

    void actions(Character &c) override{
        int action;
        do{
            cout<<"Enter what action do you want to execute: "<<endl;
            cout<<"1. Dagger Attack"<<endl;
            cout<<"2. Bow attack"<<endl;
            cout<<"3. Show Stats"<<endl;
            cin>>action;

            if(action < 1 || action > 3)
                cout<<"Wrong action. Try again";
        }while(action < 1 || action > 3);

        switch(action){
            case 1:
                bowAttack(c);
                break;
            case 2:
                daggerAttack(c);
                break;
            case 3:
                this->displayCharacterInfo();
                break;
            default:
                break;
        }

    }

    void modifyArrowsNo(){
        int arrows;
        cout<<"Enter number of arrows:";
        cin>>arrows;
        this->setNumberOfArrows(arrows);
    }

    void modifyArrowsDmg(){
        int arrowDmg;
        cout<<"Enter the arrow damage:";
        cin>>arrowDmg;
        this->setArrowDamage(arrowDmg);
    }
    void displayCharacterInfo() override{
        cout<<endl<<"================"<<endl;
        cout<<"Name: "<<this->getName()<<endl;
        cout<<"Health: "<<this->getHealth()<<endl;
        cout<<"Damage: "<<this->getDamage()<<endl;
        cout<<"Stamina: "<<this->getStamina()<<endl;
        cout<<"Mana: "<<this->getMana()<<endl;
        cout<<"Number of arrows: "<<this->getNumberOfArrows()<<endl;
        cout<<"The damage of each arrow: "<<this->getArrowDamage()<<endl;
        cout<<"================"<<endl;
    };

};

void printMenu(){
    cout<<"================"<<endl;
    cout<<"Select which character you want to control:"<<endl;
    cout<<"0. Stop the game"<<endl;
    cout<<"1. The Hero Character"<<endl;
    cout<<"2. The Enemy Character"<<endl;
    cout<<"================"<<endl;
}

int main() {
    Hero hero = *new Hero();
    Enemy enemy = *new Enemy();

    bool shouldStop = false;
    while(!shouldStop){

        if(hero.getHealth() <= 0){
            cout<<hero.getName()<<" is dead! "<<enemy.getName()<<" won! Thank you for playing"<<endl;
            shouldStop = true;
        }

        if(enemy.getHealth() <= 0){
            cout<<enemy.getName()<<" is dead! "<<hero.getName()<<" won! Thank you for playing"<<endl;
            shouldStop = true;
        }

        if(enemy.getHealth() > 0 && hero.getHealth() > 0) {
            int command;
            printMenu();
            cin >> command;
            switch (command) {
                case 0:
                    shouldStop = true;
                    break;
                case 1:
                    hero.actions(enemy);
                    break;
                case 2:
                    enemy.actions(hero);
                    break;
                default:
                    cout << "Wrong index try again!";
                    break;
            }
        }
    }

    return 0;
}