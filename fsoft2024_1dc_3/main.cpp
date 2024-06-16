#include <iostream>
#include "headers/views/View.h"
#include "headers/controllers/Controller.h"
#include "headers/model/Store.h"
#include "mock/MockData.h"

using namespace std;

int main() {
    CompoStore compoStore("CompoStore");

    MockData mock;
    mock.generateData(compoStore);

    Controller Controller(compoStore);
    Controller.run();
    cout << "Application has exited" << endl;
    return 0;
}
