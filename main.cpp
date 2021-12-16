#include <iostream>
#include "garden.h"
#include "gardener.h"


int main(int argc, char *argv[]) {
    // Обнуление рандомайзера.
    srand(time(NULL));

    // Проверка на корректность ввода аргументов командной строки.
    if(argc != 5) {
        std::cout << "The arguments of command line are wrong format.";
        return 1;
    }

    // Проверка на корректность аргументов.

    int length = std::stoi(argv[1]);
    if(length <= 0) {
        std::cout << "The length's parameter is non-positive. It will be random" << std::endl;
        length = rand() % 10000 + 1;
    }

    int width = std::stoi(argv[2]);
    if(width <= 0) {
        std::cout << "The width's parameter is non-positive. It will be random" << std::endl;
        width = rand() % 10000 + 1;
    }

    int break_of_first_gardener = std::stoi(argv[2]);
    if(width <= 0) {
        std::cout << "The break of first gardener's parameter is non-positive. It will be random" << std::endl;
        break_of_first_gardener = rand() % 10000 + 1;
    }

    int break_of_second_gardener = std::stoi(argv[2]);
    if(width <= 0) {
        std::cout << "The break of second gardener's parameter is non-positive. It will be random" << std::endl;
        break_of_second_gardener = rand() % 10000 + 1;
    }

    // Конец проверки на корректность аргументов.

    auto* current_garden = new garden(length, width);

    auto* first_gardener = new gardener(current_garden);
    auto* second_gardener = new gardener(current_garden);

    std::thread process_of_first_gardener(gardener::processAsFirstGardener, first_gardener, break_of_first_gardener);
    std::thread process_of_second_gardener(gardener::processAsSecondGardener, second_gardener, break_of_second_gardener);

    process_of_first_gardener.join();
    process_of_second_gardener.join();

    std::cout << "The working of gardeners is over. The garden is ready." << std::endl;

    delete current_garden;
    delete first_gardener;
    delete second_gardener;

    return 0;
}
