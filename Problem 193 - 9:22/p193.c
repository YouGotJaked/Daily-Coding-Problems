/*
 * Given an array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock.
 * You're also given a number 'fee' that represents a transaction fee for each buy and sell transaction.
 * 
 * You must buy before you can sell the stock, but you can make as many transactions as you like.
 *
 * For example, given [1, 3, 2, 8, 4, 10] and fee = 2, you should return 9, since you could buy the stock at 1 dollar, and sell at 8 dollars, and then buy it at 4 dollars and sell it at 10 dollars.
 * Since we did two transactions, there is a 4 dollar fee, so we have 7 + 6 = 13 profit minus 4 dollars of fees.
 */

#include <stdio.h>

typedef struct interval {
	int buy;
	int sell;
} Interval;

void print_solution(Interval *sol, int count);

void buy_sell_stock(int *price, int n) {
	// need at least 2 days
	if (n < 2) {
		return;
	}

	// solution pairs count
	int count = 0;

	// solution array
	Interval sol[n/2 + 1];

	// traverse array
	int i = 0;
	while (i < n-1) {
		// find local min
		while ((i < n-1) && (price[i+1] <= price[i])) {
			i++;
		}

		// no possible further solution at end
		if (i == n-1) {
			break;
		}

		// store min index
		sol[count].buy = i++;
		
		// find max
		while ((i < n) && (price[i] >= price[i-1])) {
			i++;
		}

		// store max index, increment count
		sol[count++].sell = i-1;
	}

	print_solution(sol, count);
}

void print_solution(Interval *sol, int count) {
	if (count == 0) {
		printf("No profit\n");
	} else {
		for (int i = 0; i < count; i++) {
			printf("Buy on day %d\t Sell on day %d\n", sol[i].buy+1, sol[i].sell+1);
		}
	}
}

int main() {
	int price[] = {1, 3, 2, 8, 4, 10};
	int n = sizeof(price) / sizeof(price[0]);
	buy_sell_stock(price,n);
}
