#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
int get_hand_value(uint8_t player_hand[], uint8_t *cards_value);
int draw_card(uint8_t player_hand[], uint8_t *cards, _Bool* is_drawn);
int get_bets(uint8_t *output_array);

int main()
{
    srand(time(NULL));
    uint8_t cards_value[] = 
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
    uint8_t player_hands[8][6] = { 0 }; //Index [x][0] used to store amount of cards in hand

    uint8_t temp[] =  {0,0,0,0,0};
    get_bets(temp);



}

int get_bets(uint8_t *output_array)
{
    char input[100];
    char *endptr;
    int i = 0;
    while (i < sizeof(output_array))
    {
        errno = 0;
        printf("Player %d how much you betting \n", i);
        if(fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("error reading input \n");
        }
        else
        {
            int amount = strtol(input, &endptr, 10);
            if (errno == ERANGE)
            {
                printf("Number out of range");
            } else if (*endptr != '\n' && endptr != '\0'){
                printf("Invalid input %s\n", endptr);
            } else {
                printf("you entered: %d\n", amount);
                output_array[i] = amount;
                i ++;
            }

        }
        
    }

    return 1;
}

int get_hand_value(uint8_t player_hand[], uint8_t *cards_value)
{
    uint8_t total = 0;
    uint8_t aces = 0;
    uint8_t i = 0;
    while(i < player_hand[0])
    {
        if (cards_value[player_hand[i + 1]] != 1)
        {
            total += cards_value[player_hand[i +1]];
        }
        else
        {
            total += 1;
            aces += 1;
        }
        i += 1;
    }
    i = 0;
    while(i < aces)
    {
        if (total <= 11)
        {
            total += 10;
        }
        i += 1;
    }
    return total;
}


int draw_card(uint8_t player_hand[], uint8_t *cards, _Bool* is_drawn)
{
    uint8_t card_number = (rand() % 51);
    uint8_t its = 0;
    while(is_drawn[card_number] && its < 200)
    {
        its += 1;
        card_number = (rand() % 51);
    }
    is_drawn[card_number] = true;
    player_hand[player_hand[0]+1] = card_number;
    player_hand[0] += 1;

    return card_number;
}





