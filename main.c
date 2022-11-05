#include <stdio.h>
#include <stdbool.h>

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
  if (table[0][col] == 0)
  {
    printf("%s", "Nem legális lépés!");
    return false;
  }
  for (int i = 0; i < ROW; ++i)
  {
    if (table[i][col] != 0)
    {
      table[i - 1][col] = player;
    }
  }
  return true;
}

void evaluate()
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
    printf("%d számú játékos nyert!\n", playerNumber);
    return;
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
    printf("%d számú játékos nyert!\n", playerNumber);
  }
}

int main()
{
  init();
  evaluate();
  return 0;
}