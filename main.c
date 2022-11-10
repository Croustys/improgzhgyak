#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROW 6
#define COL 7

int table[ROW][COL];

void init()
{
  for (int i = 0; i < ROW; ++i)
  {
    for (int j = 0; j < COL; ++j)
    {
      table[i][j] = 0;
    }
  }
}

void printTable()
{
  for (int i = 0; i < ROW; ++i)
  {
    for (int j = 0; j < COL; ++j)
    {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
}

bool submit(int player, int col)
{
  for (int i = ROW - 1; i >= 0; i--)
  {
    if (table[i][col] == 0)
    {
      table[i][col] = player;
      return true;
    }
  }

  return false;
}

int evaluate()
{
  bool playerWon = false;
  int playerNumber = 0;
  for (int i = 0; i < ROW && !playerWon; ++i)
  {
    for (int j = 0; j < COL - 2 && !playerWon; ++j)
    {
      if (table[i][j] != 0 && table[i][j] == table[i][j + 1] && table[i][j] == table[i][j + 2])
      {
        playerWon = true;
        playerNumber = table[i][j];
      }
    }
  }
  if (playerWon)
  {
    return playerNumber;
  }
  for (int i = 0; i < ROW - 2 && !playerWon; ++i)
  {
    for (int j = 0; j < COL && !playerWon; ++j)
    {
      if (table[i][j] != 0 && table[i][j] == table[i + 1][j] && table[i][j] == table[i + 2][j])
      {
        playerWon = true;
        playerNumber = table[i][j];
      }
    }
  }
  if (playerWon)
  {
    return playerNumber;
  }
  return 0;
}

void game(char *ch)
{
  const int charCodeToCol = 65;
  size_t i = 0;

  while (i < strlen(ch))
  {
    int player = i > 1 ? (i % 2) + 1 : i == 0 ? 1
                                              : 2;
    if (!submit(player, ch[i] - charCodeToCol))
    {
      printf("%s\n", "Nem legális lépés!");
      printTable();
    }
    int playerNumber = evaluate();
    if (playerNumber != 0)
    {
      printf("%d számú játékos nyert!\n", playerNumber);
      return;
    }
    i++;
  }
  if (evaluate() == 0)
    printf("Döntetlen!\n");
}

int main()
{
  init();
  char input[100];
  scanf("%s", input);
  game(input);

  return 0;
}