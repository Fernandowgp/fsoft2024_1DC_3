#include "headers/views/View.h"
#include "headers/controllers/Controller.h"
#include "headers/model/Store.h"
using namespace std;

int main() {
    Store store("compostore");

    Controller controller(store);
    controller.run();
    return 0;
}
