#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include "WinTxt.h"
#include "Jeu.h"
using namespace std;


void afficherTxt(WinTxt & win, Jeu & jeu) {
	Terrain* ter = jeu.getTerrain();
	Joueur* joueur = jeu.getJoueur();
	ListeObstacles* obstacle = jeu.getObstacle();

	win.clear();

	for(int x=0;x<ter->getDimX();++x)
		for(int y=1;y<ter->getDimY();++y)
			win.print(x,y,ter->getXY(x,y));

    // affichage du joueur
    for (int i=0; i<joueur->taille->getLargeur(); ++i)
        for (int j=0; j<joueur->taille->getHauteur(); ++j)
            win.print(joueur->pos->getX()+i,joueur->pos->getY()+j,'O');

//    // affichage des obstacles
//    for (int i=0; i<obstacle.taille->getLargeur(); ++i)
//        for (int j=0; j<obstacle.taille->getHauteur(); ++j)
//            win.print(obstacle.pos->getX()+i,obstacle.pos->getY()+j,'x');

    for(int x=0;x<ter->getDimX();++x)
        win.print(x,0,ter->getXY(x,0));

	win.draw();

//    cout << "collision = " << jeu.collision() << endl;
}

void boucleTxt (Jeu & jeu) {
	// fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTxt win (jeu.getTerrain()->getDimX(),jeu.getTerrain()->getDimY());

	bool ok = true;
	int c;

	do {
	    afficherTxt(win,jeu);

        #ifdef _WIN32
        Sleep(150);
		#else
		usleep(150000);
        #endif // WIN32

  //      jeu.actionAutomatique();

		c = win.getCh();
		switch (c) {
			case 'h':
				jeu.actionClavier('h');
				do {
                    afficherTxt(win,jeu);
 //                   jeu.actionAutomatique();

                    #ifdef _WIN32
                    Sleep(400);
                    #else
                    usleep(400000);
                    #endif // WIN32

                    jeu.actionClavier('b');

				} while (jeu.getJoueur()->pos->getY() + jeu.getJoueur()->taille->getHauteur()
                        < jeu.getTerrain()->getPlateforme()-1 );
				break;
			case 'q':
				ok = false;
				break;
		}

	} while (ok);

}

