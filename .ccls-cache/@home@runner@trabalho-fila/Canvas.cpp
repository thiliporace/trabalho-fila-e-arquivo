#include <iostream>
#include "Canvas.h"

void SetupCanvas(Canvas& canvas, char on, char off)
{
    canvas.on = on;
    canvas.off = off;
}

void ClearCanvas(Canvas& canvas)
{
    for (int row = 0; row < CANVAS_ROWS; ++row)
        for (int col = 0; col < CANVAS_COLS; ++col)
            canvas.data[row][col] = false;
}

void ToggleCanvas(Canvas& canvas, int row, int col)
{
    canvas.data[row][col] = !canvas.data[row][col];
}

void PrintCanvas(const Canvas& canvas)
{
    std::cout << "  ";
    for (int col = 0; col < CANVAS_COLS; ++col)
        std::cout << col;
    std::cout << '\n';

    for (int row = 0; row < CANVAS_ROWS; ++row)
    {
        std::cout << row << ' ';
        for (int col = 0; col < CANVAS_COLS; ++col)
            std::cout << (canvas.data[row][col] ? canvas.on : canvas.off);
        std::cout << ' ' << row << '\n';
    }

    std::cout << "  ";
    for (int col = 0; col < CANVAS_COLS; ++col)
        std::cout << col;
    std::cout << '\n';
}

// Essa função sobrecarrega (overload) o operador << que é usado em instruções
// como std::cout, std::ofstream e std::ostringstream.
// Observe que, diferente da PrintCanvas(), essa função não faz nenhuma
// referência a std::cout.
// O código dessa função é executado, por exemplo, se uma variável do tipo
// Canvas é passada para std::cout, sendo que o parâmetro std::ostream& os se
// torna std::cout, nesse caso.
std::ostream& operator<<(std::ostream& os, const Canvas& canvas)
{
    os << "  ";
    for (int col = 0; col < CANVAS_COLS; ++col)
        os << col;
    os << '\n';

    for (int row = 0; row < CANVAS_ROWS; ++row)
    {
        os << row << ' ';
        for (int col = 0; col < CANVAS_COLS; ++col)
            os << (canvas.data[row][col] ? canvas.on : canvas.off);
        os << ' ' << row << '\n';
    }

    os << "  ";
    for (int col = 0; col < CANVAS_COLS; ++col)
        os << col;
    os << '\n';

    return os;
}
