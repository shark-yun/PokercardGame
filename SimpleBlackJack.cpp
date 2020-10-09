#include<iostream> /* for cout, cin */

#include <stdlib.h> /* srand, rand */

#include <time.h> /* time */


using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	int card_1, card_2, next_card, total = 0;
	char choiceC, choiceG; //ChoiceC is for card, G is new game
	while (true){

		card_1 = rand() % 10 + 1;
		card_2 = rand() % 10 + 1;
		total = card_1 + card_2;//total of first two cards
		cout << "First Cards:" << card_1 << " & " << card_2 << endl;
		cout << "Total : " << total << endl;
		while (true)
		{
			while (true)
			{
				cout << "\nDo you want another card? (y/n):";
				cin >> choiceC;
				if (choiceC == 'y' || choiceC == 'n')
					break;
				else
					cout << "\nPlease enter only from y or n" << endl;
			}

			if (choiceC == 'y')
			{
				next_card = rand() % 10 + 1;
				total = next_card + total;
				cout << "\n New Card is " << next_card << endl;
				cout << "\n Total:" << total << endl;

				if (total == 21)
				{
					cout << "Congratulations" << endl;
					break;
				}
				else if (total > 21)
				{
					cout << "Bust" << endl;
					break;
				}
			}
				else
				{
					break;
				}
		}
			
		
				while (true)
				{
					cout << "\n Would you like to play again? (y/n):";
					cin >> choiceG;
					if (choiceG == 'y' || choiceG == 'n')
						break;
					else
						cout << "Please enter y or n" << endl << endl;
				}
		
		if (choiceG == 'n')
			break;

	}

	return 0;

}


