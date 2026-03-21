#include <iostream>
#include <list>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/453/A
        I am happy to code :)
*/

int main(void) {
	int input;

	std::cin >> input;

	if (!input || input < 1 || input > 100000)
		return (0);
	
	std::list<std::pair<int, int>> laptopsDatabase;

	int price, quality;

	for (int i = 0; i < input; ++i) {
		std::cin >> price >> quality;
		laptopsDatabase.push_back(std::make_pair(price, quality));
	}

	std::list<std::pair<int, int>>::iterator it;
	std::list<std::pair<int, int>>::iterator tmp;

	laptopsDatabase.sort(); // yes, to sort a list we have the function member sort()

	/*
		We do not need to compare every laptop with the entire list to discover if it is more cheap than
		another with same or better quality than another more expensive. I failed a lot until discover it.
		Another thing, focus in compare only the next laptop and not all from that position
	*/

	for (it = laptopsDatabase.begin(); it != laptopsDatabase.end(); ++it) {
		// it is to check each laptop with all the next values possible
		/*for (tmp = std::next(it); tmp != laptopsDatabase.end(); ++tmp) {
			if (it->first < tmp->first && tmp->second <= it->second) {
				std::cout << "Happy Alex" << std::endl;
				return (0);
			}
		}*/
		tmp = std::next(it);
		if (tmp != laptopsDatabase.end()) {
			if (it->first < tmp->first && tmp->second <= it->second) {
				std::cout << "Happy Alex" << std::endl;
				return (0);
			}
		}
	}
	std::cout << "Poor Alex" << std::endl;
	return (0);
}
