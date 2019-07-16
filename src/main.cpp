#include <iostream>

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
        case CARD_9   : os << "_9";    break;
        case CARD_10: os << "_10"; break;
        case CARD_J : os << "_J";  break;
        case CARD_Q  : os << "_Q";   break;
        case CARD_K  : os << "_K";   break;
        case CARD_A  : os << "_A";   break;
        default    : os << "_CARD_UNDEFINED";
    }
    return os;
}

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
    
    for(unsigned i = 0; i<24; i++)
    {
       std:: cout << i << "-" << deck[i].colo << deck[i].fig << "-----" << deck[i].value << std::endl;
    }

    return 0;
}
