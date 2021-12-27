
#ifndef PERSON_H_NEW_EXCEPTION_H
#define PERSON_H_NEW_EXCEPTION_H
#include <string>

enum ErrType{ErrFile, No_game, ErrValue};

class New_Exception{
public:
    New_Exception(ErrType T):err(T){
        switch (err){
            case (ErrFile):
                message="!Error! - No access to old game, start a new game.\n";
                break;
            case (No_game):
                message="!Error! - Completed the game, start a new game.\n";
                break;
            case (ErrValue):
                message="!Error! - The file is damaged, start a new game.\n";
                break;
        }
    };
    std::string getMessage(){
        return message;
    }
private:
    std::string message;
    ErrType err;
};

#endif //PERSON_H_NEW_EXCEPTION_H
