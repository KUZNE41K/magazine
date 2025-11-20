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
void RemoveStorageItem();
void ChangePrice();

void ChangeStorage();
void AddNewItem();
void ChangeName();
void DeleteItem();


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
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара \t"<<"\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t\n";
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
			AddStorageItem();
		}
		else if (choose == "4")
		{
			RemoveStorageItem();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
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
		
		if (IsNumber(chooseID) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseID) - 1;
			count = std::stoi(chooseCount);

			if (id<0 || id>storageSize - 1 || count < 0 || count>300)
			{
				std::cout << "Некорректный id или кол-во \n Максимальное кол-во товаров 300 \n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" 
					<< counterArr[id] << "---->" << counterArr[id] + count << "\n\n";
				std::cout << "Подтвердить? \n1-да \n2 нет\n Ввод - ";
				Getline(choose);
				if (choose=="1")
				{
					counterArr[id] += count;
					std::cout << "Товар успешно пополнен";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена пополнения товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}

}

void RemoveStorageItem()
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
			std::cout << "Отмена операции для списания!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите кол-во товара для списания ";
		Getline(chooseCount);

		if (IsNumber(chooseID) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseID) - 1;
			count = std::stoi(chooseCount);

			if (id<0 || id>storageSize - 1 || count < 0 || count>counterArr[id])
			{
				std::cout << "Некорректный id или кол-во \n Максимально кол-во для списания товаров - \n"
					<< counterArr[id]<<"\n\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t"
					<< counterArr[id] << "---->" << counterArr[id] - count << "\n\n";
				std::cout << "Подтвердить? \n1-да \n2 нет\n Ввод - ";
				Getline(choose);
				if (choose == "1")
				{
					counterArr[id] -= count;
					std::cout << "Товар успешно списан";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена списания товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangePrice()
{
	std::string chooseID, choosePrice, choose;
	unsigned int id = 0;
	double newPrice = 0.0;

	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "Введите id товара или \"exit\" для выхода ";
		Getline(chooseID);

		if (chooseID == "exit")
		{
			std::cout << "Отмена операции для изменения цены!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новую цену товара ";
		Getline(choosePrice);

		if (IsNumber(chooseID) && IsNumber(choosePrice))
		{
			id = std::stoi(chooseID) - 1;
			newPrice = std::stod(choosePrice);

			if (id < 0 || id > storageSize - 1 || newPrice < 0.0 || newPrice > 200000.99)
			{
				std::cout << "Некорректный id или кол-во \n Максимально цена товар - 200000.99 \n\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t"
					<< priceArr[id] << "---->" << newPrice << "\n\n";
				std::cout << "Подтвердить? \n1-да \n2 нет\n Ввод - ";
				Getline(choose);
				if (choose == "1")
				{
					priceArr[id] = newPrice;
					std::cout << "Цена успешно изменена";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена изменения цены\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить новый товар\n";
		std::cout << "2 - Изменить название товара\n";
		std::cout << "3 - Удалить товар\n";
		std::cout << "0 - Выход из редактора\n";
		std::cout << "Ввод - ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewItem();
		}
		else if (choose == "2")
		{
			ChangeName();
		}
		else if (choose == "3")
		{
			DeleteItem();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			Err();
		}
	}


}

void AddNewItem()
{
	std::string newName, newPrice, newCount, choose;
	double price = 0.0;
	unsigned int count = 0;
	bool exit;

	while (true)
	{
		exit = true;
		while (true)
		{
			system("cls");
			std::cout << "\tДобавление нового товара\nВведите exit для прекращение операции\n\n";
			std::cout << "Введите название нового товара - ";
			Getline(newName);
			if (newName == "exit")
			{
				std::cout << "Операция добавления товара прекращена!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (newName.size() <= 0 || newName.size() >= 60)
			{
				std::cout << "Ошибка имени.Максимальная длина 60 символов";
				Sleep(1500);
			}
			else
			{
				break;
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара\nВведите exit для прекращение операции\n\n";
			std::cout << "Введите кол-во нового товара - ";
			Getline(newCount);
			if (newCount == "exit")
			{
				std::cout << "Операция добавления товара прекращена!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 300 || count < 0)
				{
					std::cout << "Ошибка максимального кол-во товаров. Не более 300 ед";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара\nВведите exit для прекращение операции\n\n";
			std::cout << "Введите цену нового товара - ";
			Getline(newPrice);
			if (newPrice == "exit")
			{
				std::cout << "Операция изменения цены товара прекращена!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice))
			{
				price = std::stod(newPrice);
				if (price > 200000.99 || price < 0)
				{
					std::cout << "Ошибка максимальной цены товаров. Не более 200000.99 руб";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Новый товар "<< newName<<"\n";
			std::cout << "Кол-во " << count << "\n";
			std::cout << "Цена " << newPrice << "\n";
			std::cout << "Подтвердить?\n1 - Да 2 - Нет\nВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				storageSize++;
				unsigned int* idArrTemp = new unsigned int[storageSize];
				std::string* nameArrTemp = new std::string[storageSize];
				unsigned int* countArrTemp = new unsigned int[storageSize];
				double* priceArrTemp = new double[storageSize];

				FillArray(idArrTemp, idArr, storageSize - 1);
				FillArray(nameArrTemp, nameArr, storageSize - 1);
				FillArray(countArrTemp, counterArr, storageSize - 1);
				FillArray(priceArrTemp, priceArr, storageSize - 1);

				idArrTemp[storageSize - 1] = storageSize;
				nameArrTemp[storageSize - 1] = newName;
				countArrTemp[storageSize - 1] = count;
				priceArrTemp[storageSize - 1] = price;

				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(counterArr,countArrTemp);
				std::swap(priceArr, priceArrTemp);
				
				delete[]idArrTemp,nameArrTemp,countArrTemp,priceArrTemp;
				std::cout << "Идет подготовка....";
				Sleep(2000);
				std::cout << "Товар успешно добавлен\n\n";
				Sleep(1500);
				break;

			}
			else if(choose == "2")
			{
				std::cout << "Отмена";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
		}
		if (exit == false)
		{
			break;
		}
	}
}

void ChangeName()
{
	std::string chooseId, newName, choose;
	unsigned int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);

		std::cout << "\nВведите id товара или exit для выхода - ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции смены названия!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новое название товара - ";
		Getline(newName);
		if (newName.size()<=0||newName.size()>=60)
		{
			std::cout << "Ошибка имени.Максимальная длина 60 символов";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId)-1;
			if (id<0|| id>storageSize -1)
			{
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
			}
			else
			{
				std::cout << nameArr[id] << " ----> " << newName << "\n\n";
				std::cout << "Подвердить? \n1 - да\n2- нет\nВвод ";
				Getline(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "Смена названия завершена";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена операции\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}

			}
		}


	}



}

void DeleteItem()
{
	std::string chooseID, choose;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите Id товара для удаление или exit для выхода";
		Getline(chooseID);
		if (chooseID == "exit")
		{
			std::cout << "Отмена операции удаление товара";
			Sleep(1500);
			break;
		}

		if (IsNumber(chooseID))
		{
			id = std:: stoi(chooseID) - 1;
			if (id<0 || id>storageSize - 1)
			{
				std::cout << "Ошибка id\n";
				Sleep(1500);
			}
			else
			{
				std::cout << "Товар на удаление - " << nameArr[id] << "\n\n";
				std::cout << "Подтвердить?\n1-да\n2-нет\nВвод - ";
				if (choose =="1")
				{
					storageSize--;
					unsigned int* idArrTemp = new unsigned int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];

					for (size_t i = 0,c = 0; i < storageSize; i++,c++)
					{
						if (id == c)
						{
							c++;
						}
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = counterArr[c];
						priceArrTemp[i] = priceArr[c];
					}

					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(counterArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);

					delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
					std::cout << "Идет подготовка....";
					Sleep(2000);
					std::cout << "Товар успешно удален\n\n";
					Sleep(1500);
					break;


				}
				else if (choose == "2")
				{
					std::cout << "Отмена";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}

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
