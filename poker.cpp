#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct card
{
	string rank;
	string suit;
	int rank_number;
	int suit_number;
};

void draw_card(bool *deck, card *card);
void shuffle_deck(bool *deck);
int evaluate(vector<card> hand);
bool isFlush(vector<card> hand);
bool isStraight(vector<card> hand);

int main()
{
	bool deck[52];
	shuffle_deck(deck);
	/*
	card player1[2];
	card player2[2];
	card board[5];
	card hand1[7];
	card hand2[7];
	*/
	
	vector<card> player1 (2);
	vector<card> player2 (2);
	vector<card> board (5);
	vector<card> hand1 (7);
	vector<card> hand2 (7);
	
	int i;
	
	
	draw_card(deck, &player1[0]);
	draw_card(deck, &player2[0]);
	draw_card(deck, &player1[1]);
	draw_card(deck, &player2[1]);
	draw_card(deck, &board[0]);
	draw_card(deck, &board[1]);
	draw_card(deck, &board[2]);
	draw_card(deck, &board[3]);
	draw_card(deck, &board[4]);
	
	
	// test
	/*
	player1[0].rank_number = 3;
	player1[0].rank = "Three";
	player1[0].suit_number = 1;
	player1[0].suit = "Spades";
	player1[1].rank_number = 9;
	player1[1].rank = "Nine";
	player1[1].suit_number = 4;
	player1[1].suit = "Clubs";
	player2[0].rank_number = 8;
	player2[0].rank = "Eight";
	player2[0].suit_number = 4;
	player2[0].suit = "Clubs";
	player2[1].rank_number = 13;
	player2[1].rank = "King";
	player2[1].suit_number = 2;
	player2[1].suit = "Hearts";
	board[0].rank_number = 11;
	board[0].rank = "Jack";
	board[0].suit_number = 2;
	board[0].suit = "Hearts";
	board[1].rank_number = 2;
	board[1].rank = "Two";
	board[1].suit_number = 3;
	board[1].suit = "Diamonds";
	board[2].rank_number = 12;
	board[2].rank = "Queen";
	board[2].suit_number = 1;
	board[2].suit = "Spades";
	board[3].rank_number = 10;
	board[3].rank = "Ten";
	board[3].suit_number = 3;
	board[3].suit = "Diamonds";
	board[4].rank_number = 8;
	board[4].rank = "Eight";
	board[4].suit_number = 3;
	board[4].suit = "Diamonds";
	*/
	
	for (i=0;i<2;i++)
	{
		hand1[i] = player1[i];
		hand2[i] = player2[i];
	}
	for (i=0;i<5;i++)
	{
		hand1[i+2] = board[i];
		hand2[i+2] = board[i];
	}

	cout << "Player 1 was dealt the " << player1[0].rank << " of " << player1[0].suit << " and the " << player1[1].rank << " of " << player1[1].suit << "." << endl;
	cout << "Player 2 was dealt the " << player2[0].rank << " of " << player2[0].suit << " and the " << player2[1].rank << " of " << player2[1].suit << "." << endl;

	cout << "The community cards are " << endl;
	cout << "the " << board[0].rank << " of " << board[0].suit << "," << endl;
	cout << "the " << board[1].rank << " of " << board[1].suit << "," << endl;
	cout << "the " << board[2].rank << " of " << board[2].suit << "," << endl;
	cout << "the " << board[3].rank << " of " << board[3].suit << "," << endl;
	cout << "and the " << board[4].rank << " of " << board[4].suit << "." << endl;

	if (isFlush(hand1))
	{
		cout << "Player 1 has a flush." << endl;
	}
	else
	{
		cout << "Player 1 does not have a flush." << endl;
	}
	
	if (isFlush(hand2))
	{
		cout << "Player 2 has a flush." << endl;
	}
	else
	{
		cout << "Player 2 does not have a flush." << endl;
	}
	
	if (isStraight(hand1))
	{
		cout << "Player 1 has a straight." << endl;
	}
	else
	{
		cout << "Player 1 does not have a straight." << endl;
	}
	
	if (isStraight(hand2))
	{
		cout << "Player 2 has a straight." << endl;
	}
	else
	{
		cout << "Player 2 does not have a straight." << endl;
	}

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
	card->rank_number = rank;
	card->suit_number = suit;
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

int evaluate(vector<card> hand)
{
	return 0;
}

bool isFlush(vector<card> hand)
{
	int suits[4] = {0, 0, 0, 0};
	int i, limit;
	
	limit = hand.size();
	
	for (i=0;i<limit;i++)
	{
		suits[hand[i].suit_number-1] += 1;
	}
	for (i=0;i<4;i++)
	{
		if (suits[i]>4)
		{
			return 1;
		}
	}
	
	return 0;
}

bool isStraight(vector<card> hand)
{
	int i, j, head, tail, limit;
	
	limit = hand.size();
	
	int rank[limit];
	
	for (i=0; i<limit; i++)
	{
		rank[i] = hand[i].rank_number;
	}
	
	for(j=0; j < (limit - 4); j++)
	{
		head = rank[j];
		tail = rank[j];
		
		for (i=j+1; i<limit; i++)
		{
			
			if (rank[i] == head - 1)
			{
				head = rank[i];
				i = j;
			}
			else if (rank[i] == tail + 1)
			{
				tail = rank[i];
				i = j;
			}
			if (tail - head == 4)
			{
				return 1;
			}
		}
		
		for (i=limit-5; i<4; i++)
		{
			if (tail - head == i)
			{
				return 0;
			}
		}
	}
	
	return 0;
}
