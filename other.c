#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float netto_menu_arak[5] = {40.5f, 30.15f, 55.3f, 24.65f, 29.43f};

int dailyDiscountMenu()
{
  return (rand() % (5 - 1)) + 1;
}

float modifiedPrice(int index, float q)
{
  return (float)(netto_menu_arak[index] * q);
}

int generateReview()
{
  return (rand() % (10 - 1)) + 1;
}

void printMenuData(int index)
{
  printf("Menu #%d\n", index);
  printf("Net price: %.2f\n", netto_menu_arak[index - 1]);
  printf("Gross price: %.2f\n", netto_menu_arak[index - 1] * 1.27);
  printf("Customer review: %d\n", generateReview());
}

void printDailyData(float data[], int length)
{
  float avgRating = data[2];
  printf("Number of daily orders: %d\n", length);
  printf("Daily net income: %.2f\n", data[0]);
  printf("Daily gross income: %.2f\n", data[1]);
  printf("Daily average review: %.2f\n", avgRating);
  printf("%s\n", avgRating < 3.5 ? "The restaurant did poorly today." : avgRating < 6.5 ? "The restaurant did fine today."
                                                                                        : "The restaurant did great today.");
}

void dailyIncome(int dailyOrders[], int length)
{
  int discountedOrderNumber = dailyDiscountMenu() - 1;
  modifiedPrice(discountedOrderNumber, 0.8);
  printf("Napi kedvezményes menü: %d\n", discountedOrderNumber + 1);

  float data[3];
  for (int i = 0; i < length; ++i)
  {
    if (dailyOrders[i] > 5)
    {
      printf("%s\n", "Hibás rendelés! Nem létezik ilyen sorszámú menü!");
      continue;
    }
    printMenuData(dailyOrders[i]);
    data[0] += netto_menu_arak[dailyOrders[i] - 1];
    data[1] += modifiedPrice(dailyOrders[i] - 1, 1.27);
    data[2] += generateReview();
  }
  data[2] /= length;
  printDailyData(data, length);
}

int main()
{
  srand(time(NULL));
  int rendelesek[] = {1, 3, 4, 2, 2, 1, 5, 4, 4, 3, 5};
  size_t rendelesek_length = sizeof(rendelesek) / sizeof(int);

  dailyIncome(rendelesek, rendelesek_length);

  return 0;
}
