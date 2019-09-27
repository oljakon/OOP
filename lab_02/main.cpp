#include <iostream>
#include <cstdlib>

#include "matrix.h"
#include "base_matrix.h"
#include "base_iterator.h"
#include "const_iterator.h"
#include "matrix_math.h"

using namespace std;

int main()
{
    try
    {
        cout << "Тестирование контсрукторов\n\n";
        
        Matrix<int> mtr1(4, 4);
        cout << mtr1;
    
        Matrix<int> mtr2(mtr1);
        cout << mtr2;
        
        cout << "Тестирование сложения\n\n";
        mtr2 += mtr1;
        cout << mtr2;
        
        cout << "Тестирование вычитания\n\n";
        mtr2 -= mtr1;
        cout << mtr2;
        
        Matrix<int> mtr3({{1, 2, 3},
                          {4, 5, 6}});
        
        cout << "Тестирование получения элемента по индексу\n\n";
        int value = mtr3.get_value_by_index(0, 0);
        std::cout << "Полученное значение:  " << value << std::endl;
        
        cout << "\nТестирование проверки на квадратную матрицу\n\n";
        bool issquare = mtr3.is_square();
        cout << mtr3 << (issquare ? "Квадратная" : "Не квадратная") << std::endl;
        
        cout << "\nТестирование транспонирования матрицы\n\n";
        Matrix <int> mtr6({{1, 1, 1, 1, 1},
            {2, 2, 2, 2, 2},
            {3, 3, 3, 3, 3},
            {4, 4, 4, 4, 4},
            {5, 5, 5, 5, 5}});
        mtr6.transposition();
        cout << mtr6;
        Matrix<int> mtr7 = mtr6.transposition();
        cout << mtr7;
        
        cout << "\nТестирование умножения матриц\n\n";
        Matrix <int> mtr4(4, 4);
        mtr1 = mtr1 * mtr4;
        cout << mtr4;
        Matrix <int> mtr5(2, 2);
        mtr2 = mtr4 * mtr5;
        cout << mtr2;
    }
    catch (base_exception &exception)
    {
        cout << exception.what();
    }

    return 0;
}
