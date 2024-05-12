#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

class Action
{
public:
	virtual void execute() = 0;
};

class CreateAction :public Action
{
public:
void execute() override
	{
		cout << "CreateFile" << endl;
	}
};

class ExitAction :public Action
{
public:
	void execute() override
	{
		cout << "Exit" << endl;
	}
};

class MenuItem
{
	string text;
	Action* action;
public:
	MenuItem(string text, Action* action)
		:text(text), action(action)
	{}
	MenuItem(string text)
		:text(text), action(nullptr)
	{}
	void print()
	{cout << text << endl;
		
	}
	void clicked()
	{
		cout << "clicked" << endl;
		if(action!= nullptr)
			action->execute();
	}
};

class Menu : public MenuItem
{
	vector <MenuItem*> menuitems;
	string text;

public:
	void add(MenuItem* m)
	{
		menuitems.push_back(m);
	}
	void print()
	{
		cout<< text << endl;
		for (MenuItem* m : menuitems)
		{
			m->print();
		}
	

	}
};

class MenuBar
{
	vector <Menu*> menues;
public:
	void add(Menu* m)
	{
		menues.push_back(m);
	}
	void print()
	{
		for(Menu* m : menues)
		{
			m->print();
		}
	}
	
};

int main()
{
	Menu* file = new Menu("File");
	file->add(new MenuItem("New", new CreateAction()));
	file->add(new MenuItem("Open"));
	file->add(new MenuItem("Save"));
	file->add(new MenuItem("Exit", new ExitAction()));
	Menu* edit = new Menu();
	edit->add(new MenuItem("Copy"));
	edit->add(new MenuItem("Paste"));
	edit->add(new MenuItem("Cut"));
	Menu* help = new Menu();
	help->add(new MenuItem("About"));
	MenuBar* menubar = new MenuBar();
	menubar->add(file);
	menubar->add(edit);
	menubar->add(help);
	menubar->print();
	return 0;
	


}