// Yun Lin

#include <iostream>
#include <cstdlib> 
#include <algorithm>
using namespace std;

bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);
int NextCard(const int hand[], int num);

/* Array practice
bool noNegatives(const int array[], int size) {
	bool positive = false;
	for (int count = 0; count < size; count++) {
		if (array[count] < 0)
			return false;
	}

	return positive;
}

void absoluteValues(int array[], int size) {
	for (int count = 0; count < size; count++) {
		if (array[count] < 0)
			array[count] = (-1) * array[count];
	}
}

/**/




const int numOfCards = 5;

typedef	int hand[numOfCards];

int main()
{
	hand hand;

	cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;

	for (int count = 0; count < (numOfCards); count++)
	{
		cout << "Card " << (count + 1) << " : ";
		cin >> hand[count];    // Fill in the input statement to place Card in the array
	}
	

	sort(hand, hand + numOfCards);


	if (containsFourOfaKind(hand)) {
		cout << "Contians four of a kind!" << endl;
	}
	else if (containsFullHouse(hand)) {
		cout << "Contians full House!" << endl;
	}
	else if (containsStraight(hand)) {
		cout << "Contians straight!" << endl;
	}
	else if (containsThreeOfaKind(hand)) {
		cout << "Contians three of a kind!" << endl;
	}
	else if (containsTwoPair(hand)) {
		cout << "Contians two pair!" << endl;
	}
	else if (containsPair(hand)) {
		cout << "Contians a pair!" << endl;
	}
	else {
		cout << "Contians high card!" << endl;
	}
	return 0;


}



bool  containsPair(const int hand[]) {

	for (int count = 0; count < numOfCards; count++) {
		if (NextCard(hand, hand[count]) == 2) {
			return true;
		}
	}

			return false;
	
}

bool  containsTwoPair(const int hand[]) {
	for (int i = 0; i < numOfCards; i++) {
		if (NextCard(hand, hand[i]) == 2) {
			for (int count = 1; count < numOfCards; count++) {
				if (NextCard(hand, hand[count]) == 2) {
					return true;
				}
			}
		}
	}
	return false;
}


bool  containsThreeOfaKind(const int hand[]) {

	for (int i = 0; i < numOfCards; i++) {
		if (NextCard(hand, hand[i]) == 3) {
			return true;
		}

	}
	return false;
		
}

bool  containsStraight(const int hand[]) {
	
	for (int count = 0; count < numOfCards; count++) {
		if (hand[count + 1] != hand[count]+1) {
			return false;
		}
	}
	return true;

}

bool  containsFullHouse(const int hand[]) {
	
	for (int i = 0; i < numOfCards; i++) {
		if (NextCard(hand, hand[i]) == 3) {
			for (int count = 0; count < numOfCards; count++) {
				if (NextCard(hand, hand[numOfCards]) == 2) {
					return true;
				}
			}
		}
		else if (NextCard(hand, hand[i]) == 2) {
			for (int count = 0; count < numOfCards; count++) {
				if (NextCard(hand, hand[numOfCards]) == 3) {
					return true;
				}
			}
		}
		 else return false;
	}
	
}




bool containsFourOfaKind(const int hand[]) {
	int count = 0;
	for (int i = 0; i < numOfCards; i++) {
		int card1 = hand[i];
		count = NextCard(hand, card1);
		if (count == 4) {
			return true;
		}
	}
	if (count < 4) {
		return false;
	}
}

int NextCard(const int hand[], int card1) {
	int count = 0;
	for (int i = 0; i < numOfCards; i++) {
		if (hand[i] == card1) {
			count++;
		}
	}
	return count;
}
