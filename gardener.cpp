#include <iostream>
#include "gardener.h"

// Метод, устанавливающий садовника в конкретную точку сада.
void gardener::setGardenerPosition(int x, int y) {
    this->x_position_ = x;
    this->y_position_ = y;
}

// Метод, описывающий поведение первого садовника (который стоит в левом верхнем углу).
void gardener::processAsFirstGardener(gardener* current_gardener, int break_of_gardener) {
    current_gardener->setGardenerPosition(0, 0);

    while (!current_gardener->garden_->isGardenReady()) {
        if (current_gardener->garden_->workByGardener(current_gardener->x_position_, current_gardener->y_position_)) {
            std::cout << "The first gardener worked on (" << current_gardener->x_position_ <<
            ", " << current_gardener->y_position_ << ") position in the garden." << std::endl;
        }

        ++(current_gardener->x_position_);
        if(current_gardener->x_position_ >= current_gardener->garden_->length) {
            current_gardener->x_position_ = 0;
            ++(current_gardener->y_position_);

            if(current_gardener->y_position_ >= current_gardener->garden_->width) {
                current_gardener->setGardenerPosition(0, 0);
            }
        }

        // Садовник отдыхает.
        for (int i = 0; i < break_of_gardener; ++i) { }
    }
}

// Метод, описывающий поведение второго садовника (который стоит в правом нижнем углу).
void gardener::processAsSecondGardener(gardener* current_gardener, int break_of_gardener) {
    current_gardener->setGardenerPosition(current_gardener->garden_->length - 1,
                                          current_gardener->garden_->width - 1);

    while (!current_gardener->garden_->isGardenReady()) {
        if (current_gardener->garden_->workByGardener(current_gardener->x_position_, current_gardener->y_position_)) {
            std::cout << "The second gardener worked on (" << current_gardener->x_position_ <<
                      ", " << current_gardener->y_position_ << ") position in the garden." << std::endl;
        }

        --(current_gardener->x_position_);
        if(current_gardener->x_position_ < 0) {
            current_gardener->x_position_ = current_gardener->garden_->length - 1;
            --(current_gardener->y_position_);

            if(current_gardener->y_position_ < 0) {
                current_gardener->setGardenerPosition(current_gardener->garden_->length - 1,
                                                      current_gardener->garden_->width - 1);
            }
        }

        // Садовник отдыхает.
        for (int i = 0; i < break_of_gardener; ++i) { }
    }
}