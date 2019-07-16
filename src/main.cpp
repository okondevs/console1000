#include <iostream>
#include <vector>
#include <algorithm>

enum figure
{
    CARD_9,
    CARD_10,
    CARD_J,
    CARD_Q,
    CARD_K,
    CARD_A,
    CARD_UNDEFINED
};

enum color
{
    PIK,
    KIER,
    TREFL,
    KARO,
    COLOR_UNDEFINED
};

class Card{
    public:
        figure fig;
        color colo;
        int value;

    Card()
    {
        fig = CARD_UNDEFINED;
        colo = COLOR_UNDEFINED;
        value = -1;
    }

    Card(figure f, color c)
    {
        fig = f;
        colo = c;
        initValue();
    }

    void initValue()
    {
        if(fig == CARD_10) value = 10;
        else if(fig == CARD_J) value = 2;
        else if(fig == CARD_Q) value = 3;
        else if(fig == CARD_K) value = 4;
        else if(fig == CARD_A) value = 11;
        else value = 0;
    }
};

std::ostream& operator<<(std::ostream& os, color f)
{
    switch(f)
    {
        case PIK   : os << "PIK";    break;
        case KIER: os << "KIER"; break;
        case TREFL : os << "TREFL";  break;
        case KARO  : os << "KARO";   break;
        default    : os << "COLOR_UNDEFINED";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os,figure c)
{
    switch(c)
    {
        case CARD_9   : os << "9";    break;
        case CARD_10: os << "10"; break;
        case CARD_J : os << "J";  break;
        case CARD_Q  : os << "Q";   break;
        case CARD_K  : os << "K";   break;
        case CARD_A  : os << "A";   break;
        default    : os << "CARD_UNDEFINED";
    }
    return os;
}


class Game
{
public:
	Game(unsigned noPlayers);
	void shuffle();
	void giveCards();
	std::vector<Card> getShuffledDeck();

private:
	unsigned numberOfPlayers;
	std::vector<Card> availableCards;
	std::vector<Card> shuffledCards;
};

Game::Game(unsigned noPlayers):
	numberOfPlayers(noPlayers)
{
	this->availableCards = {
		Card(CARD_9, PIK),
		Card(CARD_10, PIK),
		Card(CARD_J, PIK),
		Card(CARD_Q, PIK),
		Card(CARD_K, PIK),
		Card(CARD_A, PIK),
		Card(CARD_9, KIER),
		Card(CARD_10, KIER),
		Card(CARD_J, KIER),
		Card(CARD_Q, KIER),
		Card(CARD_K, KIER),
		Card(CARD_A, KIER),
		Card(CARD_9, TREFL),
		Card(CARD_10, TREFL),
		Card(CARD_J, TREFL),
		Card(CARD_Q, TREFL),
		Card(CARD_K, TREFL),
		Card(CARD_A, TREFL),
		Card(CARD_9, KARO),
		Card(CARD_10, KARO),
		Card(CARD_J, KARO),
		Card(CARD_Q, KARO),
		Card(CARD_K, KARO),
		Card(CARD_A, KARO)
	};
}

void Game::shuffle()
{
//	this->shuffledCards.reserve(this->availableCards.size());
	std::copy(this->availableCards.begin(), this->availableCards.end(), std::back_inserter(this->shuffledCards));
	std::random_shuffle(this->shuffledCards.begin(), this->shuffledCards.end());
}

std::vector<Card> Game::getShuffledDeck()
{
	return this->shuffledCards;
}

class Player
{
private:
	std::vector<Card> deck;
public:
	Player();
	void setDeck(std::vector<Card> cards);

};

int main()
{
    Card * deck = new Card[24];
    int position = 0;
    for(int i = CARD_9; i != CARD_UNDEFINED; i++)
    {
        for( int j = PIK; j != COLOR_UNDEFINED; j++)
        {
            deck[position] = Card((figure)i,(color)j);
            position++;
        }
    }
	std::cout << "############ First test ################" << std::endl;
    for(int i = 0; i<24; i++)
    {
       std:: cout << i << "-" << deck[i].colo << deck[i].fig << "-----" << deck[i].value << std::endl;
    }

	std::cout << "########### Second test #############" << std::endl;
	Game g = Game(2);
	g.shuffle();
	auto gameDeck = g.getShuffledDeck();
	for(auto i = gameDeck.begin(); i < gameDeck.end(); i++)
	{
		std::cout << i->colo << "\t" << i->fig << std::endl;
	}
	std::cout << std::endl;
    return 0;
}
