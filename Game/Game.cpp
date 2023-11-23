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

void check_letters(map <char, int> start_word_letters, string temp_word, int current_player) {
	map <char, int> current_word_letters = start_word_letters;

	for (char& c : temp_word) {
		// tolower() is used to ignore letter case 
		current_word_letters[tolower(c)]--;

		if (current_word_letters[tolower(c)] < 0) {
			throw string{to_string(current_player) + " player lost" };
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
	catch (const string wrong_size)
	{
		cout << wrong_size;
		exit(1);
	}

	map <char, int> start_word_letters{};
	for (char& c : start_word) {
		start_word_letters[tolower(c)]++;
	}

	int count = 0;
	while (true) {
		int current_player = count % 2 + 1;

		cout << current_player << " player enters a word : ";
		cin >> current_word;

		try {
			check_letters(start_word_letters, current_word, current_player);
		}
		catch (const string player_lost) {
			cout << player_lost;
			exit(3);
		}
		count++;
	}
}