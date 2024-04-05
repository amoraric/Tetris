#include "Controller.h"

using namespace std;
int main() {
    auto cc = std::make_shared<Controller>();
    cc->start();

    return 0;
}
