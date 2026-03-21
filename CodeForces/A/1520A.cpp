#include <iostream>
#include <list>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1520/A
        I am happy to code :)
*/

int main(void) {
	int input;

	std::cin >> input;

	if (input < 1 || input > 1000)
		return (0);

	std::list<std::pair<int, std::string>> myTasks;
	int quantityOfTasks = 0;
	std::string tasks = "";

	while (input--) {
		std::cin >> quantityOfTasks >> tasks;
		myTasks.push_back(std::make_pair(quantityOfTasks, tasks));
	}

	std::list<char> characterList;
	std::list<std::pair<int, std::string>>::iterator it;
	std::list<char>::iterator itc;
	char letter;
	int index = 0;
	bool flag = false;

	for (it = myTasks.begin(); it != myTasks.end(); ++it) {
		index = 0;
		flag = false;
		characterList.clear();
		letter = it->second[index];
		characterList.push_back(letter);

		while (index <= it->first) {
			if (it->second[index] != letter) {
				for (itc = characterList.begin(); itc != characterList.end(); ++itc) {
					if (*itc == it->second[index]) {
						flag = true;
						break ;
					}
				}
				if (itc == characterList.end()) {
					characterList.push_back(letter);
					letter = it->second[index]; // A -> B, finalizing a sequence of letters
				}
			}
			++index;
		}
		if (flag)
			std::cout << "NO" << std::endl;
		else
			std::cout << "YES" << std::endl;
	}
	return (0);
}
