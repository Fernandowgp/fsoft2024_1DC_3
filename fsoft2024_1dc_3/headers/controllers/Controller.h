//
// Created by Luís on 26/05/2024.
//

#ifndef FSOFT2024_1DC_3_CONTROLLER_H
#define FSOFT2024_1DC_3_CONTROLLER_H

#include "../views/View.h"
#include "../model/Store.h"

class Controller {
private:
    Store model;
    View view;

public:
    Controller(Store& store);
    void run();
};


#endif //FSOFT2024_1DC_3_CONTROLLER_H
