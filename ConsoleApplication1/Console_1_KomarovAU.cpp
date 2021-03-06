// Console_1_KomarovAU.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>

#include "Shape.h"
#include "Square.h"
#include "SquareShadow.h"
#include "Text.h"
#include "SquareText.h"
#include "SquareShadowText.h"

#include "TreeMap.h"
#include "TreeMapIterator.h"

#include <vector>
#include <queue>
#include <map>

void testSTLVector();
void testSTLQueue();
void testSTLMap();

void printStr(const std::string str);

int main()
{
	// Square, Square with shadow, Text, Text in Square
	// Map(key,value) using tree

	//std::cout << "Hello. World" << std::endl;

	// New
	std::cout << "Constructor:" << std::endl;
	Square *square = new Square();
	SquareShadow *squareShadow = new SquareShadow();
	Text *text = new Text();
	SquareText *squareText = new SquareText("Text-SqT", 100);
	SquareShadowText *squareShadowText = new SquareShadowText("Text-SqShT", 123, Coloryte(3, 2, 1));

	// Print
	std::cout << "Print:" << std::endl;
	std::cout	<< *square << std::endl
				<< *squareShadow << std::endl
				<< *text << std::endl
				<< *squareText << std::endl
				<< *squareShadowText << std::endl;
	
	// Draw
	std::cout << "Draw:" << std::endl;
	square->draw();
	squareShadow->draw();
	text->draw();
	squareText->draw();
	squareShadowText->draw();

	// Start
	std::cout << "Starting test." << std::endl;
	// Set fields
	std::cout << "Set fields:" << std::endl;
	squareShadowText->setEdge(6);
	squareShadowText->setShadowColor(6, 7, 8);
	squareShadowText->setText("Square Shadow!");
	std::cout << *squareShadowText << std::endl;

	// TreeMap
	TreeMap<std::string, Shape *> treeMap;
	treeMap.add("Com5", square);
	treeMap.add("Com3", square);
	treeMap.add("Com2", square);
	treeMap.add("Com1", square);
	treeMap.add("Com7", squareShadow);
	treeMap.add("Com6", text);
	treeMap.add("Com9", text);

	std::cout << std::endl;
	printStr("Print tree:");
	treeMap.print();
	
	//TreeMapIterator<std::string, Shape *>* iter = &treeMap.begin();
	//std::cout << "Test. Iterator: " << std::endl
	//	<< iter->first() << std::endl;
	//iter->toNext();
	//if (iter == nullptr) {
	//	std::cout << "OMG.";
	//}
	//else {
	//	std::cout << std::endl
	//		<< iter->first() << std::endl;
	//}
	//iter->setSecond(squareText);
	//iter->toNext();
	//if (iter == nullptr) {
	//	std::cout << "OMG.";
	//}
	//else {
	//	std::cout << std::endl
	//		<< iter->first() << std::endl;
	//}
	//iter->toNext();
	
	//treeMap.print();

	std::cout << "Test. Iterator as For: " << std::endl;
	for (TreeMapIterator<std::string, Shape *> iter = treeMap.begin(); iter != treeMap.end(); ++iter) {
		std::cout << iter.first() << std::endl;
	};



	// Finish
	std::cout << comEnd << std::endl;
	std::cout << "Finish test." << std::endl;
	// Delete
	std::cout << "Destructor:" << std::endl;
	delete square;
	delete squareShadow;
	delete text;
	delete squareText;
	delete squareShadowText;

	// Test STL
	//bool isTestVector = true;
	//bool isTestQueue = true;
	//bool isTestMap = true;
	bool isTestVector = false;
	bool isTestQueue = false;
	bool isTestMap = false;

	if (isTestVector) {
		testSTLVector();
	}
	if (isTestQueue) {
		testSTLQueue();
	}
	if (isTestMap) {
		testSTLMap();
	}


	//int a = 0;
	//std::cin >> a;
	system("pause");

    return 0;
}

void testSTLVector() {
	std::cout << std::endl;

	printStr("Test std::vector :");
	std::vector<std::string> vect;
	printStr("push_back: a");
	vect.push_back("a");
	printStr("push_back: le");
	vect.push_back("le");
	printStr("push_back: c");
	vect.push_back("c");
	printStr("pop_back: c");
	vect.pop_back();
	printStr("push_back: x");
	vect.push_back("x");
	printStr("Print vector :");
	for (std::string str : vect) {
		std::cout << str;
	}
	std::cout << std::endl
		<< "End test std::vector." << std::endl;
};

void testSTLQueue() {
	std::cout << std::endl;

	printStr("Test std::queue :");
	std::queue<std::string> que;
	printStr("push: a");
	que.push("a");
	printStr("push: le");
	que.push("le");
	printStr("push: c");
	que.push("c");
	printStr("pop: c");
	que.pop();
	printStr("push: x");
	que.push("x");
	printStr("Print queue :");
	while (!que.empty()) {
		std::cout << que.front();
		que.pop();
	}
	std::cout << std::endl
		<< "We got other word because it is FIFO." << std::endl
		<< "End test std::queue." << std::endl;
};

typedef std::map<std::string, int> TestMap;
void testSTLMap() {
	std::cout << std::endl;

	printStr("Test std::map :");
	TestMap map;
	printStr("insert: a 1");
	map.insert(TestMap::value_type("a", 1));
	printStr("push: le 2");
	map.insert(TestMap::value_type("le", 2));
	printStr("push: c 3");
	map.insert(TestMap::value_type("c", 3));
	printStr("pop: c");
	map.erase("c");
	printStr("push: x 4");
	map.insert(TestMap::value_type("x", 4));
	printStr("Print queue :");
	for (std::pair<std::string, int> str : map) {
		std::cout << str.first << str.second;
	}
	std::cout << std::endl
		<< "End test std::map." << std::endl;
};

void printStr(const std::string str) {
	std::cout << str << std::endl;
}