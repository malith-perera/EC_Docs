#include "fruit.h"
#include "fruit_version.h"

typedef struct Fruit {
    char *name;
    char *color;
    int price;
} Fruit;

EC(Fruit)

int
main(int argc, char *argv[])
{
    Fruit *apple = Fruit_Var();
    apple = {"apple", "red", 5};

    Fruit *mango = Fruit_Var();
    mango->name = "mango";
    mango->color = "Green";
    mango->price = 6;

    Fruit *orange = Fruit_Var();
    orange->name = "orange";
    orange->color = "Yellow";
    orange->price = 4;

    FruitList *fruit_list = Fruit_List();

    Fruit_Append(fruit_list, apple);
    Fruit_Append(fruit_list, mango);
    Fruit_Append(fruit_list, orange);

    Fruit *fruit;
    for_list(fruit_list) {
    }

    return 0;
}
