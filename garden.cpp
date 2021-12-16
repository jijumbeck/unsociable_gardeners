#include "garden.h"

// Метод-флаг, показывающий законченая ли работа над садом.
bool garden::isGardenReady() const {
    return number_of_untreated_garden_cells == 0;
}

// Метод, обрабатывающий работу садовников над садом.
bool garden::workByGardener(int x, int y) {
    if(this->garden_surface[x][y]->workByGardener()) {
        --(this->number_of_untreated_garden_cells);
        return true;
    }

    return false;
}