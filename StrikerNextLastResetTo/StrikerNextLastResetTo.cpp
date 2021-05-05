#include <iostream>

using namespace std;

int main()
{
    int track[] = { 10, 20, 30, 40 }, *striker;
    striker = track; // striker points to track[0]
    track[1] += 30; // track[1] = 50
    cout << "Striker>" << *striker << " ";
    *striker -= 10; // track[0] = 0
    striker+=2; // striker points to track[2]
    cout << "Next@" << *striker << " ";
    striker--; // striker points to track[1]
    cout << "Last@" << *striker << " ";
    cout << "Reset To" << track[0] << " ";

    // Outputs: Striker>10 Next@30 Last@50 Reset To0

    return 0;
}
