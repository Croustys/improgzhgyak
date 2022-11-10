#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float netto_menu_arak[5] = {40.5f, 30.15f, 55.3f, 24.65f, 29.43f};

int dailyDiscountMenu()
{
  return 1 + rand() / ((RAND_MAX + 1u) / 5);
}

float modifiedPrice(int index, float q)
{
  return (float)(netto_menu_arak[index] * q);
}

int generateReview()
{
  return 1 + rand() / ((RAND_MAX + 1u) / 10);
}

void printMenuData(int index)
{
  printf("Menu #%d\n", index);
  printf("Net price: %.2f\n", netto_menu_arak[index - 1]);
  printf("Gross price: %.2f\n", netto_menu_arak[index - 1] * 1.27);
  printf("Customer review: %d\n", generateReview());
}

void dailyIncome(int dailyOrders[], int length)
{
  int discountedOrderNumber = dailyDiscountMenu() - 1;
  modifiedPrice(discountedOrderNumber, 0.8);
  printf("Napi kedvezményes menü: %d\n", discountedOrderNumber + 1);

  float sum = 0;
  for (int i = 0; i < length; ++i)
  {
    if (dailyOrders[i] > 5)
    {
      printf("%s\n", "Hibás rendelés! Nem létezik ilyen sorszámú menü!");
      continue;
    }
    printMenuData(dailyOrders[i]);
    sum += modifiedPrice(dailyOrders[i] - 1, 1.27);
  }
  printf("Összesen: %2.f\n", sum);
}

void printDailyData(int orders[], int length)
{
  printf("Number of daily orders: %d\n", length);
  printf("Daily net income: %.2f\n", 0);
  printf("Daily gross income: %.2f\n", 0);
  printf("Daily average review: %.2f\n", 0);
  printf("%s\n", 0 < 3.5 ? "The restaurant did poorly today." : 0 < 6.5 ? "The restaurant did fine today."
                                                                        : "The restaurant did great today.");
}

int main()
{
  srand(time(NULL));
  int rendelesek[] = {4, 3, 3, 3, 2, 1, 5, 6, 3};
  size_t rendelesek_length = sizeof(rendelesek) / sizeof(int);

  dailyIncome(rendelesek, rendelesek_length);
  printDailyData(rendelesek, rendelesek_length);

  return 0;
}
