#include <stdio.h>
#include <stdlib.h>

#pragma region basic declarations

/* =========================================================
   Forward declarations
   ========================================================= */

typedef struct Game Game;
typedef struct GameState GameState;

/* =========================================================
   Game state interface
   ========================================================= */

struct GameState {
    void (*enter)(Game *game);
    void (*update)(Game *game);
    void (*render)(Game *game);
    void (*exit)(Game *game);
};

/* =========================================================
   Game data
   ========================================================= */

struct Game {
    const GameState *state;

    int player_hp;
    int player_max_hp;

    int enemy_hp;
    int enemy_max_hp;

    int potions;

    int running;
};

#pragma endregion

#pragma region states

/* =========================================================
   State transition
   ========================================================= */

void change_state(Game *game, const GameState *new_state)
{
    if (game->state != NULL && game->state->exit != NULL) {
        game->state->exit(game);
    }

    game->state = new_state;

    if (game->state != NULL && game->state->enter != NULL) {
        game->state->enter(game);
    }
}

/* =========================================================
   Forward declarations for states
   ========================================================= */

extern const GameState MENU_STATE;
extern const GameState PLAYING_STATE;
extern const GameState PAUSED_STATE;
extern const GameState GAME_OVER_STATE;
extern const GameState VICTORY_STATE;

#pragma endregion

#pragma region menu state

/* =========================================================
   MENU STATE
   ========================================================= */

void menu_enter(Game *game)
{
    (void)game;

    printf("\n");
    printf("=================================\n");
    printf("        ASCII DUNGEON GAME       \n");
    printf("=================================\n");
}

void menu_update(Game *game)
{
    int choice;

    printf("\n");
    printf("1. Start Game\n");
    printf("2. Quit\n");
    printf("> ");

    scanf("%d", &choice);

    if (choice == 1) {
        game->player_max_hp = 100;
        game->player_hp = 100;

        game->enemy_max_hp = 50;
        game->enemy_hp = 50;

        game->potions = 3;

        change_state(game, &PLAYING_STATE);
    }
    else if (choice == 2) {
        game->running = 0;
    }
    else {
        printf("Invalid choice.\n");
    }
}

void menu_render(Game *game)
{
    (void)game;
}

void menu_exit(Game *game)
{
    (void)game;
}

const GameState MENU_STATE = {
    menu_enter,
    menu_update,
    menu_render,
    menu_exit
};

#pragma endregion

#pragma region playing state

/* =========================================================
   PLAYING STATE
   ========================================================= */

void playing_enter(Game *game)
{
    printf("\n");
    printf("You enter the dungeon...\n");
}

void playing_update(Game *game)
{
    int choice;
    int damage;

    printf("\n");
    printf("-----------------------------\n");
    printf("Player HP : %d/%d\n",
           game->player_hp,
           game->player_max_hp);

    printf("Enemy HP  : %d/%d\n",
           game->enemy_hp,
           game->enemy_max_hp);

    printf("Potions   : %d\n", game->potions);

    printf("-----------------------------\n");
    printf("1. Attack\n");
    printf("2. Use Potion\n");
    printf("3. Pause\n");
    printf("4. Run Away\n");
    printf("> ");

    scanf("%d", &choice);

    switch (choice) {

        case 1:
            /* Player attacks */
            damage = 10 + rand() % 11;

            printf("You attack for %d damage!\n", damage);

            game->enemy_hp -= damage;

            /* Enemy died */
            if (game->enemy_hp <= 0) {
                game->enemy_hp = 0;
                change_state(game, &VICTORY_STATE);
                return;
            }

            /* Enemy attacks */
            damage = 5 + rand() % 11;

            printf("Enemy attacks for %d damage!\n", damage);

            game->player_hp -= damage;

            /* Player died */
            if (game->player_hp <= 0) {
                game->player_hp = 0;
                change_state(game, &GAME_OVER_STATE);
            }

            break;

        case 2:
            if (game->potions > 0) {

                game->potions--;

                game->player_hp += 25;

                if (game->player_hp > game->player_max_hp) {
                    game->player_hp = game->player_max_hp;
                }

                printf("You drink a potion.\n");

                /* Enemy gets a free attack */
                damage = 5 + rand() % 11;

                printf("Enemy attacks for %d damage!\n", damage);

                game->player_hp -= damage;

                if (game->player_hp <= 0) {
                    game->player_hp = 0;
                    change_state(game, &GAME_OVER_STATE);
                }
            }
            else {
                printf("You have no potions left!\n");
            }

            break;

        case 3:
            change_state(game, &PAUSED_STATE);
            break;

        case 4:
            printf("You run away!\n");
            change_state(game, &GAME_OVER_STATE);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }
}

void playing_render(Game *game)
{
    /*
       Usually graphics would be drawn here.

       In this text game, update() already prints everything,
       so there is nothing else to render.
    */

    (void)game;
}

void playing_exit(Game *game)
{
    printf("Leaving the battle...\n");
    (void)game;
}

const GameState PLAYING_STATE = {
    playing_enter,
    playing_update,
    playing_render,
    playing_exit
};

#pragma endregion

#pragma region paused state

/* =========================================================
   PAUSED STATE
   ========================================================= */

void paused_enter(Game *game)
{
    (void)game;

    printf("\n");
    printf("=================================\n");
    printf("             PAUSED              \n");
    printf("=================================\n");
}

void paused_update(Game *game)
{
    int choice;

    printf("\n");
    printf("1. Resume\n");
    printf("2. Quit\n");
    printf("> ");

    scanf("%d", &choice);

    if (choice == 1) {
        change_state(game, &PLAYING_STATE);
    }
    else if (choice == 2) {
        game->running = 0;
    }
    else {
        printf("Invalid choice.\n");
    }
}

void paused_render(Game *game)
{
    (void)game;
}

void paused_exit(Game *game)
{
    printf("Resuming game...\n");
    (void)game;
}

const GameState PAUSED_STATE = {
    paused_enter,
    paused_update,
    paused_render,
    paused_exit
};

#pragma endregion

#pragma region game over state

/* =========================================================
   GAME OVER STATE
   ========================================================= */

void game_over_enter(Game *game)
{
    printf("\n");
    printf("=================================\n");
    printf("           GAME OVER             \n");
    printf("=================================\n");

    printf("You died.\n");
}

void game_over_update(Game *game)
{
    int choice;

    printf("\n");
    printf("1. Restart\n");
    printf("2. Quit\n");
    printf("> ");

    scanf("%d", &choice);

    if (choice == 1) {

        game->player_hp = game->player_max_hp;
        game->enemy_hp = game->enemy_max_hp;
        game->potions = 3;

        change_state(game, &PLAYING_STATE);
    }
    else if (choice == 2) {
        game->running = 0;
    }
    else {
        printf("Invalid choice.\n");
    }
}

void game_over_render(Game *game)
{
    (void)game;
}

void game_over_exit(Game *game)
{
    (void)game;
}

const GameState GAME_OVER_STATE = {
    game_over_enter,
    game_over_update,
    game_over_render,
    game_over_exit
};

#pragma endregion

#pragma region victory state

/* =========================================================
   VICTORY STATE
   ========================================================= */

void victory_enter(Game *game)
{
    printf("\n");
    printf("=================================\n");
    printf("            VICTORY!             \n");
    printf("=================================\n");

    printf("You defeated the monster!\n");
}

void victory_update(Game *game)
{
    int choice;

    printf("\n");
    printf("1. Play Again\n");
    printf("2. Quit\n");
    printf("> ");

    scanf("%d", &choice);

    if (choice == 1) {

        game->player_hp = game->player_max_hp;
        game->enemy_hp = game->enemy_max_hp;
        game->potions = 3;

        change_state(game, &PLAYING_STATE);
    }
    else if (choice == 2) {
        game->running = 0;
    }
    else {
        printf("Invalid choice.\n");
    }
}

void victory_render(Game *game)
{
    (void)game;
}

void victory_exit(Game *game)
{
    (void)game;
}

const GameState VICTORY_STATE = {
    victory_enter,
    victory_update,
    victory_render,
    victory_exit
};

#pragma endregion

/* =========================================================
   MAIN
   ========================================================= */

int main(void)
{
    Game game = {0};

    game.running = 1;
    game.state = NULL;

    /* Start at menu */
    change_state(&game, &MENU_STATE);

    /* Main game loop */
    while (game.running) {

        if (game.state->update != NULL) {
            game.state->update(&game);
        }

        if (game.state->render != NULL) {
            game.state->render(&game);
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}