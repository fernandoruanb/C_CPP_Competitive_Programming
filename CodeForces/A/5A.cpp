#include <iostream>
#include <list>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/5/A
        I am happy to code :)
*/

int main(void) {
	int people = 0;
	std::list<std::string> chatServer;
	
	std::list<std::string>::iterator it;
	std::string command;
	unsigned long long bytes = 0;

	while (1) {
		std::getline(std::cin, command); // std::cin directly with >> stops at the first space

		if (std::cin.eof()) // for that question, we need to detect the EOF to know when we need to stop
			break ;

		if (command.empty())
			return (0);
		if (command[0] == '+') {
			for (it = chatServer.begin(); it != chatServer.end(); ++it) {
				if (*it == command.substr(1))
					break ;
			}
			if (it == chatServer.end()) {
				chatServer.push_back(command.substr(1));
				++people;
			}
		}
		else if (command[0] == '-') {
			for (it = chatServer.begin(); it != chatServer.end(); ++it) {
				if (*it == command.substr(1)) {
					chatServer.erase(it);
					--people;
					break ;
				}
			}
		}
		else {
			int length = 0;
			std::string message;

			while (length < command.length() && command[length] != ':')
				++length;

			if (command[length] == ':') 
				++length;

			while (length < command.length()) {
				message.push_back(command[length]); // to add is push_back
				++length;
			}
			bytes += message.length() * people;
		}
	}
	std::cout << bytes << std::endl;

	/*for (it = chatServer.begin(); it != chatServer.end(); ++it) {
		std::cout << *it << std::endl;
	}*/

	return (0);
}
