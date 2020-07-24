#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * ChangeMaker
 *
 * Author: Barbara Anthony
 * Last Modified: 2/28/2020
 * Developed: Guy Greathouse
 * Last Modified: 3/
 * Implement the function makeChange below which determines
 * the fewest possible coins to make change for a given amount
 * given an arbitrary set of coin denominations.
 *
 * IMPORTANT: You MUST use a DYNAMIC PROGRAMMING algorithm to
 *            determine the MINIMUM number of coins needed.
 *            While a greedy algorithm works for standard
 *            US currency denominations, your code should
 *            handle arbitrary coin denominations in which case
 *            the simple greedy algorithm does not always produce
 *            the optimal result (see Section 9.1 of Levitin).
 *
 * INPUT: unsigned amount
 *          This is the total amount that needs to be returned
 *          in coins.
 *
 * INPUT: const vector<unsigned> & denominations
 *          This vector contains the denominations of each of the
 *          allowed coins. In USD, the usual denominations are
 *          1 (penny), 5 (nickel), 10 (dime) and 25 (quarter),
 *          but your code should admit any set of integral
 *          denominations. You may assume that the denominations
 *          you are given are distinct and in increasing order.
 *
 * OUTPUT: vector<unsigned> & coinCounts
 *          The function should set this to be a vector of size
 *          equal to the number of denominations and in each
 *          location, contain the number of coins to be returned
 *          in the given denomination.
 *
 * RETURN: unsigned
 *          The function should return the total number of coins
 *          to be returned. Note: this should be the sum of the values
 *          in the coinCounts vector.
 *
 * If there is no possible way to return a given amount with the
 * denominations specified, your code should return 0 and put all
 * zeros in the coinCounts vector.
 *
 * Example: suppose coins come in denominations of 1, 7 and 8.
 * Then the denominations vector should contain three items,
 * < 1, 7, 8 >. If the user wants to make change for 22 cents,
 * then the minimum set of coins is two 7s and one 8. The
 * function make change should return 3 (for three total
 * coins) and put the values <0, 2, 1> in the coinCounts vector,
 * denoting that there are no 1s, two 7s and one 8.
 *
 */

unsigned totalCoinsNeeded(const vector<unsigned> & denominations, vector<unsigned> & coinCounts){
	//gets the minimum total coins needed
		unsigned totalCoins = 0;
		for(int i = 0; i < denominations.size(); i++){
			//adds all the values in the coinCounts vector together
			totalCoins += coinCounts[i];
		}
	return totalCoins;
}

unsigned makeChange(unsigned amount,
		const vector<unsigned> & denominations,
		vector<unsigned> & coinCounts) {
	coinCounts.resize(denominations.size());

	//created this vector to store the count information needed
	vector<unsigned> firstTable;
	//set the size of this vector to amount+1
	firstTable.resize(amount+1);
	//set the original value to 0
	firstTable[0] = 0;
	//initialize j to 0
	int j = 0;
	//loop through each instance of the amount
	for(int i = 1; i <= amount; i++){
		//save i in num because I am changing num
		int num = i;
		//check before entering while loop if the number is equal to some denomination[j+1] is so increase j
		if(num == denominations[j+1]){
			//increase j if num == to the next denomination
			j++;
		}
		//while num > 0 AND num >= the particular denomination
		while(num > 0 && num >= denominations[j]){
			//decrease the num by the amount of denominations until either of the conditions arise
			num -= denominations[j];
			//update the count for that instance
			firstTable[i]++;
		}
	}

	//save amount in changeToMake
	int changeToMake = amount;
	//loop through each denomination from the largest denomination
	for(int i = denominations.size()-1; i >= 0; i--){
		//while the change is either not zero or the change is >= the smallest denomination
		while(changeToMake > 0 && changeToMake >= denominations[i]){
			//insert the value into coinCounts[i] to be the value in the firstTable[changeToMake]
			int valueToInsert = firstTable[changeToMake];
			coinCounts[i] = valueToInsert;
			//decrease changeToMake by the denomination currently on
			changeToMake-=denominations[i]*valueToInsert;
		}
	}

	//if there is an instance where the denominations don't give exact change, then return 0 for everything
	if(changeToMake > 0){
		//loop through the size of coinCounts
		for(int i = 0; i < coinCounts.size(); i++){
			//inserts 0 in all of the spots in coinCounts for these instances.
			coinCounts[i] = 0;
		}
	}

	//return the minimum total amount of coins
	return totalCoinsNeeded(denominations, coinCounts);
}

void printResults(unsigned amount,
		const vector<unsigned> & denominations,
		unsigned total,
		vector<unsigned> & coinCounts) {
	cout << "   ---- " << amount << " ----" << endl;
	for (unsigned i=0; i<denominations.size(); i++) {
		cout << setw(6) << denominations[i] << ": " << coinCounts[i] << endl;
	}
	cout << " Total: " << total << endl;
	cout << endl;
}

void makeChangeAndPrintResults(unsigned amount, const vector<unsigned> & denominations) {
	vector<unsigned> coinCounts;
	unsigned total =  makeChange(amount, denominations, coinCounts);
	printResults(amount, denominations, total, coinCounts);
}

int main() {
	vector<unsigned> denominations;
	denominations.push_back(1);
	denominations.push_back(5);
	denominations.push_back(10);
	denominations.push_back(25);

	makeChangeAndPrintResults(47, denominations);
	makeChangeAndPrintResults(2020, denominations);
	//Test case #1: to make sure that it would get the correct thing for large numbers
	makeChangeAndPrintResults(12948, denominations);
	//Test case #4: to check what it does with zero
	makeChangeAndPrintResults(0, denominations);
	//Test case #6 (for Assignment #9): Check the functionality of denominations <1, 5, 10, 25> using the greedy algorithm
	makeChangeAndPrintResults(120012, denominations);

	denominations.clear();
	denominations.push_back(33);
	denominations.push_back(37);
	denominations.push_back(39);
	denominations.push_back(41);

	sort(denominations.begin(), denominations.end());

	makeChangeAndPrintResults(42, denominations);
	makeChangeAndPrintResults(194, denominations);
	makeChangeAndPrintResults(2000, denominations);
	makeChangeAndPrintResults(2020, denominations);
	//Test case #2: to make sure that there is consistency throughout the code (should give me 41: 315, 33: 1)
	makeChangeAndPrintResults(12948, denominations);
	//Test case #3: to make sure that it takes care of it even if it is 1 number off
	makeChangeAndPrintResults(12947, denominations);
	//Test case #5: to check what it does with 0 in a different set of denominations
	makeChangeAndPrintResults(0, denominations);
	return 0;
}
