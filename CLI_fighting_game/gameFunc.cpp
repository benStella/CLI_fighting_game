#include <iostream>
using namespace std;


// game mechanics
void gameFunc()
{
    // variables
    string startFight;
    string playerName;
    string attack;
    int round = 1;
    int playerHealth = 100;
    int playerAttack = 10;
    int enemyHealth = 10;
    int enemyAttack = 10;

    cout << "Name of Player:";
    cin >> playerName;

    while (true)
    {
        cout << "would " + playerName + " like to fight:";
        cin >> startFight;

        // begin fight loop
        if (startFight == "yes")
        {
            cout << "round:" << round << endl;
            cout << "would you like to attack or heal: ";
            cin >> attack;

            // if type in "attack" subtract enemy health with player attack and cout value
            if (attack == "attack")
            {
                enemyHealth = enemyHealth - playerAttack;
                cout << "enemy has " << enemyHealth << " hp left" << endl;
            }
            // if type in "heal" subtract one potion and heal player
            else if (attack == "heal")
            {
                playerHealth = playerHealth + 10;
                cout << "player now has " << playerHealth << " left" << endl;
            }

            // random number for enemy attack
            srand(time(0));
            int random = rand() % 2;

            // if random is 0 the enemy attacks
            if (random == 0)
            {
                playerHealth = playerHealth - enemyAttack;
                cout << "player has " << playerHealth << " hp left" << endl;
            }
            // if random is 1 the enemy heals
            else if (random == 1)
            {
                enemyHealth = enemyHealth + 10;
                cout << "enemy now has " << enemyHealth << " hp left" << endl;
            }

            if (enemyHealth == 0)
            {
                round = round += 1;
                enemyHealth = round * 10;
            }
        }

        // if startFight is no then exit
        if (startFight == "no")
        {
            cout << "goodbye";
            return;
        }
    }
}