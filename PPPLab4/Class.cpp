#include "Class.h"

ITariff::ITariff(float cost, string TName) : cost(cost), TName(TName) {
    cout << "the class has been CREATED" << endl;
}

ITariff::~ITariff() {
    cout << "the class has been DESTROYED" << endl;
}

string ITariff::GetName() {
    return TName;
}

DiscontTariff::DiscontTariff(float cost, string TName, float discont)
    : ITariff(cost, TName), discont(discont) {
}

float DiscontTariff::GetCost() const {
    return (cost - discont);
}

ClassicTariff::ClassicTariff(float cost, string TName)
    : ITariff(cost, TName) {
}

float ClassicTariff::GetCost() const {
    return cost;
}

Airport::~Airport() {
    for (ITariff* tarif : tariffs) delete tarif;
    cout << "Airport was deleted" << endl;
}

void Airport::addTarif(ITariff* tarif) {
    tariffs.push_back(tarif);
}

void Airport::ShowTariff() {
    for (const auto& tarif : tariffs) {
        cout << tarif->GetCost() << " " << tarif->GetName() << endl;
    }
}

void Airport::GetMaxTariff() {
    if (tariffs.empty()) {
        cout << "Нет тарифов" << endl;
        return;
    }
    ITariff* max_cost = tariffs[0];
    for (const auto& tarif : tariffs) {
        if (tarif->GetCost() > max_cost->GetCost()) max_cost = tarif;
    }
    cout << "Стоимость билета - " << max_cost->GetCost()
        << " ; Название - " << max_cost->GetName() << endl;
}
