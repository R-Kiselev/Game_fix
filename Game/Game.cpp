#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
using namespace std;

void check_word_size(size_t size) {

	if (size < 8 || size > 30) {
		throw string{ "Error : wrong size" };
	}

}

void check_letters(map <char, int> start_word_letters, string temp_word) {

	map <char, int> temp_word_letters = start_word_letters;

	for (char& c : temp_word) {

		temp_word_letters[tolower(c)]--;

		if (temp_word_letters[tolower(c)] < 0) {
			throw string{ " игрок проиграл" };
		}

	}
}

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	string start_word;
	string temp_word;

	cout << "¬ведите начальное слово : \n";
	cin >> start_word;

	try
	{
		check_word_size(start_word.size());
	}
	catch (const string error_message)
	{
		cout << error_message;
		exit(1);
	}

	map <char, int> start_word_letters{};
	for (char& c : start_word) {
		start_word_letters[tolower(c)]++;
	}

	int count = 0;
	while (true) {
		int player_number = count % 2 + 1;
		cout << player_number << " пользователь вводит слово : ";
		cin >> temp_word;

		try {
			check_letters(start_word_letters, temp_word);
		}
		catch (const string lost) {
			cout << player_number << lost;
			exit(3);
		}
		count++;
	}
}