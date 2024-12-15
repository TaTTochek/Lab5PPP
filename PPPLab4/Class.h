#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ITariff {
protected:
    float cost;
    string TName;
public:
    ITariff(float cost, string TName);
    virtual ~ITariff();

    virtual float GetCost() const = 0;
    virtual string GetName();
};

class DiscontTariff : public ITariff {
private:
    float discont;
public:
    DiscontTariff(float cost, string TName, float discont);
    float GetCost() const override;
};

class ClassicTariff : public ITariff {
public:
    ClassicTariff(float cost, string TName);
    float GetCost() const override;
};

class Airport {
private:
    vector<ITariff*> tariffs;
public:
    ~Airport();
    void addTarif(ITariff* tarif);
    void ShowTariff();
    void GetMaxTariff();
};
