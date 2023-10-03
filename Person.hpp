#pragma once

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

class Person {
  public:
    /*
    * Constructor: Initialize a new Person object.
    */
    Person(string name, int age, int idNumber, string gender, string phoneNumber, string address, string profession, bool married, int numberOfChildren)
      : _name(name), _age(age), _idNumber(idNumber), _gender(gender), _phoneNumber(phoneNumber), _address(address), _profession(profession), _married(married), _numberOfChildren(numberOfChildren)
    {};

    /*
    * introduce()
    * The person gives a short introduction, with name and age.
    */
    void introduce() const
    {
      cout << "Hello! My name is " << _name << " and I am " << _age << " years old" << endl;
    };

    // Getters
    string getName() {
      return _name;
    }
  
    string getGender() { // Returns the gender of the person
      return _gender;
    }

    string getPhoneNumber() { // Returns the phone number of the person
      return _phoneNumber;
    }

    string getAddress() { // Returns the address of the person
      return _address;
    }

    string getProfession() { // Returns the profession of the person
      return _profession;
    }

    bool getMarried() { // Returns wether or not the person is married
      return _married;
    }

    int getNumberOfChildren() { // Returns number of children person has
      return _numberOfChildren;
    }

    int getIdNumber() { // Returns the persons id number
      return _idNumber;
    }

    int getAge() { // Returns the persons age
      return _age;
    }

    vector<Person *> getFriends() { // Returns _friends
      return _friends;
    }

    // Setters
    void setName(string newName) {
      _name = newName;
    }
  
    void setGender(string newGender) { // Changes the persons gender to given parameter
      _gender = newGender;
    }

    void setPhoneNumber(string newPhoneNumber) { // Changes the persons phone number to given parameter
      _phoneNumber = newPhoneNumber;
    }

    void setAddress(string newAddress) { // Changes the persons address to the given parameter
      _address = newAddress;
    }

    void setProfession(string newProfession) { // Changes the persons profession to the given parameter
      _profession = newProfession;
    }

    void setMarried(bool newMarried) { // Changes the status of the persons married to the given parameter
      _married = newMarried;
    }


    // Methods
    void birthday() { // It's the birthday for the person - they get one year older
      _age++;
    }

    void interact(Person &otherPerson) { // The person gives a greeting to the other person from the given parameter
      cout << _name << " says: Hello " << otherPerson._name << ", nice to meet you!" << endl;
    }

    void listFriends() {
      cout << _name << "'s friends are: ";

      for (int i = 0; i < _friends.size(); i++) { // Loop through every item in _friends
        cout << _friends[i]->getName(); // Print out the name
        if (i == _friends.size() -2) cout << " and "; // Separate last element with 'and'
        else if (i != _friends.size() -1) cout << ", "; // Separate every other elements
      }

      cout << "." << endl; // End by a period and new line
    }

    void addFriend(Person &newFriend) {
      cout << _name << " just added " << newFriend._name << " to their friends list!" << endl;
      _friends.push_back(&newFriend);
    }

    void removeFriend(Person &oldFriend) {
      for (int i = 0; i < _friends.size(); i++) { // Go through each friend in _friends
        if (&oldFriend == _friends[i]) { // Looking for &oldFriend index in _friends
          _friends.erase(_friends.begin() + i); // Removes the &oldFriend from _friends
          cout << _name << " just removed " << oldFriend._name << " from their friends list!" << endl;
          break;
        }
      }
      //_friends.erase(oldFriend);
    }

  private:
    string _name;
    int _age;
    int _idNumber;
    string _gender;
    string _phoneNumber;
    string _address;
    string _profession;
    bool _married;
    int _numberOfChildren;
    vector<Person *> _friends;
};