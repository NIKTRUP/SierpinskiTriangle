#include <iostream>
#include <fstream>
#include <cmath>
#include "ТреугольникСерпинского.h"
#include <vector>
#include <GLFW/glfw3.h>
using namespace std;
int main()
{
    system("chcp 1251>nul");
    int n; bool InputСheck = false;
    vector<double> v_points_x{ 0.0 };
    vector<double> v_points_y{ 0.0 };
    double step[2] = {0.0 , 0.0};
    cout << "Введите количество точек Треугольника Серпинского: ";
    InputCheck(InputСheck, n);
    unsigned int start_time = clock(); 
    CalculateSierpinskiTriangle(n, v_points_x, step, v_points_y);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << search_time / 1000.00 << " в секундах " << endl;// вывод в секундах 
    WriteFile(v_points_x, v_points_y);
    GLFWwindow* window;
    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(800, 800, "SierpinskiTriangle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        Draw(v_points_x, v_points_y);
        glfwSwapBuffers(window);
        glfwPollEvents();
        glClearColor(0.2, 0.2, 0.2, 1.0);
    }
    glfwTerminate();
}
void WriteFile(std::vector<double>& v_points_x, std::vector<double>& v_points_y)
{
    ofstream out("PointOutput.txt");
    if (out.is_open())
    {
        for (int i = 0; i < v_points_x.size(); i++) {
            out << v_points_x[i] << " " << v_points_y[i] << "\n";
        }
        cout << "Запись в файл произошла";
    }
}
void Draw(std::vector<double>& v_points_x, std::vector<double>& v_points_y)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < v_points_x.size(); i++)
    {
        glVertex2d(v_points_x[i]-0.5, 0.55 * v_points_y[i]-0.5);
    }
    glEnd();
}
void CalculateSierpinskiTriangle(int n, std::vector<double>& v_points_x, double  step[2], std::vector<double>& v_points_y)
{
    for (int i = 0, r_T = 0, r_point = 0; i < n; i++) {
        r_T = rand() % 3 + 1;
        r_point = rand() % v_points_x.size();
        switch (r_T)
        {
        case 1: step[0] = 0.0;
            step[1] = 0.0;
            break;
        case 2: step[0] = 0.5;
            step[1] = 0.0;
            break;
        case 3: step[0] = 0.25;
            step[1] = 0.86602540378;
            break;
        default: cout << "Что-то пошло не так";
            break;
        }
        v_points_x.emplace_back(0.5 * v_points_x[r_point] + step[0]);
        v_points_y.emplace_back(0.5 * v_points_y[r_point] + step[1]);
    }
}
void InputCheck(bool& InputСheck, int& n)
{
    while (!InputСheck) {

        cin >> n;
        if (cin.fail()) // если предыдущее извлечение было неудачным,
        {
            cout << "Ошибка ввода! Вы ввели некорректный символ, попробуйте снова: " << endl;
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else if (n >= 0) { InputСheck = true; }
        else { cout << "Ошибка ввода! Порядок фрактала не может быть отрицательным, попробуйте снова: " << endl; }
    }
    InputСheck = false;
}


