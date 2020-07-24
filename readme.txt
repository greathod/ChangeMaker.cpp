-Guy Greathouse
-Last updated: 03/16/2020

-Files Submitting: ChangeMaker.cpp
						In this file, I was to write the dynamic programming algorithm
					for making change for a given amount and set of denominations. This
					file does this by using the bottom-up approach to solving this 
					problem by solving all of the subproblems first then adding and
					insertting the values from a table to the coinCounts needed. Also,
					if there was a given amount in which the denominations could not 
					give exact change for then the total would be made to zero along 
					with the coinCounts vector's values.
						I have 5 test cases. My first test case is looking at a made up 
					value to just simply check if my code works for the US denominations 
					given. This is important to test so that you can make sure that the
					code can run for this usual type of denomination. My second test case 
					is looking at if I use the made up value from before (12948) can be
					done in the other set of denominations and could so it displayed
					33:1 and 41:315. Something interesting about this test case is that 
					the total amount of coins needed to get the same value differred from
					one denomination to the next. The third test case I had was testing if
					the amount was 1 number off of the (12948 to 12947) would display
					0's. This test case is interesting to see if the I implemented 
					if there was no possible way to return the exact change with the given 
					denominations. My fourth test case is testing 0 given as an amount to 
					give in the US denominations. This is an interesting test case to see
					if my code deals with an extreme well. My last test case is testing 0 
					on the other denomination set. This is interesting to see if my code
					deals with the 0 in most cases correctly. Now, I would have tried double 
					values and things like that, but the code would not allow for such cases
					as we are not passing those types of parameters through the code.
					
					
-Limitations: A limitation to this project submission is that it will make the table for
				each subproblem everytime a new amount is given. Meaning that the firstTable 
				is not saved for the next instance of the problem for the same denominations.
									
-Help: N/A
	
-Honor Code:
	I have acted with honesty and integrity in producing this work 
	and am unaware of anyone who has not.
		X  David Guy Greathouse III