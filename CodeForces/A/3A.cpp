#include <iostream>
#include <list>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/3/A
        I am happy to code :)
*/

int main(void) {

	std::string kingPosition, targetPosition;

	std::cin >> kingPosition >> targetPosition;

	if (kingPosition.empty() || targetPosition.empty() || kingPosition.length() != 2 || targetPosition.length() != 2)
		return (0);

	int moves = 0;
	std::list<std::string> listOfMoves;

	std::list<std::string>::iterator it;

	while (kingPosition != targetPosition) {
		if (kingPosition[0] < targetPosition[0] && kingPosition[1] > targetPosition[1]) {
			kingPosition[0] += 1;
			kingPosition[1] -= 1;
			listOfMoves.push_back("RD"); // e2 -> d3
			++moves;
		} else if (kingPosition[0] > targetPosition[0] && kingPosition[1] < targetPosition[1]) {
			kingPosition[0] -= 1;
			kingPosition[1] += 1;
			listOfMoves.push_back("LU");
			++moves; // h1 -> b2 
		} else if (kingPosition[0] < targetPosition[0] && kingPosition[1] < targetPosition[1]) {
			kingPosition[0] += 1;
			kingPosition[1] += 1;
			listOfMoves.push_back("RU");
			++moves;
		} else if (kingPosition[0] > targetPosition[0] && kingPosition[1] > targetPosition[1]) {
			kingPosition[0] -= 1;
			kingPosition[1] -= 1;
			listOfMoves.push_back("LD");
			++moves;
		} else if (kingPosition[0] == targetPosition[0] && kingPosition[1] < targetPosition[1]) {
			kingPosition[1] += 1;
			listOfMoves.push_back("U");
			++moves;
		} else if (kingPosition[0] == targetPosition[0] && kingPosition[1] > targetPosition[1]) {
			kingPosition[1] -= 1;
			listOfMoves.push_back("D");
			++moves;
		} else if (kingPosition[0] > targetPosition[0] && kingPosition[1] == targetPosition[1]) {
			kingPosition[0] -= 1;
			listOfMoves.push_back("L");
			++moves;
		} else if (kingPosition[0] < targetPosition[0] && kingPosition[1] == targetPosition[1]) {
			kingPosition[0] += 1;
			listOfMoves.push_back("R");
			++moves;
		}
	}

	std::cout << moves << std::endl;

	for (it = listOfMoves.begin(); it != listOfMoves.end(); ++it)
		std::cout << *it << std::endl;

	return (0);
}
