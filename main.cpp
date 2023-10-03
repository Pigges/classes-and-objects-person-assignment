#include "Person.hpp"
#include <iostream>

using namespace std;


void printTestResults(vector<bool> const &results) {
    for (int i = 0; i < results.size(); ++i) {
        cout << "Test " << i + 1 << ": ";
        cout << (results[i] ? "PASSED" : "FAILED") << endl;
    }
}

int main() {
    Person marie("Marie", 22, 231546, "female", "0709876543", "Gata 3", "Frisör", true, 2);
    Person johan("Johan", 19, 213231, "male", "0701234567", "Gata 1", "Gruvarbetare", false, 0);
    Person mona("Mona", 64, 2304, "female", "0700483927", "Gata 4", "Astronaut", true, 2);
    Person bjorn("Bjorn", 32, 312940, "other", "0704492859", "Gata 12", "Försäljare", true, 3);


    johan.addFriend(marie);
    johan.addFriend(mona);
    johan.birthday();


    vector<bool> personTest;
    personTest.push_back(johan.getMarried() == false);
    personTest.push_back(johan.getGender() == "male");
    personTest.push_back(johan.getAge() == 20);
    personTest.push_back(johan.getFriends()[johan.getFriends().size() -1] == &mona);

    cout << "Tests for Person" << endl;
    printTestResults(personTest);

    cout << endl;

    johan.interact(marie);

    johan.introduce();

}