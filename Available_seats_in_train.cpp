/* В поезде 18 вагонов, в каждом из которых 36 мест. 
Информация о проданных на поезд билетах хранится в двумерном массиве, 
номера строк которых соответствуют номерам вагонов, а номера столбцов — номерам мест. 
Если билет на то или иное место продан, то соответствующий элемент массива имеет значение 1, в противном случае — 0. 
Напишите программу, определяющую число свободных мест в любом из вагонов поезда. */

#include <iostream>
#include <ctime>     // чтобы в randomize опираться на время запуска программы

const uint16_t number_of_cars{ 18 };
const uint16_t number_of_seats_in_car{ 36 };

uint16_t get_car_number()
{
	std::cout << "Введите номер вагона (от 1 до " << number_of_cars << "): ";
	uint16_t answer;
	std::cin >> answer;
	while (std::cin.fail() || (answer < 1) || (answer > number_of_cars))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Нужно ввести целое число от 1 до " << number_of_cars << ", повторите ввод: ";
		std::cin >> answer;
	}
    return (answer-1); // вычитаем 1, т.к. в массиве номера вагонов начинаются с 0, а не с 1 
}

uint16_t calculate_available_seats(bool* seats_array_for_choosen_car)
{
	uint16_t available_seats{ 0 };
	for (uint16_t seat = 0; seat < number_of_seats_in_car; ++seat)
		if (seats_array_for_choosen_car[seat] == 0)
			++available_seats;
	return available_seats;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
	// аналог randomize с привязкой ко времени запуска:
	srand(static_cast<unsigned int>(time(0)));

	// создаём и заполняем двумерный массив случайными булевыми значениями:
	bool busy_seats[number_of_cars][number_of_seats_in_car] = {};
	for (uint16_t car = 0; car < number_of_cars; ++car)
		for (uint16_t seat = 0; seat < number_of_seats_in_car; ++seat)
			busy_seats[car][seat] = rand() % 2;

	while (true)
		std::cout << "Количество свободных мест в выбранном вагоне: " 
			      << calculate_available_seats(busy_seats[get_car_number()])  << std::endl;
}