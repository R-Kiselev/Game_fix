#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;

void check_word_size(size_t size) {
	if (size < 8 || size > 30) {
		throw string{ "Error : wrong size" };
	}
}

void check_letters(map <char, int> start_word_letters, string temp_word, int player_number) {
	map <char, int> temp_word_letters = start_word_letters;

	for (char& c : temp_word) {
		// tolower() is used to ignore letter case 
		temp_word_letters[tolower(c)]--;

		if (temp_word_letters[tolower(c)] < 0) {
			throw string{ " player lost" };
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	string start_word;
	string current_word;

	cout << "Enter a word to start : \n";
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
		cout << player_number << " player enters a word : ";
		cin >> current_word;

		try {
			check_letters(start_word_letters, current_word, player_number);
		}
		catch (const string player_lost) {
			cout << player_lost;
			exit(3);
		}
		count++;
	}
}