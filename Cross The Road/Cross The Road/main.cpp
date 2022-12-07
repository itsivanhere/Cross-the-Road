#include<iostream>
#include"Game.h"
#include<ctime>
void main() {
	srand(time(NULL));
	Game RunningMan;
	while (RunningMan.isRunning()) {
		RunningMan.update();
		RunningMan.render();
	}
}