// krestikinoliki_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
// функция корректости ввода данных
bool correct(std::string sumOfRows)
{
    int x = 0; // Флажок крестиков
    int o = 0; // Флажок ноликов
    if (sumOfRows.length() != 9) return false;
    for (int i = 0; i < sumOfRows.length(); i++)
    {
        if (sumOfRows[i] != 'X' && sumOfRows[i] != 'O' && sumOfRows[i] != '.') return false; //возможно косячное условие. (ПРОВЕРКА НА ВВОД X O . )
        if (sumOfRows[i] == 'X') x++;
        if (sumOfRows[i] == 'O') o++;
    }

    if (x - o < 0) return false;

    return true;
}

// Проверка по горизонтали
std::string horizontal(std::string sumOfRows)
{
    int flag = 0; // флажок корректности
    std::string result = "";

    if (sumOfRows[0] == sumOfRows[1] && sumOfRows[0] == sumOfRows[2] && sumOfRows[0] == 'X') {
        result += 'X';
        flag++;
    }
    if (sumOfRows[0] == sumOfRows[1] && sumOfRows[0] == sumOfRows[2] && sumOfRows[0] == 'O') {
        result += 'O';
        flag++;
    }

    if (sumOfRows[3] == sumOfRows[4] && sumOfRows[3] == sumOfRows[5] && sumOfRows[3] == 'X') {
        result += 'X';
        flag++;
    }
    if (sumOfRows[3] == sumOfRows[4] && sumOfRows[3] == sumOfRows[5] && sumOfRows[3] == 'O') {
        result += 'O';
        flag++;
    }

    if (sumOfRows[6] == sumOfRows[7] && sumOfRows[6] == sumOfRows[8] && sumOfRows[6] == 'X') {
        result += 'X';
        flag++;
    }
    if (sumOfRows[6] == sumOfRows[7] && sumOfRows[6] == sumOfRows[8] && sumOfRows[6] == 'O') {
        result += 'O';
        flag++;
    }

    if (flag > 0) return result;
    return "";
}

// ПРОВЕРКА ПО ВЕРТИКАЛИ
std::string vertical(std::string sumOfRows)
{
    int flag = 0; // флажок корректности
    std::string result = "";

    if (sumOfRows[0] == sumOfRows[3] && sumOfRows[0] == sumOfRows[6] && sumOfRows[0] == 'X') {
        result += 'X';
        flag++;
    }
    if (sumOfRows[0] == sumOfRows[3] && sumOfRows[0] == sumOfRows[6] && sumOfRows[0] == 'O') {
        result += 'O';
        flag++;
    }

    if (sumOfRows[1] == sumOfRows[4] && sumOfRows[1] == sumOfRows[7] && sumOfRows[1] == 'X') {
        result += 'X';
        flag++;
    }
    if (sumOfRows[1] == sumOfRows[4] && sumOfRows[1] == sumOfRows[7] && sumOfRows[1] == 'O') {
        result += 'O';
        flag++;
    }

    if (sumOfRows[2] == sumOfRows[5] && sumOfRows[2] == sumOfRows[8] && sumOfRows[2] == 'X') {
        result += 'X';
        flag++;
    }
    if (sumOfRows[2] == sumOfRows[5] && sumOfRows[2] == sumOfRows[8] && sumOfRows[2] == 'O') {
        result += 'O';
        flag++;
    }

    if (flag > 0) return result;
    return "";
}

// ПРОВЕРКА ПО ГЛАВНОЙ ДИАГОНАЛИ
std::string first_diagonal(std::string sumOfRows)
{
    int flag = 0;
    std::string result = "";

    if (sumOfRows[0] == sumOfRows[4] && sumOfRows[0] == sumOfRows[8] && sumOfRows[0] == 'X') {
        result += 'X';
        flag++;
    }
    if (sumOfRows[0] == sumOfRows[4] && sumOfRows[0] == sumOfRows[8] && sumOfRows[0] == 'O') {
        result += 'O';
        flag++;
    }

    if (flag > 0) return result;
    return "";
}

// ПРОВЕРКА ПО ВТОРОСТЕПЕННОЙ ДИАГОНАЛИ
std::string second_diagonal(std::string sumOfRows)
{
    int flag = 0;
    std::string result = "";

    if (sumOfRows[2] == sumOfRows[4] && sumOfRows[2] == sumOfRows[6] && sumOfRows[2] == 'X') {
        result += 'X';
        flag++;
    }
    if (sumOfRows[2] == sumOfRows[4] && sumOfRows[2] == sumOfRows[6] && sumOfRows[2] == 'O') {
        result += 'O';
        flag++;
    }

    if (flag > 0) return result;
    return "";
}

std::string winner(std::string h, std::string v, std::string f, std::string s)
{
    std::string result = h + v + f + s;
    if (result == "X") return "Petya won";
    if (result == "O") return "Wanya won";
    if (result == "") return "Nobody";
    return "incorrect";
}


int main()
{

    std::cout << "Enter  the batch:\n";
    std::string str_1;
    std::cin >> str_1;
    std::string str_2;
    std::cin >> str_2;
    std::string str_3;
    std::cin >> str_3;
    std::string sumOfRows = str_1 + str_2 + str_3;

    std::string h = horizontal(sumOfRows);
    std::string v = vertical(sumOfRows);
    std::string f = first_diagonal(sumOfRows);
    std::string s = second_diagonal(sumOfRows);

    std::string win = winner(h, v, f, s);
    if (correct(sumOfRows))
    {
        if (win != "Incorrect")
        {
            std::cout << win;
        }
        else std::cout << "Incorrect";
    }
    else if (!correct(sumOfRows)) std::cout << "Incorrect";

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
