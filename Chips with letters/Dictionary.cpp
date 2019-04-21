
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary()
{
	StarFactor = false;
	for (int i = 0; i < 8; ++i)
		Letters[i] = 0;
	for (int i = 0; i < 33; ++i) {
		Costs[i] = 0;
	}
	Buffer[0] = 0;
	Last[0] = 0;
	maxCost = 0;
	BufferSize = 0;
	Stars = 0;
}

Dictionary::Dictionary(const char letters[], int size, int costs[], int size2) {
	StarFactor = false;
	for (int i = 0; i < 8; ++i) {
		Letters[i] = letters[i];
	}
	for (int i = 0; i < 7; ++i) {
		if (Letters[i] == '*') {
			StarFactor = true;
			Stars++;
		}
	}
	for (int i = 0; i < 33; ++i) {
		Costs[i] = costs[i];
	}
	Buffer[0] = 0;
	Last[0] = 0;
	maxCost = 0;
	BufferSize = 0;
}


Dictionary::~Dictionary()
{
	delete[] Letters;
}

int Dictionary::cost(string buffer){
	int result = 0;
	for (int i = 0; i < BufferSize; ++i) {
		if ((int)Buffer[i] >= 192 && (int)Buffer[i] <= 223) {
			result += Costs[(int)Buffer[i] - 192];
		}
		else { // от 224 до 255
			result += Costs[(int)Buffer[i] - 224];
		}
	}
	return result;
}

void Dictionary::findWord(std::string adress) {
	ifstream ifs(adress, ios_base::in);
	if (!ifs.is_open()) {
		cout << "Неправильный адрес файла" << endl;
		return;
	}
	char tmp;
	while (!ifs.eof()) {
		tmp = ifs.get();
		while (tmp != ',' || tmp == '/n') {
			Buffer += tmp;
			tmp = ifs.get();
		}
		bool relevant = true;
		if (Letters[7] == '*') {
			BufferSize = Buffer.size();
			int error = 0;
			char errorletter1 = ' ';
			char errorletter2 = ' ';

			if (StarFactor)
				error = Stars;
			for (int i = 0; i < BufferSize; ++i) {
				if (Buffer[i] == Letters[0] || Buffer[i] == Letters[1] || Buffer[i] == Letters[2] || Buffer[i] == Letters[3] || Buffer[i] == Letters[4] || Buffer[i] == Letters[5] || Buffer[i] == Letters[6] || Buffer[i] == Letters[7] || Buffer[i] == errorletter1 || Buffer[i] == errorletter2) {

				}
				else {
					if (error != 0) {
						if (errorletter1 == ' ')
							errorletter1 = Buffer[i];
						else
							errorletter2 = Buffer[i];
						error--;
					}
					else {
						relevant = false;
						break;
					}
				}
			}
			if (relevant) {
				int Tcost = 0;
				Tcost = cost(Buffer);
				if (Tcost > maxCost) {
					Last = Buffer;
					maxCost = Tcost;
				}
			}
			Buffer.clear();
		}
		else {
			BufferSize = Buffer.size();
			int error = 0;
			char errorletter1 = ' ';
			char errorletter2 = ' ';
			char errorletter3 = ' ';
			bool LastFactor = false;

			if (StarFactor)
				error = Stars;
			for (int i = 0; i < BufferSize; ++i) {
				if (Buffer[i] == Letters[0] || Buffer[i] == Letters[1] || Buffer[i] == Letters[2] || Buffer[i] == Letters[3] || Buffer[i] == Letters[4] || Buffer[i] == Letters[5] || Buffer[i] == Letters[6] || Buffer[i] == Letters[7] || Buffer[i] == errorletter1 || Buffer[i] == errorletter2 || Buffer[i] == errorletter3) {
					if (Buffer[i] == Letters[7])
						LastFactor = true;
				}
				else {
					if (error != 0) {
						if (errorletter1 == ' ') {
							errorletter1 = Buffer[i];
						}
						else
							if (errorletter2 == ' ')
								errorletter2 = Buffer[i];
							else
								errorletter3 = Buffer[i];
						error--;
					}
					else {
						relevant = false;
						break;
					}
				}
			}
			if (relevant && LastFactor) {
				int Tcost = 0;
				Tcost = cost(Buffer);
				if (Tcost > maxCost) {
					Last = Buffer;
					maxCost = Tcost;
				}
			}
			Buffer.clear();
		}
		while (!ifs.eof() && tmp != '/n') {
			tmp = ifs.get();
		}
		while (!ifs.eof() && tmp != '/n') {
			tmp = ifs.get();
		}
	}
	ifs.close();

}

void Dictionary::printres()const {
	if (Last.empty())
		cout << "There is no word for this letters" << endl;
	else
	    cout << Last << "  with cost = " << maxCost << endl;
}