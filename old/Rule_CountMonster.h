
#ifndef PERSON_H_RULE_COUNTMONSTER_H
#define PERSON_H_RULE_COUNTMONSTER_H

template <typename LVL>
class Rule_CountMonster{
public:
    Rule_CountMonster(LVL l){
        level = l;
    }
    int CountChicken(int E){
        int Count;
        if (level==1 || level==2 || level==3) {
            if (level == 1) {
                Count = E / 4;
            }
            if (level == 2) {
                Count = E / 3;
            }
            if (level == 3) {
                Count = E / 2;
            }
        }
        else{
            Count = E;
        }
        return Count;
    }
    int CountWitch(int E){
        int Count;
         if (level==1 || level==2 || level==3) {
            if (level == 1) {
                Count = E / 6;
            }
            if (level == 2) {
                Count = E / 4;
            }
            if (level == 3) {
                Count = E;
            }
        }
        else{
            Count = 0;
        }
        return Count;
    }
    int CountHunter(int E){
        int Count;
        if (level==1 || level==2 || level==3){
            if (level == 1){
                Count = E/7;
            }
            if (level == 2){
                Count = E/5;
            }
            if (level == 3){
                Count = E;
            }
        }
        else{
            Count = 0;
        }
        return Count;
    }
private:
    LVL level;
};


#endif //PERSON_H_RULE_COUNTMONSTER_H
