#ifndef CARDS_H_INCLUDED
#define CARDS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef enum suit_t
{
    clubs,
    diamonds,
    hearts,
    spades
} suit_t;

typedef enum rank_t
{
    king,
    queen,
    jack,
    ten,
    nine,
    eight,
    seven,
    six,
    five,
    four,
    three,
    two,
    ace,
    joker

} rank_t;

typedef struct
{
    suit_t suit;
    rank_t rank;
} card;

void shuffle_cards(card *deck, const size_t num_cards);
card draw_card(const card *deck, const size_t num_cards, const size_t num_from_the_top);
void write_cards(const card *deck, const size_t num_cards, FILE *fp);
card *read_cards(FILE *fp, const size_t num_cards);

#endif