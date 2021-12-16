#ifndef UNSOCIABLE_GARDENERS_GARDENCELL_H
#define UNSOCIABLE_GARDENERS_GARDENCELL_H

#include <mutex>

// gardenCell - сущность, представляющая собой клетку, из множества которых состоит сад.
// isReady - переменная отображаеющая, работал ли на этой клетке садовник.
class gardenCell {
private:
    bool isReady;
    std::mutex* mutex_of_garden_cell;

public:
    gardenCell() {
        isReady = false;
        mutex_of_garden_cell = new std::mutex();
    }

    // Метод, обрабатывающий событие, что gardenCell обработал садовник.
    bool workByGardener();
};


#endif //UNSOCIABLE_GARDENERS_GARDENCELL_H
