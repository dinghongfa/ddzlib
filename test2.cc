#include "card.h"
#include "deck.h"
#include "hole_cards.h"
#include "community_cards.h"
#include "card_statistics.h"
#include "card_analysis.h"
#include "card_find.h"

int main(int argc, char *argv[])
{
	Deck deck;
	deck.fill();
	deck.debug();
	deck.shuffle(1);
	deck.debug();
	//Card::sort_by_ascending(deck.cards);
	//deck.debug();
	
	HoleCards hole_cards1;
	HoleCards hole_cards2;
	HoleCards hole_cards3;
	CommunityCards community_cards;
	deck.get_hole_cards(hole_cards1);
	deck.get_hole_cards(hole_cards2);
	deck.get_hole_cards(hole_cards3);
	deck.get_community_cards(community_cards);
	
	hole_cards1.debug();
	hole_cards2.debug();
	hole_cards3.debug();
	community_cards.debug();
	deck.debug();
	
	vector<Card> cards;
	hole_cards1.copy_cards(&cards);
	Card::dump_cards(cards, "test cards begin");
	
	CardStatistics card_stat;
	card_stat.statistics(cards);
	Card::dump_cards(cards, "test cards after");
	printf("\n\n\n");
	
   /**
    * suit  0  方块  1 梅花   2  红桃    3黑桃
    * 	
   0x01, 0x11, 0x21, 0x31,		//A 14
   0x02, 0x12, 0x22, 0x32,		//2 15
   0x03, 0x13, 0x23, 0x33,		//3 3
   0x04, 0x14, 0x24, 0x34,		//4 4
   0x05, 0x15, 0x25, 0x35,		//5 5
   0x06, 0x16, 0x26, 0x36,		//6 6
   0x07, 0x17, 0x27, 0x37,		//7 7
   0x08, 0x18, 0x28, 0x38,		//8 8
   0x09, 0x19, 0x29, 0x39,		//9 9
   0x0A, 0x1A, 0x2A, 0x3A,		//10 10
   0x0B, 0x1B, 0x2B, 0x3B,		//J 11
   0x0C, 0x1C, 0x2C, 0x3C,		//Q 12
   0x0D, 0x1D, 0x2D, 0x3D,		//K 13
   0x0E,						//小王
   0x0F						//大王
    * @author luochuanting
    */
	{	
		// test card analysis
		//int arr0[] = {0x0C, 0x1C, 0x2C, 0x3C, 0x0E, 0x0F};
		//int arr1[] = {0x0D, 0x1D, 0x2D, 0x3D, 0x03, 0x17};
		 
		//int arr[] = {0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28};
		// int arr[] = {0x06, 0x16, 0x26, 0x14, 0x04, 0x24, 0x05, 0x15, 0x25, 0x07, 0x17, 0x27,0x02, 0x12, 0x22, 0x32};
		int arr0[] = {0x03, 0x13, 0x23, 0x06, 0x16, 0x26, 0x14, 0x04, 0x24, 0x05, 0x15, 0x25, 0x07, 0x17, 0x27, 0x09};
		int arr1[] = {0x03, 0x13, 0x23, 0x06, 0x16, 0x26, 0x14, 0x04, 0x24, 0x05, 0x15, 0x25, 0x0B, 0x1B, 0x2B, 0x09};
		// int arr[] = {0x0e, 0x0f};
		CardAnalysis::test(arr0, sizeof(arr0) / sizeof(int), arr1, sizeof(arr1) / sizeof(int));
	}
	printf("\n\n\n");
	{	//
		// int arr0[] = {0x03, 0x13, 0x23, 0x04, 0x14, 0x24, 0x05, 0x15, 0x25, 0x08, 0x18, 0x09, 0x19, 0x0A, 0x1A};
		int arr0[] = {0x06, 0x16, 0x26, 0x36, 0x0A, 0x1A, 0x02, 0x12};
		int arr1[] = {0x0D, 0x1D, 0x01, 0x09, 0x19, 0x29, 0x39, 0x0A, 0x1A, 0x2A, 0x0B, 0x1B, 0x2B, 0x3B, 0x03, 0x13, 0x23, 0x04, 0x14, 0x34, 0x05, 0x15, 0x35, 0x06, 0x26, 0x36, 0x07, 0x17, 0x27, 0x37, 0x08, 0x18, 0x28, 0x38};
		CardFind::test(arr0, sizeof(arr0) / sizeof(int), arr1, sizeof(arr1) / sizeof(int));	
	}
	printf("\n\n\n");
	{
		// int arr0[] = {0x0D, 0x1D, 0x01, 0x09, 0x19, 0x29, 0x39, 0x0A, 0x1A, 0x2A, 0x0B, 0x1B, 0x2B, 0x3B, 0x03, 0x13, 0x23, 0x04, 0x14, 0x34, 0x05, 0x15, 0x35, 0x06, 0x26, 0x36, 0x07, 0x17, 0x27, 0x37, 0x08, 0x18, 0x28, 0x38};
		int arr0[] = {0x02, 0x0C, 0x0D, 0x0E, 0x0F, 0x0D, 0x1D, 0x01, 0x09, 0x19, 0x29, 0x39, 0x0A, 0x1A, 0x2A, 0x0B, 0x1B, 0x2B, 0x3B, 0x03, 0x13, 0x23, 0x04, 0x14, 0x34, 0x05, 0x15, 0x35, 0x06, 0x26, 0x36, 0x07, 0x17, 0x27, 0x37};
		CardFind::test(arr0, sizeof(arr0) / sizeof(int));	
	}
	return 0;
}