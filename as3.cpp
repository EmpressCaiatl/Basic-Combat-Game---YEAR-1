/* CS 202 FALL 2020
    This skeleton code was developed by James Piotrowski - UNLV Computer Science
*/

#include "PlayerClass.h"

using namespace std;

int main() {
    cout << "/****\\ GAME START /****\\\n";
    //Red Players
    RedClass r[4];
    r[0].EquipWeapon("Sword");
    r[1].EquipWeapon("Staff");
    r[2].EquipWeapon("Bow");
    r[3].EquipWeapon("Saradomin Godsword"); //This will give the player Bare Hands
    //Blue Players
    BlueClass b[3];
    b[0].EquipWeapon("Sword");
    b[1].EquipWeapon("Staff");
    b[2].EquipWeapon("Bow");
    //Green Players
    GreenClass g[3];
    g[0].EquipWeapon("Sword");
    g[1].EquipWeapon("Staff");
    g[2].EquipWeapon("Bow");
    cout << "************************\nThere are " << PlayerClass::GetPlayerCount() << " Players.\n************************\n";
    r[3].DoDamage(g[2]);
    g[2].DoDamage(r[1]);
    b[1].DoDamage(r[1]);
    //R1 Cant battle anymore
    cout << endl << r[3].GetPlayerName() << " - {I can't believe this Red is using a Bow!}\n" << endl;
    r[3].DoDamage(r[2]);
    cout << endl << r[2].GetPlayerName() << " - {It is better than bare fists!}\n" << endl;
    r[2].DoDamage(r[3]);
    cout << endl << b[1].GetPlayerName() << " - {ENOUGH OF THIS CHILDISH BICKERING NOOBS!}\n" << endl;
    b[1].DoDamage(r[2]);
    b[1].DoDamage(r[3]);
    b[1].DoDamage(r[2]);
    b[1].DoDamage(r[3]);
    //R3 and R2 are out... 
    cout << endl << r[0].GetPlayerName() << " - {My teammates! I AM ENRAGED!}\n" << endl;
    r[0].DoDamage(b[1]);
    r[0].DoDamage(b[1]);
    cout << endl << g[2].GetPlayerName() << " - {Here.. I can help!}\n" << endl;
    g[2].DoDamage(b[1]);
    //b1 is gone
    cout << endl << r[0].GetPlayerName() << " - {I DID NOT WANT YOUR HELP!}\n" << endl;
    r[0].DoDamage(g[2]);
    r[0].DoDamage(g[2]);
    //G2 gone
    g[0].DoDamage(b[0]);
    b[0].DoDamage(g[0]);
    g[0].DoDamage(b[0]);
    g[1].DoDamage(b[2]);
    b[2].DoDamage(g[1]);
    g[1].DoDamage(b[2]);
    g[0].DoDamage(b[0]);
    g[1].DoDamage(b[2]);
    //B2 and B0 Gone
    r[0].DoDamage(g[0]);
    r[0].DoDamage(g[1]);
    r[0].DoDamage(g[0]);
    r[0].DoDamage(g[1]);
    //G0 and G1 gone
    cout << endl << r[0].GetPlayerName() << " - {I AM THE CHAMPION!}\n" << endl;
    cout << "/****\\ GAME OVER /****\\\n";
    return 0;
}