#include <iostream>

class basic {
private:
    char id;
public:
    static char counter;

    basic() {
        id = counter++;
        std::cout << "basic " << id << " Default constructor\n";
    }

    basic(const basic &) {
        id = counter++;
        std::cout << "basic " << id << " Copy constructor\n";
    }

    ~basic() { std::cout << "basic " << id << " Destructor\n"; }
};

char basic::counter = 'A';

basic use_basic(basic c) {
    std::cout << "Entered use_basic\n";
    std::cout << "Instantiating a local basic using the cc and the basic passed as a param\n";
    basic local(c);
    std::cout << "Returning a basic that was created locally (returning it by VALUE so it works)\n";
    return local; // RETURN VALUE OPTIMIZATION! COPY ELISION ALERT!  WHAT DOES YOUR COMPILER DO?
}

int main() {
    std::cout << "Constructing basic a using default constructor\n";
    basic a;

    std::cout << "Creating basic b using copy constructor and basic A\n";
    basic b(a);

    std::cout << "Passing basic a by value to a function\n";
    basic d = use_basic(a);

    std::cout << "Creating an array of 5 basics\n";
    basic array[5];

}

