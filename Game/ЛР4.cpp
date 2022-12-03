#include <iostream>
#include <fstream>

using namespace std;

#pragma region Инициализация функций

void MaxOfPunctuationMarksInSentence(char* buf, ifstream& file);
void SearchDuoNumberInSentence(char* buff, ifstream& fin);

#pragma endregion

#pragma region Главная функция

int main()
{
	setlocale(LC_ALL, "Russian");

	string pathToFile;									//Путь к файлу с названием файлв и его расширением

	cout << "Введите путь к файлу\n";
	cin >> pathToFile;

	ifstream file(pathToFile, ios::in | ios::binary);	//Создание потока получения данных из файла в простом и бинарном режиме

	if (!file)											//Проверка на успешность прочтения
	{
		cout << "Ошибка отурытия файла!";
		return 0;
	}

	file.seekg(0, ios_base::end);				//Переход в конец файла

	int file_size = file.tellg();						//Получение длинны файла

	file.seekg(0, ios_base::beg);				//Переход в конец файла

	char* buf = new char[file_size + 1];				//Создание буфера для хранения данных из файла

#pragma region Вызов функций

	SearchDuoNumberInSentence(buf, file);

#pragma endregion


	cout << endl;
	return 0;
}

#pragma endregion

#pragma region Функции

#pragma region Нахождение придложения с максимальным количеством знаков припенания

void MaxOfPunctuationMarksInSentence(char* buf, ifstream& file) {										// Передача в качестве параметров буфера и ссылки на поток ввода
	int punctuationMax = 0, punctuationNow = 0, currentStart = 0, positionStart = 0, positionEnd = 0;	// Инициализация переменных
	bool isSentenceFull = true;
	for (size_t i = 0; (buf[i] = file.get()) != EOF; i++)												// Прохождение до конца файла для чтения
	{
		switch (buf[i])																					// Проверка символов файла 
		{
		case '\n':																						// Если символ перехода на новую строку
			buf[i] = ' ';																				// то в массиве записать его как пробел
			break;
		case ',':																						// Если встречен знак препинания
			punctuationNow++;																			// то прибавить к счётчику 1
			break;
		case '.': case '?': case '!':																	// Если встречен знак окончания предложения
			if (punctuationMax < punctuationNow)														// то проверить, максимальное значение и то которое сейчас
			{
				punctuationMax = punctuationNow;														// при необходимости заменить 
				positionStart = currentStart;															// запомнить номер начала предложения
				positionEnd = i;																		// и запомнить символ конца предложения
			}

			punctuationNow = 0;																			// Обнулить счётчик
			currentStart = i + 1;																		// Запомнить начало нового предложения
			break;
		}
	}

	for (size_t i = positionStart; i <= positionEnd; i++)												// Вывод найденного предложения
	{
		if (isSentenceFull)																				// Вывод без лишнего пробела
		{
			if (buf[i] == ' ')
			{
				continue;
			}
			else
			{
				isSentenceFull = false;
			}
		}
		cout << buf[i];																					// Посимвольный вывод предложения
	}
}

#pragma endregion

#pragma region Вывод предложений с двухзначными числами

void SearchDuoNumberInSentence(char* buff, ifstream& fin) {
	int currentStart = 0, positionStart = 0, positionEnd = 0;	// Инициализация переменных
	bool isDuoSentence = false;
	for (size_t i = 0; (buff[i] = fin.get()) != EOF; i++)												// Прохождение до конца файла для чтения
	{
		switch (buff[i])																					// Проверка символов файла 
		{
		case '\n':																						// Если символ перехода на новую строку
			buff[i] = ' ';																				// то в массиве записать его как пробел
			break;
		case '.': case '?': case '!':																	// Если встречен знак окончания предложения														// при необходимости заменить 

			positionStart = currentStart;															// запомнить номер начала предложения
			positionEnd = i;																		// и запомнить символ конца предложения																	// Обнулить счётчик
			currentStart = i + 1;

			for (size_t j = positionStart; j < positionEnd; j++)
			{
				if ((!(buff[j - 1] >= '0' && buff[j - 1] <= '9'))
					&& (buff[j] >= '0' && buff[j] <= '9')
					&& (buff[j + 1] >= '0' && buff[j + 1] <= '9')
					&& (!(buff[j + 2] >= '0' && buff[j + 2] <= '9')))
				{
					isDuoSentence = true;
					j += 2;
				}
			}

			if (isDuoSentence)
			{
				for (size_t j = positionStart + 1; j <= positionEnd; j++)
				{
					cout << buff[j];
					if (buff[j] == positionEnd)
						cout << '\n';
				}

			}
			isDuoSentence = false;

			break;
		}
	}
}

#pragma endregion

#pragma endregion