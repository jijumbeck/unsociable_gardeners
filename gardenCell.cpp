#include "gardenCell.h"

// Метод, обрабатывающий событие, что gardenCell обработал садовник.
bool gardenCell::workByGardener() {
    this->mutex_of_garden_cell->lock();

    if(this->isReady) {
        this->mutex_of_garden_cell->unlock();
        return false;
    }

    this->isReady = true;
    this->mutex_of_garden_cell->unlock();

    return true;
}