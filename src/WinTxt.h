#ifndef ENDLESSRUNNER_WINTXT_H
#define ENDLESSRUNNER_WINTXT_H

//! \brief une fenêtre texte est un tableau 2D de caractères
class WinTxt {

private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief hauteur
    char* win;      //!< \brief stocke le contenu de la fenêtre dans un tableau 1D mais on y accede en 2D

public:

    WinTxt(int dx, int dy);
    ~WinTxt();
    void clear (char c=' ');
    void print (int x, int y, char c);
    void print (int x, int y, char* c);
    void draw();
    void pause();
    char getCh();

};

void termClear ();

#endif  //ENDLESSRUNNER_WINTXT_H

