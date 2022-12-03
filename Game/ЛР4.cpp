#include <iostream>
#include <fstream>

using namespace std;

#pragma region ������������� �������

void MaxOfPunctuationMarksInSentence(char* buf, ifstream& file);
void SearchDuoNumberInSentence(char* buff, ifstream& fin);

#pragma endregion

#pragma region ������� �������

int main()
{
	setlocale(LC_ALL, "Russian");

	string pathToFile;									//���� � ����� � ��������� ����� � ��� �����������

	cout << "������� ���� � �����\n";
	cin >> pathToFile;

	ifstream file(pathToFile, ios::in | ios::binary);	//�������� ������ ��������� ������ �� ����� � ������� � �������� ������

	if (!file)											//�������� �� ���������� ���������
	{
		cout << "������ �������� �����!";
		return 0;
	}

	file.seekg(0, ios_base::end);				//������� � ����� �����

	int file_size = file.tellg();						//��������� ������ �����

	file.seekg(0, ios_base::beg);				//������� � ����� �����

	char* buf = new char[file_size + 1];				//�������� ������ ��� �������� ������ �� �����

#pragma region ����� �������

	SearchDuoNumberInSentence(buf, file);

#pragma endregion


	cout << endl;
	return 0;
}

#pragma endregion

#pragma region �������

#pragma region ���������� ����������� � ������������ ����������� ������ ����������

void MaxOfPunctuationMarksInSentence(char* buf, ifstream& file) {										// �������� � �������� ���������� ������ � ������ �� ����� �����
	int punctuationMax = 0, punctuationNow = 0, currentStart = 0, positionStart = 0, positionEnd = 0;	// ������������� ����������
	bool isSentenceFull = true;
	for (size_t i = 0; (buf[i] = file.get()) != EOF; i++)												// ����������� �� ����� ����� ��� ������
	{
		switch (buf[i])																					// �������� �������� ����� 
		{
		case '\n':																						// ���� ������ �������� �� ����� ������
			buf[i] = ' ';																				// �� � ������� �������� ��� ��� ������
			break;
		case ',':																						// ���� �������� ���� ����������
			punctuationNow++;																			// �� ��������� � �������� 1
			break;
		case '.': case '?': case '!':																	// ���� �������� ���� ��������� �����������
			if (punctuationMax < punctuationNow)														// �� ���������, ������������ �������� � �� ������� ������
			{
				punctuationMax = punctuationNow;														// ��� ������������� �������� 
				positionStart = currentStart;															// ��������� ����� ������ �����������
				positionEnd = i;																		// � ��������� ������ ����� �����������
			}

			punctuationNow = 0;																			// �������� �������
			currentStart = i + 1;																		// ��������� ������ ������ �����������
			break;
		}
	}

	for (size_t i = positionStart; i <= positionEnd; i++)												// ����� ���������� �����������
	{
		if (isSentenceFull)																				// ����� ��� ������� �������
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
		cout << buf[i];																					// ������������ ����� �����������
	}
}

#pragma endregion

#pragma region ����� ����������� � ������������ �������

void SearchDuoNumberInSentence(char* buff, ifstream& fin) {
	int currentStart = 0, positionStart = 0, positionEnd = 0;	// ������������� ����������
	bool isDuoSentence = false;
	for (size_t i = 0; (buff[i] = fin.get()) != EOF; i++)												// ����������� �� ����� ����� ��� ������
	{
		switch (buff[i])																					// �������� �������� ����� 
		{
		case '\n':																						// ���� ������ �������� �� ����� ������
			buff[i] = ' ';																				// �� � ������� �������� ��� ��� ������
			break;
		case '.': case '?': case '!':																	// ���� �������� ���� ��������� �����������														// ��� ������������� �������� 

			positionStart = currentStart;															// ��������� ����� ������ �����������
			positionEnd = i;																		// � ��������� ������ ����� �����������																	// �������� �������
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