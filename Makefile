CCX=g++ -g -Wall

all: mainGraph mainTest

mainGraph: mainGraph.o Forme2D.o GraphicJoueur.o GraphicMenu.o GraphicObjet.o GraphicObstacle.o Graphics.o GraphicTerrain.o Jeu.o JeuTxt.o Joueur.o ListeObjet.o ListeObstacles.o Objet.o Obstacle.o Pos2D.o Terrain.o
	g++ -g -o ./bin/mainGraph mainGraph.o Forme2D.o GraphicJoueur.o GraphicMenu.o GraphicObjet.o GraphicObstacle.o Graphics.o GraphicTerrain.o Jeu.o JeuTxt.o Joueur.o ListeObjet.o ListeObstacles.o Objet.o Obstacle.o Pos2D.o Terrain.o

mainTest: mainTest.o Forme2D.o GraphicJoueur.o GraphicMenu.o GraphicObjet.o GraphicObstacle.o Graphics.o GraphicTerrain.o Jeu.o JeuTxt.o Joueur.o ListeObjet.o ListeObstacles.o Objet.o Obstacle.o Pos2D.o Terrain.o
	g++ -g -Wall -o ./bin/mainTest mainTest.o Forme2D.o GraphicJoueur.o GraphicMenu.o GraphicObjet.o GraphicObstacle.o Graphics.o GraphicTerrain.o Jeu.o JeuTxt.o Joueur.o ListeObjet.o ListeObstacles.o Objet.o Obstacle.o Pos2D.o Terrain.o

mainGraph.o: mainGraph.cpp 
	g++ -g -Wall -c mainGraph.cpp -o ./obj/mainGraph.o

mainTest.o: mainTest.cpp 
	g++ -g -Wall -c mainTest.cpp -o ./obj/mainTest.o

Forme2D.o: ./src/Forme2D.cpp ./src/Forme2D.h
	g++ -g -Wall -c ./src/Forme2D.cpp -o ./obj/Forme2D.o

GraphicJoueur.o: ./src/GraphicJoueur.cpp ./src/GraphicJoueur.h
	g++ -g -Wall -c ./src/GraphicJoueur.cpp -o ./obj/GraphicJoueur.o

GraphicMenu.o: ./src/GraphicMenu.cpp ./src/GraphicMenu.h
	g++ -g -Wall -c ./src/GraphicMenu.cpp -o ./obj/GraphicMenu.o

GraphicObjet.o: ./src/GraphicObjet.cpp ./src/GraphicObjet.h
	g++ -g -Wall -c ./src/GraphicObjet.cpp -o ./obj/GraphicObjet.o

GraphicObstacle.o: ./src/GraphicObstacle.cpp ./src/GraphicObstacle.h
	g++ -g -Wall -c ./src/GraphicObstacle.cpp -o ./obj/GraphicObstacle.o

Graphics.o: ./src/Graphics.cpp ./src/Graphics.h
	g++ -g -Wall -c ./src/Graphics.cpp -o ./obj/Graphics.o

GraphicTerrain.o: ./src/GraphicTerrain.cpp ./src/GraphicTerrain.h
	g++ -g -Wall -c ./src/GraphicTerrain.cpp -o ./obj/GraphicTerrain.o

Jeu.o: ./src/Jeu.cpp ./src/Jeu.h
	g++ -g -Wall -c ./src/Jeu.cpp -o ./obj/Jeu.o

JeuTxt.o: ./src/JeuTxt.cpp ./src/JeuTxt.h
	g++ -g -Wall -c ./src/JeuTxt.cpp -o ./obj/JeuTxt.o

Joueur.o: ./src/Joueur.cpp ./src/Joueur.h
	g++ -g -Wall -c ./src/Joueur.cpp -o ./obj/Joueur.o

ListeObjet.o: ./src/ListeObjet.cpp ./src/ListeObjet.h
	g++ -g -Wall -c ./src/ListeObjet.cpp -o ./obj/ListeObjet.o

ListeObstacles.o: ./src/ListeObstacles.cpp ./src/ListeObstacles.h
	g++ -g -Wall -c ./src/ListeObstacles.cpp -o ./obj/ListeObstacles.o

Objet.o: ./src/Objet.cpp ./src/Objet.h
	g++ -g -Wall -c ./src/Objet.cpp -o ./obj/Objet.o

Obstacle.o: ./src/Obstacle.cpp ./src/Obstacle.h
	g++ -g -Wall -c ./src/Obstacle.cpp -o ./obj/Obstacle.o

Pos2D.o: ./src/Pos2D.cpp ./src/Pos2D.h
	g++ -g -Wall -c ./src/Pos2D.cpp -o ./obj/Pos2D.o

Terrain.o: ./src/Terrain.cpp ./src/Terrain.h
	g++ -g -Wall -c ./src/Terrain.cpp -o ./obj/Terrain.o






clean:
	rm -r ./obj/*.o

veryclean:
	rm -r ./obj/*.o
	rm -r ./bin/*




