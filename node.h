#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class node
{
	private:
		int value;
		bool terminal;
		string name, variable_look_at;
		
	public:
		node();
		//node(string id);
		//~node();
		int get_value();
		void set_value(int v);
		bool get_terminal();
		void set_terminal(bool t);
 		string get_name();
 		void set_name(string id);
 		void set_var_observed(string o);
 		string get_var_observed();
 
		vector<node> children;
		
		//node * left;
		//node * middle;
		//node * right;
};

#endif

node::node()
{
	value = 0;
	terminal = false;
}
/*
node::node(string id)
{
	value = 0;
	terminal = false;
	name = id;
}
/*
node::~node()
{
	delete left;
	delete right;
	delete middle;
}
*/
int node::get_value()
{
	return value;
}
void node::set_value(int v)
{
	value = v;
}
bool node::get_terminal()
{
	return terminal;
}
void node::set_terminal(bool t)
{
	terminal = t;
}
string node::get_name()
{
	return name;
}
void node::set_name(string id)
{
	name = id;
}
void node::set_var_observed(string o)
{
	variable_look_at = o;
}
string node::get_var_observed()
{
	return variable_look_at;
}
