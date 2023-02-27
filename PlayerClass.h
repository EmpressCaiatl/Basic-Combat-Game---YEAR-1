/* CS 202 FALL 2020
    This skeleton code was developed by James Piotrowski - UNLV Computer Science
*/

#include <fstream> 
#include "WeaponClass.h"

using namespace std;
/********************************************************************************************************/
/*                              Super Class                                                             */
/********************************************************************************************************/
class PlayerClass {
public:
    PlayerClass();                          // Constructors                             
    PlayerClass(char, string, int, int);  //                                        
    ~PlayerClass();                         //Destructor
    void EquipWeapon(string);             // Will alter the Weapon in the WeaponSlot. 
    void DoDamage(PlayerClass&);          // Will do damage to another player.        
    void TakeDamage(int);                 // A function to subract from HealthPoints. 

    char GetPlayerType();        // Returns the PlayerType  
    string GetPlayerName();      // Returns the PlayerName  
    static int GetPlayerCount(); // Returns the PlayerCount -- This is Static

// Protected Members. Derived class instances will be able to inheret and access these members. Protected is not accesible to anything but the Base Class and Derived Classes. 
protected:
    string PlayerName;          // PlayerName --> {PlayerType Color} + {PlayerCount} --> i.e. "Red1", "Blue2", "Blue3", "Green4", etc..
    char PlayerType;            // Either 'r', 'b', 'g'
    int Strength;               // Strength Level
    int Skill;                  // Skill Level
    int HealthPoints;           // Health Points --> 25 By default
    WeaponClass WeaponSlot;     // Choice of Weapon
    static int PlayerCount;     // Keeps track of the number of Players. Should be incremented in Constructors -- Notice it is Static   
    ofstream out;               // For the Player Log
};

//YOUR CODE HERE
int PlayerClass::PlayerCount = 0;

PlayerClass::PlayerClass() {

    Strength = 0;
    Skill = 0;
    HealthPoints = 25;
    PlayerType = '\0';
    PlayerName = "";

    PlayerCount++;

    //this is backup
    //I should print the name of character and add number to the end
}

PlayerClass::PlayerClass(char typeP, string nameP, int strP, int skillP) {

    Strength = strP;
    Skill = skillP;
    PlayerName = nameP + to_string(PlayerCount);
    PlayerType = typeP;
    HealthPoints = 25;

    PlayerCount++;

    string fileName = PlayerName + ".txt";
    out.open(fileName);

    out << PlayerName << " has been spawned." << endl;

    //same as above
}

PlayerClass::~PlayerClass() {

    if (out.is_open()) {

        out << PlayerName << " has been despawned." << endl;
           
        out.close();
    }

}

void PlayerClass::TakeDamage(int damageToPlayer) {

    cout << PlayerName << " has taken " << damageToPlayer << " damage!" << endl;

    out << PlayerName << " took " << damageToPlayer << " damage." << endl;

    if ((HealthPoints - damageToPlayer) < 0) {

        HealthPoints = 0;
        cout << PlayerName << " has reached 0 health! They can no longer battle..." << endl;
        out << PlayerName << " has reached 0 health." << endl;

    }
    else {

        HealthPoints -= damageToPlayer;

    }

}

void PlayerClass::DoDamage(PlayerClass& damageToThis){

    damageToThis.TakeDamage(this->WeaponSlot.CalculateDamage(Strength, Skill));
    
}

void PlayerClass::EquipWeapon(string weaponEquip) {

    WeaponSlot.WeaponClass::SetWeapon(weaponEquip);

    out << PlayerName << " equipped a " << WeaponSlot.WeaponClass::GetName() << "." << endl;

}

 char PlayerClass::GetPlayerType()  {

    return PlayerType;

}

string PlayerClass::GetPlayerName() {

    return PlayerName;
}

int PlayerClass::GetPlayerCount() {

    return PlayerCount;
}

/********************************************************************************************************/
/*                              Red Class                                                             */
/********************************************************************************************************/
class RedClass: public PlayerClass{
public:
    RedClass();                     // Constructor         
    void DoDamage(PlayerClass&);    // DoDamage Override  
};

//YOUR CODE HERE

RedClass::RedClass():PlayerClass('r',"Red", 3,1) {}

void RedClass::DoDamage(PlayerClass& passPlayer) {

    cout << this->GetPlayerName() << " is attacking " << passPlayer.GetPlayerName() << "." << endl;
    out << this->GetPlayerName() << "is attacking " << passPlayer.GetPlayerName() << "." << endl;

    int dealerDamageDelt = WeaponSlot.CalculateDamage(Strength, Skill);

    //statements check if player taking damage is of a certain type, damage delt accordingly
    if (passPlayer.GetPlayerType() == 'r') {

        dealerDamageDelt = dealerDamageDelt/2;
        passPlayer.TakeDamage(dealerDamageDelt);

        cout << "That was not very effective..." << endl;

    }

    if (passPlayer.GetPlayerType() == 'b') {

        passPlayer.TakeDamage(dealerDamageDelt);

    }

    if (passPlayer.GetPlayerType() == 'g') {

        dealerDamageDelt = 2 * dealerDamageDelt;
        passPlayer.TakeDamage(dealerDamageDelt);

        cout << "That was super effective" << endl;
    }
}

/********************************************************************************************************/
/*                              Blue Class                                                             */
/********************************************************************************************************/
class BlueClass: public PlayerClass{
public:
    BlueClass();                    // Constructor         
    void DoDamage(PlayerClass&);    // DoDamage Override     
};

//YOUR CODE HERE

BlueClass::BlueClass() :PlayerClass('b', "Blue", 1, 3) {}

void BlueClass::DoDamage(PlayerClass& passPlayer) {

    cout << this->GetPlayerName() << " is attacking " << passPlayer.GetPlayerName() << "." << endl;
    out << this->GetPlayerName() << "is attacking " << passPlayer.GetPlayerName() << "." << endl;

    int dealerDamageDelt = WeaponSlot.CalculateDamage(Strength, Skill);

    if (passPlayer.GetPlayerType() == 'b') {

        dealerDamageDelt = dealerDamageDelt/2;
        passPlayer.TakeDamage(dealerDamageDelt);

        cout << "That was not very effective..." << endl;

    }

    if (passPlayer.GetPlayerType() == 'g') {

        passPlayer.TakeDamage(dealerDamageDelt);

    }

    if (passPlayer.GetPlayerType() == 'r') {

        dealerDamageDelt = 2 * dealerDamageDelt;
        passPlayer.TakeDamage(dealerDamageDelt);

        cout << "That was super effective" << endl;
    }
}

/********************************************************************************************************/
/*                              Green Class                                                             */
/********************************************************************************************************/
class GreenClass: public PlayerClass{
public:
    GreenClass();                   // Constructor         
    void DoDamage(PlayerClass&);    // DoDamage Override    
};

GreenClass::GreenClass():PlayerClass('g', "Green", 2, 2) {}

void GreenClass::DoDamage(PlayerClass& passPlayer) {

    cout << this->GetPlayerName() << " is attacking " << passPlayer.GetPlayerName() << "." << endl;
    out << this->GetPlayerName() << "is attacking " << passPlayer.GetPlayerName() << "." << endl;

    int dealerDamageDelt = WeaponSlot.CalculateDamage(Strength, Skill);

    if (passPlayer.GetPlayerType() == 'g') {

        dealerDamageDelt = dealerDamageDelt/2;
        passPlayer.TakeDamage(dealerDamageDelt);

        cout << "That was not very effective..." << endl;

    }

    if (passPlayer.GetPlayerType() == 'r') {

        passPlayer.TakeDamage(dealerDamageDelt);

    }

    if (passPlayer.GetPlayerType() == 'b') {

        dealerDamageDelt = 2 * dealerDamageDelt;
        passPlayer.TakeDamage(dealerDamageDelt);

        cout << "That was super effective" << endl;

    }
}

