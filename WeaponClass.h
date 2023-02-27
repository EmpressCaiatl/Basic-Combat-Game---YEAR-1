/* CS 202 FALL 2020
    This skeleton code was developed by James Piotrowski - UNLV Computer Science
*/

#include <string>
#include <cstdlib>
using namespace std;

/********************************************************************************************************/
/*                              Weapon Class                                                             */
/********************************************************************************************************/
class WeaponClass {
public:
	WeaponClass();						// Constructor 						
	string GetName();					// GetName returns the WeaponName
	void SetWeapon(string);				// Changes the Weapon Name			
	int CalculateDamage(int, int);		// Determines damage dealt by weapon
private:
	string name;			// The Weapon Name - "Sword", "Bow", "Staff", or "Bare Hands"
	const int Damage = 3;	// Base Damage for all Weapons except Bare Hands
};

//YOUR CODE HERE

WeaponClass::WeaponClass() {

	name = "Bare Hands";
}

string WeaponClass::GetName(){

	return name;
	
}

void WeaponClass::SetWeapon(string weapon) {

	if ((weapon != "Sword") && (weapon != "Bow") && (weapon != "Staff")) {

		name = "Bare Hands";

		cout << "ERROR: Unknown Weapon" << endl;

	}
	else {

		name = weapon;
	}

}

int WeaponClass::CalculateDamage(int strength, int skill) {

	bool checkWeapon = false;  //for checking if the weapon is a valid choice, if not, one of these will statements will run

	if (name == "Sword") {

		cout << "**CLANG**" << endl;
		checkWeapon = true;
		return (strength * Damage);

	}

	if (name == "Staff") {

		cout << "**POW**" << endl;
		checkWeapon = true;
		return (skill * Damage);

	}

	if (name == "Bow") {

		cout << "**FWOOSH**" << endl;
		checkWeapon = true;
		return (Damage-abs( strength - skill)) * Damage;

	}

	if (checkWeapon == false) {

		cout << "**pfft**" << endl;
		return 1;

	}
}

