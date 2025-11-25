#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int playerAtk()
{
      return 15+ (rand() % 11);
}

int heavyAttack()
{
    return 25+ (rand() % 11);
}


int heal(int playerHP)
{
    int healAmount = 10 + (rand() % 11);
    return healAmount;
}

int enemyAttack()
{
    int enemyAttack = 15+ (rand() % 11);
    return enemyAttack;
}


int main() {
    
    srand(time(0));

    int playerAtkDamage = 0;
    int healAmount = 0;
    int heavyAttackDamage = 0;
    int playerHP = 100;
    int enemyHP = 100;

    while (playerHP > 0 && enemyHP > 0) {
       
        int choice;

        cout << "\n=== Your Turn ===\n";
        cout << "Player HP: " << playerHP << " | Enemy HP: " << enemyHP << "\n";
        cout << "Choose action:\n";
        cout << "1. Attack\n";
        cout << "2. Heavy Attack\n";
        cout << "3. Heal\n";
        cout << "Enter choice: ";

        cin >> choice;

     if (choice == 1) 
     {
        playerAtkDamage = playerAtk();  
        enemyHP -= playerAtkDamage;
        cout << "You dealt " << playerAtkDamage << " damage!\n";
     }

     else if (choice == 2)
     {
       heavyAttackDamage = heavyAttack();  
       enemyHP -= heavyAttackDamage;
       cout << "Heavy attack for " << heavyAttackDamage << " damage!\n";

     }

     else if (choice == 3)
     {
        healAmount = heal(playerHP);  
        playerHP += healAmount;
        cout << "You healed for " << healAmount << " HP! Current HP: " << playerHP << "\n";

         if (playerHP > 100)
             playerHP = 100;
     }

     else 
     {
        cout << "Invalid choice, please try again!\n" << endl;
        continue;
     }

     

     if (enemyHP > 0)
     {
         int enemyDMG = enemyAttack();
         playerHP -= enemyDMG;
         cout << "Enemy dealt " << enemyDMG << " damage!\n"; 
     }
    }

    cout << "\n=== GAME OVER ===\n";
    if (playerHP <= 0)
    {
        cout << "You lost the game!\n";
    }
    else 
    {
        cout << "You won!\n";  
    }

    return 0;
}