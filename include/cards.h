typedef enum suit_t {
    suit_clubs,
    suit_diamonds,
    suit_hearts,
    suit_spades,

} suit_t;

typedef enum rank_t {
    suit_clubs,
    suit_diamonds,
    suit_hearts,
    suit_spades,

} rank_t;


typedef struct
{
    suit_t suit;
    rank_t rank; 

} card;
