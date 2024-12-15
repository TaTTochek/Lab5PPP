#include "Data_.h"


// - Информационе
Data_::Data_() {
    nickname = "";
    score = 0;
}
Data_::Data_(std::string nickname_, int score_) {
    nickname = nickname_;
    score = score_;
}
Data_::~Data_() {}