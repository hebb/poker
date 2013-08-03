#include <iostream>
#include <cstdlib>

using namespace std;

struct card
{
	string rank;
	string suit;
};
struct hand
{
	card first;
	card second;
};

void draw_card(bool *deck, card *card);
void shuffle_deck(bool *deck);

int main()
{
	bool deck[52];
	shuffle_deck(deck);
	hand player1;
	draw_card(deck, &player1.first);
	draw_card(deck, &player1.second);

	cout << "Player 1 was dealt ";
	if (player1.first.rank == "Ace" || player1.first.rank == "Eight")
	{
		cout << "an ";
	}
	else
	{
		cout << "a ";
	}
	cout << player1.first.rank << " of " << player1.first.suit << " and ";
	if (player1.second.rank == "Ace" || player1.second.rank == "Eight")
	{
		cout << "an ";
	}
	else
	{
		cout << "a ";
	}
	cout << player1.second.rank << " of " << player1.second.suit << "." << endl;

	return 0;
}

void draw_card(bool *deck, card *card)
{
	int n, rank, suit;
	srand (time(NULL));
	do
	{
		n = rand() % 52;
	} while (deck[n]);
	deck[n] = 1;
	rank = n % 13 + 1;
	suit = n / 13 + 1;
	switch (rank)
	{
		case 1: card->rank = "Ace"; break;
		case 2: card->rank = "Two"; break;
		case 3: card->rank = "Three"; break;
		case 4: card->rank = "Four"; break;
		case 5: card->rank = "Five"; break;
		case 6: card->rank = "Six"; break;
		case 7: card->rank = "Seven"; break;
		case 8: card->rank = "Eight"; break;
		case 9: card->rank = "Nine"; break;
		case 10: card->rank = "Ten"; break;
		case 11: card->rank = "Jack"; break;
		case 12: card->rank = "Queen"; break;
		case 13: card->rank = "King";
	}
	switch (suit)
	{
		case 1: card->suit = "Spades";  break;
		case 2: card->suit = "Hearts"; break;
		case 3: card->suit = "Diamonds"; break;
		case 4: card->suit = "Clubs";
	}
}

void shuffle_deck(bool *deck)
{
	int i;
	for (i=0; i<52; i++)
	{
		deck[i] = 0;
	}
}
