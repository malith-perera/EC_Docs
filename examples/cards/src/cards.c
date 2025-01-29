#include "cards.h"
#include <stdlib.h>
#include <time.h>


typedef struct Card {
    char *face;
    char *suit;
} Card;


EC(Card);


char *face[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
char *suit[] = {"Spade", "Club", "Diamond", "Heart"};


int
main(int argc, char *argv[])
{
    Card c;
    Card *card;
    int i;;
    int rn;

    srand(time(NULL));

    //CardArray *card_array = Card_Array(52);
    Static_Array(Card, card_array, 52)

    i = 0;
    for_array(card_array, card)
    {
        card->face = face[i % 13];
        card->suit = suit[i / 13];
        i++;
    }

    for(int i = 0; i < 52; i++)
    {
        rn = rand() % 52;
        c = card_array->var[i];
        card_array->var[i] = card_array->var[rn];
        card_array->var[rn] = c;
    }

    for_array(card_array, card)
    {
        printf("%s of %s\n", card->suit, card->face);
    }

	return 0;
}
