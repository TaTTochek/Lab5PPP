#pragma once
#include <string>
/*
Data:
1. UserNickname
2. Score
*/


class Data_ {
private:
    std::string nickname;
    int score;

public:

    Data_();
    Data_(std::string nickname_, int score_);
    ~Data_();

    std::string GetNick() const { return nickname; };
    int GetScore() const { return score; }

};

// Костыли >_<

public ref class ManagedData {
private:
    System::String^ nickname;
    int score;

public:
    ManagedData(std::string nickname_, int score_)
    {
        nickname = gcnew System::String(nickname_.c_str());
        score = score_;
    }

    property System::String^ Nickname {
        System::String^ get() { return nickname; }
    }

    property int Score {
        int get() { return score; }
    }
};
