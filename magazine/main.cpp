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
void ShowStorage(int mode = 0);
void AddStorageItem();
template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize);


//-------------------------------------------------------



//--------------------Служебные функции------------------
void Start();
bool login();
void ShowSuperAdminMenu();
bool IsNumber(const std::string& str);
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
		"Тайский черный чай","Фунчоза"
	};
	unsigned int count[staticSize]{30,22,44,18,13,24,34,2,4,15};
	double price[staticSize]{224.5,300.2,455.5,120.7,300.9,222.4,150.2,130.3,333.5,344.0};

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	counterArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	isStorageCreate = true;

	FillArray(idArr, id, storageSize);
	FillArray(nameArr, name, storageSize);
	FillArray(counterArr, count, storageSize);
	FillArray(priceArr, price, storageSize);

}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара \t" <<
			"Кол-во\t" << "Цена\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] <<
				"\t" << counterArr[i] << "\t" << priceArr[i] << "\n";
		}
		system("pause");
		system("cls");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара \t" <<
			"Кол-во\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] <<
				"\t" << counterArr[i]<< "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара \t" << "Цена\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] <<
				"\t" << priceArr[i] << "\n";
		}
	}


}

void Start()
{
	std::string choose;
	
	if (login())
	{
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "Выберите склад \n1 - готовый склад\n 2 - создать новый склад\n Ввод - ";
				Getline(choose);
				if (choose == "1")
				{
					system("cls");
					createStorage();
					ShowSuperAdminMenu();
					
				}
				else if (choose == "2")
				{
					//создать новый склад
				}
				else
				{
					Err();
				}
			}	
		}
		else if (currentStatus == userStatus[1])
		{
			createStorage();
			// открытие + создание склада
		}
		else if (currentStatus == userStatus[2])
		{
			createStorage();
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
		std::cout << "\n\n\nМагазин Огузка\n\n\n";
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
				system("cls");
				std::cout << "Пользователь " << loginArr[i]<< "\n\nДобро пожаловать\n\n";
				std::cout << "Наш статус " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				return true;
			}
		}
		Err();

	}
}

void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Изменить цену\n";
		std::cout << "6 - Редактировать склад\n";
		std::cout << "7 - Редактировать персонал\n";
		std::cout << "8 - Отчет о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод - ";
		Getline(choose);
		if (choose == "1")
		{
			
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			
		}
		else
		{
			Err();
		}
	}

}

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Ошибка длина числа, максимум девятизначные числа\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Выше число не является числом!\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}

void AddStorageItem()
{
	std::string chooseID, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите id товара или \"exit\" для выхода ";
		Getline(chooseID);
		
		if (chooseID == "exit")
		{
			std::cout << "Отмена операции для пополнения!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите кол-во товара для пополнения ";
		Getline(chooseCount);
		
		
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

template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize)
{
	for (size_t i = 0; i < arraySize; i++)
	{
		dynamicArray[i] = staticArray[i];
	}
}
