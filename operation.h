#ifndef OPERATION_H
#define OPERATION_H

#include <string>
using namespace std;

class operation_Handler {
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

class library_Handler : public operation_Handler {
    public:
    library_Handler();
    bool inputNew();
    bool updateExisted();
    bool removeExisted();
    bool readFromFile();
    bool writeToFile();
};

class userbase_Handler : public operation_Handler {
    public:
    userbase_Handler();
    bool inputNew();
    bool updateExisted();
    bool removeExisted();
    bool readFromFile();
    bool writeToFile();
};

class borrowing_Handler : public operation_Handler {
    public: 
    borrowing_Handler();
    bool inputNew();
    bool updateExisted();
    bool removeExisted();
    bool readFromFile();
    bool writeToFile();
};

class operation_Handler_Creator {
    public:
    virtual operation_Handler* Creator() = 0;

    int call_to_Handler_Creator() {
        operation_Handler* current_handler = this->Creator();
    }
};

class library_Handler_Creator : public operation_Handler_Creator {
    operation_Handler* Creator();
};

class userbase_Handler_Creator : public operation_Handler_Creator {
    operation_Handler* Creator();
};

class borrowing_Handler_Creator : public operation_Handler_Creator {
    operation_Handler* Creator();
};
#endif