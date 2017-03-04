#ifndef PRODUCT_H_
#define PRODUCT_H_
#define MAX 50
struct product
{
      int id;
      char name[50];
      char measureUnit[5];
      char category[50];
      char creationDate[10];
      float basePrice;
      float sellingPrice;
      float upperPercentage;
      float lowerPercentage;
}stock[MAX];

static const struct product EmptyProduct;

int current = 0;

int addProduct(int id, float basePrice, float sellingPrice, float upperPercentage, float lowerPercentage, char name[MAX], char measureUnit[5], char category[MAX],
    char creationDate[10]);
int searchProduct(int index);
int validateUpperPercentage(float percentage);
int validateLowerPercentage(float percentage);
int validatePrice(float basePrice, float sellingPrice);
#endif
