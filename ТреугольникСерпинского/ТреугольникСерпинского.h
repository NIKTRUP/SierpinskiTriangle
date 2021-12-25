#pragma once
#include <vector>
void InputCheck(bool& Input—heck, int& n);

void CalculateSierpinskiTriangle(int n, std::vector<double>& v_points_x, double  step[2], std::vector<double>& v_points_y);

void Draw(std::vector<double>& v_points_x, std::vector<double>& v_points_y);

void WriteFile(std::vector<double>& v_points_x, std::vector<double>& v_points_y);

