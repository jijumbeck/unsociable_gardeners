#ifndef UNSOCIABLE_GARDENERS_GARDEN_H
#define UNSOCIABLE_GARDENERS_GARDEN_H

#include <cstdlib>
#include "gardenCell.h"

// garden - сущность, представляющая собой сад.
// по сути он состоит из матрицы gardenCell'ов (garden_surface).
// width - ширина сада (матрицы).
// length - длина сада (матрицы).
// number_of_untreated_garden_cells - количество клеток, до которых еще не дошли садовники.
class garden {
private:
    gardenCell*** garden_surface;

public:
    int width;
    int length;
    int number_of_untreated_garden_cells;

    garden(int length, int width) {
        this->length = length;
        this->width = width;
        this->number_of_untreated_garden_cells = length * width;

        garden_surface = new gardenCell**[length];

        for (int i = 0; i < length; ++i) {
            garden_surface[i] = new gardenCell*[width];
            for (int j = 0; j < width; ++j) {
                garden_surface[i][j] = new gardenCell();
            }
        }
    }

    // Метод-флаг, показывающий законченая ли работа над садом.
    bool isGardenReady() const;

    // Метод, обрабатывающий работу садовников над садом.
    bool workByGardener(int x, int y);

    ~garden() {
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                delete garden_surface[i][j];
            }
            delete[] garden_surface[i];
        }
        delete[] garden_surface;
    }
};


#endif //UNSOCIABLE_GARDENERS_GARDEN_H
