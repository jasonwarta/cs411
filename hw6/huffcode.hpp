// huffcode.hpp
// Jason Warta
// 2017 November 27
// 
// CS 411 
// Homework 6

#ifndef FILE_HUFFCODE_H_INCLUDED
#define FILE_HUFFCODE_H_INCLUDED

#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <queue>
using std::priority_queue;
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

using Weights = unordered_map<char, int>;

struct Node {
	Node() {}
	Node(char ch, int wgt) : m_char(ch), m_weight(wgt) {}
	Node(const shared_ptr<Node> & lhs, const shared_ptr<Node> & rhs, int weight) : 
		m_leftNode(lhs),
		m_rightNode(rhs),
		m_char(0),
		m_weight(weight)
	{}

	bool null();

	shared_ptr<Node> m_leftNode = nullptr, m_rightNode = nullptr;
	char m_char = 0;
	int m_weight = 0;
};

struct Compare {
	bool operator() (const Node & lhs, const Node & rhs);
};

// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    // Compiler-generated default ctor, copy ctor, copy =, dctor used

// ***** HuffCode: general public functions *****
public:

    void setWeights(const unordered_map<char, int> & theWeights);

    string encode(const string & text) const;

    string decode(const string & codestr) const;

    void map(Node & node, string code);

// ***** HuffCode: data members *****
private:
	Node m_root;
	unordered_map<char, string> m_char_to_string;
	unordered_map<string, char> m_string_to_char;
};  // End class HuffCode

#endif //#ifndef FILE_HUFFCODE_H_INCLUDED

