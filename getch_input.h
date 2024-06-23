#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <random>

void back(std::string& str)
{
	if (!str.empty()) {
		std::cout << '\b' << ' ' << '\b';
		str.pop_back();
	}
}

int event(int min, int max) {
	if (min > 0) return 1;
	else if (max < 0) return 2;
	return 0;
}

int event(double min, double max) {
	if (min > 0) return 1;
	else if (max < 0) return 2;
	return 0;
}

bool size_check(std::string number, int min, int max, int event) { //Если проверка успешна, то число достигло максимума/минимума
	switch (event)
	{
	case 1:
		if ((std::stoi(number) < 0) or (std::stoi(number) > max)) return true;
		break;
	case 2:
		if ((std::stoi(number) > 0) or (std::stoi(number) < min)) return true;
		break;
	case 0: 
		if ((std::stoi(number) > max) or (std::stoi(number) < min)) return true;
		break;
	default:
		break;
	}
	return false;
}

bool size_check(std::string number, double min, double max, int event) { //Если проверка успешна, то число достигло максимума/минимума
	switch (event)
	{
	case 1:
		if ((std::stod(number) < 0) or (std::stod(number) > max)) return true;
		break;
	case 2:
		if ((std::stod(number) > 0) or (std::stod(number) < min)) return true;
		break;
	case 0:
		if ((std::stod(number) > max) or (std::stod(number) < min)) return true;
		break;
	default:
		break;
	}
	return false;
}

int int_input(int min = INT_MIN / 10, int max = INT_MAX / 10)
{
	if (min > max) {
		std::cout << "\nERROR: min > max" << std::endl;
		abort();
	}
	if ((min < INT_MIN / 10) or (max > INT_MAX / 10)) {
		std::cout << "\nERROR: invalid min or max" << std::endl;
		abort();
	}
	int case_event = event(min, max);
	std::string future_number{};
	char get;
	while (true)
	{
		get = _getch();
		if (isdigit(get)) 
		{
			if (size_check(future_number + get, min, max, case_event))
			{
				continue;
			}
			future_number.push_back(get);
			std::cout << get;
		}
		if ((get == 45) and (future_number.length() == 0) and (min < 0))
		{
			future_number.push_back('-');
			std::cout << get;
		}
		if (get == 8) back(future_number);
		if (get == 27) return INT_MIN;
		if (get == 13) {
			if ((future_number.empty()) or (std::stoi(future_number) > max) or (std::stoi(future_number) < min)) continue;
			std::cout << std::endl;
			return std::stoi(future_number);
		}
	}
}

double double_input(double min = DBL_MIN / 10, double max = DBL_MAX / 10)
{
	if (min > max) {
		std::cout << "\nERROR: min > max" << std::endl;
		abort();
	}
	if ((min < INT_MIN / 10) or (max > INT_MAX / 10)) {
		std::cout << "\nERROR: invalid min or max" << std::endl;
		abort();
	}
	int case_event = event(min, max);
	std::string future_number{};
	char get;
	while (true)
	{
		get = _getch();
		if (isdigit(get))
		{
			if (size_check(future_number + get, min, max, case_event))
			{
				continue;
			}
			future_number.push_back(get);
			std::cout << get;
		}
		if ((get == 45) and (future_number.length() == 0) and (min < 0))
		{
			future_number.push_back('-');
			std::cout << get;
		}
		if ((get == '.') and (future_number.find(',') == std::string::npos) and (((future_number.length() >= 1) and
			(future_number[0] != '-')) or (future_number.length() >= 2))) {
			future_number.push_back(',');
			std::cout << get;
		}
		if (get == 8) back(future_number);
		if (get == 27) return DBL_MIN;
		if (get == 13) {
			if ((future_number.empty()) or (std::stod(future_number) > max) or (std::stod(future_number) < min)) continue;
			std::cout << std::endl;
			return std::stod(future_number);
		}
	}
}

bool bool_input(char lie = '0', char truth = '1') {
	char get;
	while (true)
	{
		get = _getch();
		if (get == truth) return true;
		if (get == lie) return false;
	}
}

std::string str_input(int max_len, int min_len = 1) {
	std::string future_string{};
	char get;
	while (true)
	{
		get = _getch();
		if (isalpha(get) or isdigit(get)) 
		{
			if (future_string.length() >= max_len)
			{
				continue;
			}
			future_string.push_back(get);
			std::cout << get;
		}
		if (get == 8) back(future_string);
		if (get == 27) return "\n";
		if (get == 13) 
		{
			std::cout << std::endl;
			if (future_string.length() >= min_len) return future_string;
		}
	}
}

int rand_int_input(int min = INT_MIN, int max = INT_MAX) {
	std::random_device RandomDevice;
	unsigned seed = RandomDevice();
	std::default_random_engine RandomEngine(seed);
	std::uniform_int_distribution<int> Border(min, max);
	return Border(RandomEngine);
}

double rand_double_input(double min = DBL_MIN, double max = DBL_MAX) {
	std::random_device RandomDevice;
	unsigned seed = RandomDevice();
	std::default_random_engine RandomEngine(seed);
	std::uniform_real_distribution<double> Border(min, max);
	return Border(RandomEngine);
}