#include <SFML/Graphics.hpp>
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(800,600),"Bernardo Zero");
	Texture t;
	Sprite s;
	
	t.loadFromFile("sfml.png");
	s.setTexture(t);
	s.setPosition(175, 130);
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		w.clear(Color(255,255,255,255));
		w.draw(s);
		w.display();
	}
	return 0;
}

