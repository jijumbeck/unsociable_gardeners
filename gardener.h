#ifndef UNSOCIABLE_GARDENERS_GARDENER_H
#define UNSOCIABLE_GARDENERS_GARDENER_H

#include "garden.h"
#include <thread>

// gardener - сущность садовника.
// (x_position, y_position_) - позиция садовника в саду (координата в матрице garden_surface).
// в самом начале садовник нигде не стоит, поэтому его координаты == (-1, -1)
// garden - сад, над которым работает садовник.
class gardener {
private:
    garden* garden_;
    int x_position_ = -1;
    int y_position_ = -1;

    // Метод, устанавливающий садовника в конкретную точку сада.
    void setGardenerPosition(int x, int y);

public:
    explicit gardener(garden* garden) {
        this->garden_ = garden;
    }

    // Метод, описывающий поведение первого садовника (который стоит в левом верхнем углу).
    static void processAsFirstGardener(gardener* current_gardener, int break_of_gardener);

    // Метод, описывающий поведение второго садовника (который стоит в правом нижнем углу).
    static void processAsSecondGardener(gardener* current_gardener, int break_of_gardener);
};


#endif //UNSOCIABLE_GARDENERS_GARDENER_H
