#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#include <map>
#include <list>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/2/A
        I am happy to code :)
*/

int main(void) {
	std::map<std::string, std::pair<long long, long long>> results;
	std::list<std::pair<std::string, long long>> rounds;
	int input;

	std::cin >> input;

	if (!input || input < 1 || input > 1000)
		return (0);

	std::string player;
	std::string winner;
	long long result = 0;
	long long round = 1;
	std::map<std::string, std::pair<long long, long long>>::iterator it;

	for (int i = 0; i < input; ++i) {
		std::cin >> player >> result;
		for (it = results.begin(); it != results.end(); ++it) {
			if (it->first == player) {
				it->second.first += result;
				it->second.second = round++;
				break ;
			}
		}
		if (it == results.end())
			results[player] = std::make_pair(result, round);
		rounds.push_back(std::make_pair(player, result));
	}

	long long finalMax = 0;

	for (it = results.begin(); it != results.end(); ++it) {
		if (it->second.first > finalMax)
			finalMax = it->second.first;
	}

	std::list<std::pair<std::string, long long>>::iterator itl;

	int lessRound = INT_MAX;
	int checker;

	/*
		The magic happens here, if the final result is not the finalMax, you must disconsider that player
		immediately. Then, the second step is check the round that the player finally got the finalMax.
		Discovering the less position, you found the winner of the game : )
	*/

	for (it = results.begin(); it != results.end(); ++it) {
		checker = 0;
		round = 1;
		for (itl = rounds.begin(); itl != rounds.end(); ++itl) {
			if (it->second.first == finalMax && it->first == itl->first) {
				checker += itl->second;
				if (checker >= finalMax && round < lessRound) {
					lessRound = round;
					winner = it->first;
				}
			}
			++round;
		}
	}

	std::cout << winner << std::endl;
	return (0);
}
