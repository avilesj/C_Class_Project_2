#include "product.h"
#include <string.h>

int validateUpperPercentage(float percentage)
{
  if(percentage <=15)
  {
    return 0;
  }  
  else
  {
    return -1;
  }
}

int validateLowerPercentage(float percentage)
{
  if(percentage <=10)
  {
    return 0;
  }  
  else
  {
    return -1;
  }
}

int validatePrice(float basePrice, float sellingPrice)
{
  if(basePrice < sellingPrice)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

int searchProduct(int id)
{
  for(int i =0; i < MAX; i++)
  {
    if(stock[i].id == id)
    {
      return i;
    }
  }

  return -1; 
}

int addProduct(int id, float basePrice, float sellingPrice, float upperPercentage, float lowerPercentage, char name[MAX], char measureUnit[5], char category[MAX],
    char creationDate[10])
{
  if(searchProduct(id) != -1)
  {
    return -1;
  }

  if(validateUpperPercentage(upperPercentage) != 0)
  {
    return -2;
  }
  if(validateLowerPercentage(lowerPercentage) !=0)
  {
    return -3;
  }

  if(validatePrice(basePrice, sellingPrice) !=0)
  {
    return -4;
  }
  else
  {
    stock[current].id = id;
    memcpy(stock[current].name, name, 50);
    memcpy(stock[current].measureUnit, measureUnit, 50);
    memcpy(stock[current].category, category, 50);
    memcpy(stock[current].creationDate, creationDate, 50);
    stock[current].basePrice = basePrice;
    stock[current].sellingPrice = sellingPrice;
    stock[current].upperPercentage = upperPercentage;
    stock[current].lowerPercentage = lowerPercentage;
    current++;
    return 0;
  }
}
