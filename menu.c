#include "menu.h"
#include <stdio.h>
#include "invtools.c"
#include "product.c"

int printProduct(int index)
{ printf("\n");
  printf("ID: %d\n", stock[index].id);
}
void m_searchProduct()
{

  int product_id;

  printf("Favor escriba el numero de ID del numero: ");
  scanf("%d", &product_id);

  if(searchProduct(product_id) >= 0)
  {
    printf("\nEXECUTE!");
    printProduct(product_id);
  }
  else
  {
    clearScreen();
    printf("Producto no encontrado\n\n");
    m_searchProduct();

  }


}
void m_addProduct()
{
  clearScreen();

  int id;
  float basePrice;
  float sellingPrice;
  float upperPercentage;
  float lowerPercentage;
  printf("CURRENT: %d", current);

  printf("Favor llenar lo requerido\n");

  printf("ID: ");
  scanf("%d", &id);
  printf("\nPrecio de adquisicion: ");
  scanf("%f", &basePrice);
  printf("\nPrecio de venta: ");
  scanf("%f", &sellingPrice);
  printf("\nPorcentaje superior: ");
  scanf("%f", &upperPercentage);
  printf("\nPorcentaje inferior: ");
  scanf("%f", &lowerPercentage);

  if(addProduct(id,basePrice, sellingPrice, upperPercentage, lowerPercentage) < 0)
  {
    printf("Hubo un error agregando el producto");
  }
  else
  {
        printf("Producto agregado exitosamente!");
  }
  menu();
}

void menu()
{
  int option;

  printf("Inventario MEDASOFT\n");
  printf("1.  Agregar producto\n");
  printf("2.  Buscar producto\n");
  scanf("%d", &option);

  switch(option)
  {
    case 1:
      m_addProduct();
    case 2:
      clearScreen();
      m_searchProduct();

    default:
      menu();
  }
}
