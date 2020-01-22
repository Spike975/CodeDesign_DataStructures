#include "Singleton.h"

TestSingleton::TestSingleton(){
	states = MainMenu;
}
TestSingleton::~TestSingleton() {
}
TestSingleton::TestSingleton(TestSingleton const&){
	
}
GameState TestSingleton::getState() {
	return states;
}
void TestSingleton::setState(GameState s) {
	states = s;
}