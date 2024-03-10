// oop_review.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

// Base class for contacts
class Contact {
protected:
    std::string name;
    std::string phoneNumber;

public:
    Contact(const std::string& name, const std::string& phoneNumber) 
        : name(name), phoneNumber(phoneNumber) {}

    virtual void display() const {
        std::cout << "Name: " << name << ", Phone: " << phoneNumber << std::endl;
    }
};

// Derived class for personal contacts
class PersonalContact : public Contact {
    std::string email;

public:
    PersonalContact(const std::string& name, const std::string& phoneNumber, const std::string& email)
        : Contact(name, phoneNumber), email(email) {}

    void display() const override {
        std::cout << "Personal Contact: ";
        Contact::display();
        std::cout << "Email: " << email << std::endl;
    }
};

// Derived class for business contacts
class BusinessContact : public Contact {
    std::string company;

public:
    BusinessContact(const std::string& name, const std::string& phoneNumber, const std::string& company)
        : Contact(name, phoneNumber), company(company) {}

    void display() const override {
        std::cout << "Business Contact: ";
        Contact::display();
        std::cout << "Company: " << company << std::endl;
    }
};

// Address book class
class AddressBook {
    std::vector<Contact*> contacts;

public:
    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    void displayAllContacts() const {
        std::cout << "Address Book Contents:" << std::endl;
        for (const auto& contact : contacts) {
            contact->display();
        }
    }

    ~AddressBook() {
        for (auto& contact : contacts) {
            delete contact;
        }
    }
};

int main() {
    AddressBook addressBook;

    // Adding some sample contacts
    addressBook.addContact(new PersonalContact("John Doe", "1234567890", "john@example.com"));
    addressBook.addContact(new BusinessContact("Jane Smith", "0987654321", "XYZ Corp"));

    // Display all contacts
    addressBook.displayAllContacts();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
