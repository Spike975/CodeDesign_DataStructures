#pragma once

#include <iostream>
#include <string>

enum GameState {
	MainMenu = 0, Begining, Quest, Final, End
};


class TestSingleton{
public:
	~TestSingleton();
	static TestSingleton& GetInstance() {
		static TestSingleton instance;
		return instance;
	}
	TestSingleton();
	TestSingleton(TestSingleton const&);
	GameState getState();
	void setState(GameState s);
private:
	GameState states = MainMenu;
	void operator=(TestSingleton const&) {}
};