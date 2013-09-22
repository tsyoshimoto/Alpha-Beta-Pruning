#include "node.h"
#include <iostream>
#include <cmath>

using namespace std;

int min_value(node , int , int );
int max_value(node, int , int );
int alpha_beta_search(node & n);
void print_skipped_nodes(node );
void display_nodes_visited(int , int );

//global variables
int a= -100000, b=100000, v, i=0, temp;
int a0_value, b1_value, b0_value, c0_value, c1_value, c2_value, c3_value;
int d0_value, d1_value, d2_value, d3_value, d4_value, d5_value, d6_value, d7_value, d8_value;

string next_node;
node child;

int main()
{	
	node a0, b0, b1, c0, c1, c2, c3, d0, d1, d2, d3, d4, d5, d6, d7, d8,
	e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14;
	
	a0.set_name("a0"); a0.set_var_observed("beta");
	b0.set_name("b0"); b0.set_var_observed("alpha");
	b1.set_name("b1"); b1.set_var_observed("alpha");
	c0.set_name("c0"); c0.set_var_observed("beta");
	c1.set_name("c1"); c1.set_var_observed("beta");
	c2.set_name("c2"); c2.set_var_observed("beta");
	c3.set_name("c3"); c3.set_var_observed("beta");
	d0.set_name("d0"); d0.set_var_observed("alpha");
	d1.set_name("d1"); d1.set_var_observed("alpha");
	d2.set_name("d2"); d2.set_var_observed("alpha");
	d3.set_name("d3"); d3.set_var_observed("alpha");
	d4.set_name("d4"); d4.set_var_observed("alpha");
	d5.set_name("d5"); d5.set_var_observed("alpha");
	d6.set_name("d6"); d6.set_var_observed("alpha");
	d7.set_name("d7"); d7.set_var_observed("alpha");
	d8.set_name("d8"); d8.set_var_observed("alpha");
	e0.set_name("e0"); e0.set_var_observed("beta");
	e1.set_name("e1"); e1.set_var_observed("beta");
	e2.set_name("e2"); e2.set_var_observed("beta");
	e3.set_name("e3"); e3.set_var_observed("beta");
	e4.set_name("e4"); e4.set_var_observed("beta");
	e5.set_name("e5"); e5.set_var_observed("beta");
	e6.set_name("e6"); e6.set_var_observed("beta");
	e7.set_name("e7"); e7.set_var_observed("beta");
	e8.set_name("e8"); e8.set_var_observed("beta");
	e9.set_name("e9"); e9.set_var_observed("beta"); 
	e10.set_name("e10"); e10.set_var_observed("beta");
	e11.set_name("e11"); e11.set_var_observed("beta");
	e12.set_name("e12"); e12.set_var_observed("beta");
	e13.set_name("e13"); e13.set_var_observed("beta");
	e14.set_name("e14"); e14.set_var_observed("beta");
	
	
	e0.set_value(-1); e0.set_terminal(true);
	e1.set_value(2); e1.set_terminal(true);
	e2.set_value(3); e2.set_terminal(true);
	e3.set_value(-5); e3.set_terminal(true);
	e4.set_value(0); e4.set_terminal(true);
	e5.set_value(4); e5.set_terminal(true);
	e6.set_value(7); e6.set_terminal(true);
	e7.set_value(2); e7.set_terminal(true);
	e8.set_value(6); e8.set_terminal(true);
	e9.set_value(9); e9.set_terminal(true);
	e10.set_value(8); e10.set_terminal(true);
	e11.set_value(1); e11.set_terminal(true);
	e12.set_value(4); e12.set_terminal(true);
	e13.set_value(0); e13.set_terminal(true);
	e14.set_value(5); e14.set_terminal(true);
	
	
	d0.children.push_back(e0); 
	d1.children.push_back(e3); d1.children.push_back(e2); d1.children.push_back(e1);
	d2.children.push_back(e4);
	d3.children.push_back(e6); d3.children.push_back(e5);
	d4.children.push_back(e8); d4.children.push_back(e7);
	d5.children.push_back(e10); d5.children.push_back(e9);
	d6.children.push_back(e11);
	d7.children.push_back(e12);
	d8.children.push_back(e14); d8.children.push_back(e13);
	c0.children.push_back(d2); c0.children.push_back(d1); c0.children.push_back(d0); 
	c1.children.push_back(d4); c1.children.push_back(d3);
	c2.children.push_back(d6); c2.children.push_back(d5);
	c3.children.push_back(d8); c3.children.push_back(d7);
	b0.children.push_back(c1); b0.children.push_back(c0); 
	b1.children.push_back(c3); b1.children.push_back(c2);
	a0.children.push_back(b1); a0.children.push_back(b0);
	
	
	//start of the alpha-beta search recursively
	
	cout<<endl;
	int value_a = alpha_beta_search(a0);
	cout<<"Expansions completed"<<endl<<endl;
	cout<<"Value of Max Node A = "<<value_a<<endl<<endl;
	
	if(b0_value == value_a)
	{
		next_node = "b0";
	}
	else if(b1_value == value_a)
	{
		next_node = "b1";
	}
	cout<<"Move that Max Node A would make is = "<<next_node<<endl<<endl;	
	return 0;
}



	int alpha_beta_search(node &starting_node)
	{
		v = max_value(starting_node, a, b);
		return v;	
	}

	int max_value(node current_node, int alpha, int beta)
	{
		if (current_node.get_terminal() == true)
		{
			return current_node.get_value();
		}
		
		i=0;
		v = -100000; //arbitrary number to represent negative infinity
		while(!current_node.children.empty())
		{
			if(i==0)
				cout<<"Expanding Max Node "<<current_node.get_name();
			else
				cout<<"Updating Max Node  "<<current_node.get_name();
			display_nodes_visited(alpha, beta);
			
			child = current_node.children.back();
			
			v = min_value(child, alpha, beta);
			if(v >= beta)
			{
				cout<<"Updating Max Node  "<<current_node.get_name();
				if(current_node.get_name() == "a0")
				{
					temp = a0_value;
				}
				else if(current_node.get_name() == "c0")
				{
					temp = c0_value;
				}
				else if(current_node.get_name() == "c1")
				{
					temp = c1_value;
				}
				else if(current_node.get_name() == "c2")
				{
					temp = c2_value;
				}
				else if(current_node.get_name() == "c3")
				{
					temp = c3_value;
				}
				display_nodes_visited(temp, beta);
				
				current_node.children.pop_back();
				while(!current_node.children.empty())
				{
					print_skipped_nodes(current_node.children.back());
					current_node.children.pop_back();
				}
				return alpha;
			}
			if(v > alpha)
			{
				alpha = v;
			}
			
			current_node.children.pop_back();
			
			if(current_node.children.empty())
			{
				cout<<"Updating Max Node  "<<current_node.get_name();
				display_nodes_visited(alpha, beta);
				if(current_node.get_name() == "a0")
				{
					a0_value=alpha;
				}
				else if(current_node.get_name() == "c0")
				{
					c0_value=alpha;
				}
				else if(current_node.get_name() == "c1")
				{
					c1_value=alpha;
				}
				else if(current_node.get_name() == "c2")
				{
					c2_value=alpha;
				}
				else if(current_node.get_name() == "c3")
				{
					c3_value=alpha;
				}
			}
			i++;
		}	
		return alpha;
	}

	int min_value(node current_node, int alpha, int beta)
	{
		if (current_node.get_terminal() == true)
		{
			return current_node.get_value();
		}
		
		i=0;
		v = 100000; //arbitrary number to represent +infinity
		//vector holding the pointers to the children are not empty
		while(!current_node.children.empty())
		{
			if (i==0)
				cout<<"Expanding Min Node "<<current_node.get_name();
			else
				cout<<"Updating Min Node  "<<current_node.get_name();
			display_nodes_visited(alpha, beta);
			
			child = current_node.children.back();
			
			v = max_value(child, alpha, beta);
			if (v <= alpha)
			{
				cout<<"Updating Min Node  "<<current_node.get_name();
				if(current_node.get_name() == "b0")
				{
					temp=b0_value;
				}
				else if(current_node.get_name() == "b1")
				{
					temp=b1_value;
				}
				else if(current_node.get_name() == "d0")
				{
					temp=d0_value;
				}
				else if(current_node.get_name() == "d1")
				{
					temp=d1_value;
				}
				else if(current_node.get_name() == "d2")
				{
					temp=d2_value;
				}
				else if(current_node.get_name() == "d3")
				{
					temp=d3_value;
				}
				else if(current_node.get_name() == "d4")
				{
					temp=d4_value;
				}
				else if(current_node.get_name() == "d5")
				{
					temp=d5_value;
				}
				else if(current_node.get_name() == "d6")
				{
					temp=d6_value;
				}
				else if(current_node.get_name() == "d7")
				{
					temp=d7_value;
				}
				else if(current_node.get_name() == "d8")
				{
					temp=d8_value;
				}
				display_nodes_visited(alpha, temp);
				
				current_node.children.pop_back();
				while(!current_node.children.empty())
				{
					print_skipped_nodes(current_node.children.back());
					current_node.children.pop_back();
					
				}
				return alpha;
			}
			if (v < beta)
			{
				beta = v;
			}
			
			current_node.children.pop_back();
			
			if(current_node.children.empty())
			{
				cout<<"Updating Min Node  "<<current_node.get_name();
				display_nodes_visited(alpha, beta);
				if(current_node.get_name() == "b0")
				{
					b0_value=beta;
				}
				else if(current_node.get_name() == "b1")
				{
					b1_value=beta;
				}
				else if(current_node.get_name() == "d0")
				{
					d0_value=beta;
				}
				else if(current_node.get_name() == "d1")
				{
					d1_value=beta;
				}
				else if(current_node.get_name() == "d2")
				{
					d2_value=beta;
				}
				else if(current_node.get_name() == "d3")
				{
					d3_value=beta;
				}
				else if(current_node.get_name() == "d4")
				{
					d4_value=beta;
				}
				else if(current_node.get_name() == "d5")
				{
					d5_value=beta;
				}
				else if(current_node.get_name() == "d6")
				{
					d6_value=beta;
				}
				else if(current_node.get_name() == "d7")
				{
					d7_value=beta;
				}
				else if(current_node.get_name() == "d8")
				{
					d8_value=beta;
				}
		
				
			}
			i++;
		}
		return beta;
	}

void print_skipped_nodes(node skipped_node)
{
	cout<<"Skipping expansion of Node "<<skipped_node.get_name();
	cout<<" because it cannot make "<<skipped_node.get_var_observed();
	if(skipped_node.get_var_observed() == "alpha")
	{
		cout<<" higher"<<endl;
	}
	else
	{
		cout<<" lower"<<endl;
	}
} 

void display_nodes_visited(int a, int b)
{
	
		if (a == -100000)
		{
			cout<<": alpha=negative infinity";
		}
		else
		{
			cout<< ": alpha=" <<a<<" ";
		}
		if (b == 100000)
		{
			cout<<" Beta=positive infinity"<<endl;
		}
		else
		{
			cout<< " Beta=" <<b<<endl;
		}
}
