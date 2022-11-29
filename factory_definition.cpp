#include <iostream>
#include <string>
using namespace std;

#define OBJ_1 OBJECT_MODEL1 
#define OBJ_2 OBJECT_MODEL2
#define OBJ_OPR  OBJECT_OPERATION
#define CRT CREATOR_FACTORY
#define CRT1 OBJ1_CREATOR
#define CRT2 OBJ2_CREATOR

class OBJECT_OPERATION {
    public:
    virtual ~OBJECT_OPERATION(){}
    virtual void operation() {
        cout<<"operation called from interface";
    }
};

//every model has a specific OBJECT_MODEL class;

class OBJECT_MODEL1 : public OBJ_OPR {
    public:
    OBJECT_MODEL1() {
        cout<<"an object model 1 is created\n";
    }
    void operation() {
        cout<<"operation called from type model 1 (example, Sach)\n";
    }
};

class OBJECT_MODEL2 : public OBJ_OPR {
    public: 
    OBJECT_MODEL2() {
        cout<<"an object model 2 is created\n";
    }
    void operation() {
        cout<<"operation called from type model 2 (example, User)\n";
    }
};

class CREATOR_FACTORY {
    public:
    virtual OBJ_OPR* creator() = 0;

    void logical_operation() {
        //call creator to create an object
        OBJ_OPR* handler = this->creator();
        //use the handler* as any object 1 or 2
        handler->operation();
        //now i wonder if we can modify to keep track with the handler?
        //or, these factory methods will instead, call interfaces
        //like, we need to return the handler, or if not wanna keep track, just delete it
        delete handler;
    }
};

//every model has its own creator

class OBJ1_CREATOR : public CREATOR_FACTORY {
    public: 
    OBJ_OPR* creator() {
        return new OBJ_1;
    }
};

class OBJ2_CREATOR : public CREATOR_FACTORY {
    public: 
    OBJ_OPR* creator() {
        return new OBJ_2;
    }
};

void subsequent_code(CRT* target) {
    target->logical_operation();
    //this logical_operation() may return a handler of OBJECT (which don't care about its model)
} 

int main () {
    //start with OBJECT MODEL 1
    CRT* current_creator_ptr = new CRT1();
    subsequent_code(current_creator_ptr);
    CRT* another_creator_ptr = new CRT2();
    subsequent_code(another_creator_ptr);

    cout<<"end the program";
    delete current_creator_ptr;
    delete another_creator_ptr;
    return 0;
}