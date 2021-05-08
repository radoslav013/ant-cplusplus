#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string lastname;
    int age;
    double height;
    double weight;
};

int main()
{
    struct Person pesho;

    pesho.age = 20;
    pesho.height = 1.80;
    pesho.weight = 70;
    pesho.name = "Pesho";
    pesho.lastname = "Ivanov";

    struct Person people[2];
    people[0] = pesho;

    cout << people[0].name << endl;

    struct Person gosho = {"Georgi"};
    cout << gosho.lastname << endl;

    return 0;
}
