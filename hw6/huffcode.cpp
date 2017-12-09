// huffcode.cpp
// Jason Warta
// 2017 November 27
// 
// CS 411 
// Homework 6

#include "huffcode.hpp"  // for class HuffCode declaration

bool Node::null() {
	return m_leftNode == nullptr && m_rightNode == nullptr && m_char == 0 && m_weight == 0;
}

void HuffCode::setWeights(const unordered_map<char, int> & theWeights)
{
	priority_queue<Node, vector<Node>, Compare> weights;

	for(auto & item : theWeights)
		weights.push( Node(item.first, item.second) );

	while(weights.size() > 1){
		Node first = weights.top();
		weights.pop();
		Node second = weights.top();
		weights.pop();

		weights.push( Node(make_shared<Node>(first),make_shared<Node>(second), first.m_weight + second.m_weight) );
	}

	if(weights.size() > 0) {
		m_root = weights.top();
	}

	map(m_root,"");
}

string HuffCode::encode(const string & text) const
{
	string code = "";

	for(int i = 0; i < text.size(); i++){
		auto result = m_char_to_string.find(text[i]);

		if(result != m_char_to_string.end())
			code += result->second;
	}

	return code;
}

string HuffCode::decode(const string & codestr) const
{
	Node node = m_root;
	auto it = codestr.begin();
	string plaintext = "";

	do {
		if((*it) == '0'){
			node = *node.m_leftNode;
			it++;
		} else if ((*it) == '1') {
			node = *node.m_rightNode;
			it++;
		}

		if( node.m_char != 0 ) {
			plaintext += node.m_char;
			node = m_root;
			continue;
		}

	} while(it != codestr.end());

	return plaintext;
}

void HuffCode::map(Node & node, string code) {
	if (node.null())
		return;

	if( node.m_char == 0 ) {
		map( *(node.m_leftNode), code + "0");
		map( *(node.m_rightNode), code + "1");
	} else {
		m_char_to_string.insert({ node.m_char, code });
		m_string_to_char.insert({ code, node.m_char });
	}
}

bool Compare::operator() (const Node & lhs, const Node & rhs){
	return lhs.m_weight > rhs.m_weight;
}