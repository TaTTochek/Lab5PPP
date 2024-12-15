#include "Functions.h"

int getRandomNumber() {
    int randomValue = rand() % 100;
    return (randomValue < 90) ? 2 : 4;
}