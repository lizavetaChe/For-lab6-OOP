#ifndef UNTITLED1_FIELD_H
#define UNTITLED1_FIELD_H

#include <ctime>
#include "ChickenFactory.h"
#include "WitchFactory.h"
#include "HunterFactory.h"
#include "DragonFactory.h"
#include "medicineFactory.h"
#include "armorFactory.h"
#include "gunFactory.h"
#include "LogProxy.h"
#include "Observable.h"

#include "Cell.h"
#include "Rule_Finish.h"

typedef struct Size{
    int height;
    int width;
}Size;

class Field: public Observable{
public:
    explicit Field(int W=10, int H=10);
    Field(const Field &other);
    Field &operator=(const Field &other);
    Field(Field &&other) noexcept;
    Field &operator=(Field &&other) noexcept;
    Size getSize() const;
    Cell **getMap();
    int getCountB();
    Cell* FirstCell();
    Cell* LastCell();
    ~Field();
    int CheckStep(Cell& dot);
    int Check(Cell& dot);
    void FieldGen(int C, int W, int H);
    void change();
    Cell* StepUser(Cell* Place, int dx, int dy);
    void find(Cell& dom);
    int battle(Cell& dom);
    int getCountE();
    void setLast(Cell* it);
    void setFirst(Cell* it);
private:
    Size size;
    Cell** Map;
    Cell* Last;
    Cell* First;
    int CountB = 0;
    int CountE = 0;
    int CountChick = 0;
    int CountHunter = 0;
    int CountWitch = 0;
    std::string logString;
};

#endif //UNTITLED1_FIELD_H
