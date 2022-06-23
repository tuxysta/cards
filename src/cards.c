#include "../include/cards.h"
#include <stdlib.h>
#include <stdio.h>

// Standard Fischer-Yates algorithm.
void shuffle_cards(card *const deck, const size_t num_cards)
{
    for (int i = num_cards; i; i--)
    {
        card temp = deck[i];
        deck[i] = deck[rand() % i];
        deck[rand() % num_cards] = temp;
    }
}

// Draw the card num_from_the_top cards from the top of the deck.

card draw_card(const card *deck, const size_t num_cards, const size_t num_from_the_top)
{
    return deck[num_from_the_top];
}

// Write the deck to `fp`. This is done in a simple plaintext format.
void write_cards(const card *deck, const size_t num_cards, FILE *fp)
{
    const char rank_to_char[13] = {'K', 'Q', 'J', 'X', '9', '8', '7', '6', '5', '4', '3', '2', 'A'};
    const char suit_to_char[4] = {'C', 'D', 'H', 'S'};
    for (int i = 0; i < num_cards; i++)
    {
        fputc(rank_to_char[deck[i].rank], fp);
        fputc(suit_to_char[deck[i].suit], fp);
        fputc('\n', fp);
    }
}

// Read num_cards cards from fp.

card *read_cards(FILE *fp, const size_t num_cards)
{
    const rank_t char_to_rank[128] = {['K'] = king,
                                      ['Q'] = queen,
                                      ['J'] = jack,
                                      ['X'] = ten,
                                      ['9'] = nine,
                                      ['8'] = eight,
                                      ['7'] = seven,
                                      ['6'] = six,
                                      ['5'] = five,
                                      ['4'] = four,
                                      ['3'] = three,
                                      ['2'] = two,
                                      ['A'] = ace};
    const suit_t char_to_suit[128] = {['C'] = clubs, ['D'] = diamonds, ['H'] = hearts, ['S'] = spades};
    card *cards = malloc(num_cards * sizeof(*cards));
    for (int i = 0; i < num_cards; i++)
    {
        cards[i].rank = char_to_rank[fgetc(fp)];
        cards[i].suit = char_to_suit[fgetc(fp)];
        if (fgetc(fp) != '\n')
            return NULL;
    }

    return cards;
}