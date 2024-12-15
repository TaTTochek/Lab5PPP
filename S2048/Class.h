#pragma once

class cell {
private:
    unsigned int value : 16; // Значение клетки

public:
    cell();
    void setValue(int valu);
    int getValue() const;
};

const unsigned int GridSize = 4; // Размер поля

class mainGame2048 {
private:
    cell** MainGrid;

    void initializedCell();
    int sumGrid() const;
    bool isGameEnd(cell** grid) const;
    void squash_array(cell col[GridSize], bool key);
    void new_number(cell**& grid);

public:
    mainGame2048();
    ~mainGame2048();

    void playGame2048();
    char playGame2048(char a);//
    //

    void displayGrid(cell**& Grid) const;
    int  displaycell(int x,int y);
    void horizontalMove(cell**& grid, bool key);
    void verticalMove(cell**& grid, bool key);
    int GetScore() const;
};