#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#endif

#define clear_terminal() printf("\e[1;1H\e[2J")
#define print_at(x, y, c) printf("\033[%d;%dH%s", x, y, c)

typedef enum {
  None = 0,
  White = 1,
  Black = 2,
} BoardValue;

typedef enum {
  BottomLeft = 0,
  BottomCenter = 1,
  BottomRight = 2,
  Right = 3,
  TopRight = 4,
  TopCenter = 5,
  TopLeft = 6,
  Left = 7,
} BoardRingPosition;

typedef enum {
  Outer = 0,
  Middle = 1,
  Inner = 2,
} BoardRing;

short board_state[3];

int set_board_position(BoardRing ring, BoardRingPosition position,
                       BoardValue value) {
  board_state[ring] =
      (board_state[ring] & ~(3 << position)) | (value << position);
  return 1;
}

char position_symbols[24] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                             ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                             ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void draw() {
  int i;
  const char symbol_arr[3] = {' ', 'X', 'O'};

  for (i = 0; i < 3; i += 1) {

  }

  /* Simple, hardcoded, linear draw. Does not work well with autoformatting
   * though. */
  printf("┌───┐             ┌───┐             ┌───┐\n");
  printf("│ %c ├─────────────┤ %c ├─────────────┤ %c │\n", position_symbols[21],
         position_symbols[22], position_symbols[23]);
  printf("└─┬a7             └──d7             └─┬g7\n");
  printf("  │   ┌───┐       ┌───┐       ┌───┐   │\n");
  printf("  │   │ %c ├───────┤ %c ├───────┤ %c │   │\n", position_symbols[18],
         position_symbols[19], position_symbols[20]);
  printf("  │   └─┬b6       └──d6       └─┬f6   │\n");
  printf("  │     │   ┌───┐ ┌───┐ ┌───┐   │     │\n");
  printf("  │     │   │ %c ├─┤ %c ├─┤ %c │   │     │\n", position_symbols[15],
         position_symbols[16], position_symbols[17]);
  printf("  │     │   └─┬c5 └──d5 └─┬e5   │     │\n");
  printf("┌─┴─┐ ┌─┴─┐ ┌─┴─┐       ┌─┴─┐ ┌─┴─┐ ┌─┴─┐\n");
  printf("│ %c ├─┤ %c ├─┤ %c │       │ %c ├─┤ %c ├─┤ %c │\n",
         position_symbols[9], position_symbols[10], position_symbols[11],
         position_symbols[12], position_symbols[13], position_symbols[14]);
  printf("└─┬a4 └─┬b4 └─┬c4       └─┬e4 └─┬f4 └─┬g4\n");
  printf("  │     │   ┌─┴─┐ ┌───┐ ┌─┴─┐   │     │\n");
  printf("  │     │   │ %c ├─┤ %c ├─┤ %c │   │     │\n", position_symbols[6],
         position_symbols[7], position_symbols[8]);
  printf("  │     │   └──c3 └──d3 └──e3   │     │\n");
  printf("  │   ┌─┴─┐       ┌───┐       ┌─┴─┐   │\n");
  printf("  │   │ %c ├───────┤ %c ├───────┤ %c │   │\n", position_symbols[3],
         position_symbols[4], position_symbols[5]);
  printf("  │   └──b2       └──d2       └──f2   │\n");
  printf("┌─┴─┐             ┌───┐             ┌─┴─┐\n");
  printf("│ %c ├─────────────┤ %c ├─────────────┤ %c │\n", position_symbols[0],
         position_symbols[1], position_symbols[2]);
  printf("└──a1             └──d1             └──g1\n");
}

unsigned int str_compare(const char *a, const char *b, const int length) {
  int i;
  for (i = 0; i < length; i += 1) {
    if (!*a || !*b || *a != *b)
      return 0;
    a += 1;
    b += 1;
  }
  return 1;
}

int get_index_for_coordinate_str(const char *coordinate) {
  switch (coordinate[0]) {
  case 'a':
    break;
  case 'b':
    break;
  case 'c':
    break;
  case 'd':
    break;
  case 'e':
    break;
  case 'f':
    break;
  case 'g':
    break;
  default:
    return -1;
  }

  switch (coordinate[1]) {
  case '1':
    switch (coordinate[0]) {
    case 'a':
      return 0;
    case 'd':
      return 1;
    case 'g':
      return 2;
    default:
      return -1;
    }
  case '2':
    switch (coordinate[0]) {
    case 'b':
      return 3;
    case 'd':
      return 4;
    case 'f':
      return 5;
    default:
      return -1;
    }
  case '3':
    switch (coordinate[0]) {
    case 'c':
      return 6;
    case 'd':
      return 7;
    case 'e':
      return 8;
    default:
      return -1;
    }
  case '4':
    switch (coordinate[0]) {
    case 'a':
      return 9;
    case 'b':
      return 10;
    case 'd':
      return 11;
    case 'e':
      return 12;
    case 'f':
      return 13;
    case 'g':
      return 14;
    default:
      return -1;
    }
  case '5':
    switch (coordinate[0]) {
    case 'c':
      return 15;
    case 'd':
      return 16;
    case 'e':
      return 17;
    default:
      return -1;
    }
  case '6':
    switch (coordinate[0]) {
    case 'b':
      return 18;
    case 'd':
      return 19;
    case 'f':
      return 20;
    default:
      return -1;
    }
    break;
  case '7':
    switch (coordinate[0]) {
    case 'a':
      return 21;
    case 'd':
      return 22;
    case 'g':
      return 23;
    default:
      return -1;
    }
  default:
    return -1;
  }
}

int main(void) {
  /* Game is broken up in two, potentially 3, phases:
   * 1 Placement phase
   * 2 Movement phase
   * 3 Jump phase
   */
  char player_turn = 0;
  while (1) {
    char user_input[6];
    int found_end_of_line = 0;
    int index = 0;
    int board_index[2];
    int move_is_valid = 1;

    char player_symbol = player_turn == 0 ? 'X' : 'O';

    clear_terminal();
    draw();

    printf("Input move (a1 d1): \n");
    fgets(user_input, sizeof(user_input), stdin);

    move_is_valid = move_is_valid * user_input[2] == ' ';

    board_index[0] = get_index_for_coordinate_str(&user_input[0]);
    move_is_valid = board_index[0] >= 0;
    printf("First index: %d\n", board_index[0]);

    board_index[1] = get_index_for_coordinate_str(&user_input[3]);
    move_is_valid = move_is_valid * board_index[1] >= 0;
    printf("Second index: %d\n", board_index[1]);

    if (move_is_valid) {
      position_symbols[board_index[0]] = ' ';
      position_symbols[board_index[1]] = player_symbol;
    }

    /* printf("Compare: %d\n", str_compare(&user_input[2], "sting", 2)); */
    for (index = 0; index < sizeof(user_input); index += 1) {
      char current_char = user_input[index];

      if (current_char == '\n') {
        break;
      }
      if (current_char == '\0') {
        while (!found_end_of_line)
          found_end_of_line = getchar() == '\n';
        break;
      }
      printf("%c", current_char);
    }
    printf("\n");
    player_turn = (player_turn + 1) % 2;
  }

  return 0;
}
