#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int get_hand_value(int player_hand[]);
int draw_card(uint_fast8_t player_hand[], uint_fast8_t *cards, _Bool* is_drawn);

int main()
{
    srand(time(NULL));
    uint_fast8_t cards_value[] = 
    {1,1,1,1,
    2,2,2,2,
    3,3,3,3,
    4,4,4,4,
    5,5,5,5,
    6,6,6,6,
    7,7,7,7,
    8,8,8,8,
    9,9,9,9,
    10,10,10,10,
    10,10,10,10,
    10,10,10,10,
    10,10,10,10};
    _Bool is_drawn[52] = { false };
    char* cards_name[] = 
    {"ACE", "TWO","THREE", 
    "FOUR","FIVE", "SIX", 
    "SEVEN", "EIGHT", "NINE", 
    "TEN", "KNIGHT", "QUEEN", "KING"};
    uint_fast8_t player_hands[8][6] = { 0 };
    int test = draw_card(player_hands[0], cards_value, is_drawn);

}


int get_hand_value(int player_hand[])
{

}


int draw_card(uint_fast8_t player_hand[], uint_fast8_t *cards, _Bool* is_drawn)
{
    uint8_t card_number = (rand() % 51);
    uint8_t its = 0;
    while(is_drawn[card_number] && its < 200)
    {
        its += 1;
        card_number = (rand() % 51);
    }
    is_drawn[card_number] = true;
    printf("%d, %d", card_number, its);


    return card_number;
}





