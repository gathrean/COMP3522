//Name: Gathrean Dela Cruz
//Student# : A01167248

#include "SingletonFacade.hpp"

int main() {
    SingletonFacade& singletonFacade = SingletonFacade::get_instance();
    singletonFacade.run();
    return 0;
}