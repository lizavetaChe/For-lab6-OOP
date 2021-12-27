
#ifndef PERSON_H_RULE_FINISH_H
#define PERSON_H_RULE_FINISH_H

template <typename RES>
class Rule_Finish{
public:
    Rule_Finish(RES r){
        Res = r;
    }
    RES getRule_F(){
        return Res;
    }
    void SetRule_F(RES R){
        Res = R;
    }

private:
    RES Res;
};


#endif //PERSON_H_RULE_FINISH_H
