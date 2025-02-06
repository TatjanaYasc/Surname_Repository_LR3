#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

//глобальные переменные - стороны прямоугольника
int side1, side2;

//функция ввода данных
function<void()> EnterNumber(int& varLink, string label) {
	//разрабатывается Сидоровым С. - ветка branch_fun_1    
    return [&varLink, label]() {
        std::cout << label << " = ";
        std::cin >> varLink;
    };  
}
void CalcArea()
{
	//разрабатывается Петровым П. - ветка branch_fun_2
    cout << "area = " << side1 * side2 << endl;
}

void CalcPerim()
{
	//разрабатывается Васильевым В. - ветка branch_fun_3
    cout << "perimatr " << side1 + side2 << endl;
}

//структра меню
struct MenuItem {
       string title;
       function<void()> action;
    };

int main() {
    map<int, MenuItem> menu = {
        {1, {"Ввод 1-й стороны прямоугольника", EnterNumber(side1, "Input side1")}},
        {2, {"Ввод 2-й стороны прямоугольника", EnterNumber(side2, "Input side2")}},
        {3, {"Calculate of Area", CalcArea}},
        {4, {"Calculate of Perimetr", CalcPerim}},
    };

    int choice = 0;

    while (true) {
        cout << "Меню:" <<endl;
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << std::endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        if (choice == 0) {
            cout << "© 2025 FirstName LastName" << endl;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некорректный ввод.";
        }
        cout << endl ;
    }
    return 0;
}