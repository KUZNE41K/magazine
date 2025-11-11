#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
// ----------------------Учетные записи------------------
size_t userSize = 2;
std::string userStatus[3]{ "Супер администратор","Администратор","Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "admin","user" };
std::string* passArr = new std::string[userSize]{ "admin","user" };
std::string* statusArr = new std::string[userSize]{ userStatus[0],userStatus[2] };
std::string currentStatus;
//-------------------------------------------------------

//---------------------Склад-----------------------------
size_t storageSize = 0;
unsigned int* idArr=nullptr;
std::string* nameArr = nullptr;
unsigned int* counterArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreate = false;

void createStorage();


//-------------------------------------------------------



//--------------------Служебные функции------------------
void Start();
bool login();
inline void Getline(std::string& str);
inline void Err(int time =1500);
//-------------------------------------------------------



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	
	Start();
	delete[] loginArr, passArr, statusArr;
	if (isStorageCreate)
	{
		delete[]idArr, nameArr, counterArr, priceArr;
	}


	return 0;
}



void createStorage()
{
	const int staticSize = 10;
	unsigned int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]
	{
		"Buldak","Чипсы рисовые с томатом","Соевое мясо",
		"Имбирь с медом","Моти","Рамунэ","Онигири","Кимчи",
		"Тайский черный чай"
	};
	unsigned int count[staticSize]{30,22,44,18,13,24,34,2,4,15};
	double price[staticSize]{224.5,300.0,455.5,120.7,300.9,222.4,150.2,130.3,333.5,344.0};

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	counterArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	isStorageCreate = true;


}

void Start()
{
	std::cout << "\n\n\nМагазин Огузка\n\n\n";
	if (login())
	{
		if (currentStatus == userStatus[0])
		{
			// открытие + создание склада 
		}
		else if (currentStatus == userStatus[1])
		{
			// открытие + создание склада
		}
		else if (currentStatus == userStatus[2])
		{
			// открытие + создание склада
		}
	}
	else
	{
		system("cls");
		std::cout << "Завершение работы программы ";
	}
}

bool login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "Введите логин ";
		Getline(login);
		std::cout << "Введите пароль ";
		Getline(pass);

		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}


		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "Пользователь " << loginArr[i]<< "\n\nДобро пожаловать\n\n";
				std::cout << "Наш статус " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				return true;
			}
		}
		Err();

	}
}

inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');

}

inline void Err(int time)
{
	std::cout << "Некоректный ввод\n\n";
	Sleep(time);
	system("cls");
}
