#ifndef OPERATION_H
#define OPERATION_H

#include <string>
using namespace std;

class OperationHandler {
    protected:
    string file_destination;

    public:
    virtual bool inputNew() = 0;
    virtual bool updateExisted() = 0;
    virtual bool removeExisted() = 0;
    virtual bool readFromFile() = 0;
    virtual bool writeToFile() = 0;
    bool setDestination();
};

class LibraryHandler : public OperationHandler {
    public:
    LibraryHandler();
    bool inputNew();
    bool updateExisted();
    bool removeExisted();
    bool readFromFile();
    bool writeToFile();
} LH;

class UserbaseHandler : public OperationHandler {
    public:
    UserbaseHandler();
    bool inputNew();
    bool updateExisted();
    bool removeExisted();
    bool readFromFile();
    bool writeToFile();
} UH;

class BorrowingHandler : public OperationHandler {
    public: 
    BorrowingHandler();
    bool inputNew();
    bool updateExisted();
    bool removeExisted();
    bool readFromFile();
    bool writeToFile();
} BH;

OperationHandler* switcher(const int&);

#endif