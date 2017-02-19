    --- Pong 2000 ---

-------- Informations diverses --------

    Créateurs : THOMAS Robin et GONI Guillaume
    Langage : C++
    Bibliothèque utilisée : SFML

  --- Présentation ---

    C'est une version revisitée du célèbre jeu Pong.

    Le joueur contrôle la gravité appliquée sur la balle avec les touches directionnelles du clavier.
    Ce jeu consiste à gagner des points en touchant les barres et à éviter de toucher un des bords de la fenêtre.
    Il y a aussi des bonus et des malus représentés sous la forme de triangles.

-------- Partie technique --------

  Il existe, dans le dossier binaries, des versions déjà compilées pour GNU/Linux et Windows, utiliser la dernière version (1.6)

  --- Exécuter le programme sous GNU/Linux ---
    $ ./binaries/GNU_Linux/Pong_1.6_GNU_Linux
    
  --- Exécuter le programme sous Windows ---
    > .\binaries\Windows\Pong_1.6_Final.exe

 ---- Compilation ----
    Elements requis :
        - Compilateur supportant le c++11 (GCC de préférence)
        - SFML version 2.4.1 (testé)
        
  --- Compiler sous GNU/Linux ---
    $ make clean; make
    $ ./Pong

  --- Compiler sous Windows ---
    Element requis : Compilateur mingw32-gcc pour la version de la bibliothèque se trouvant dans le dossier SFML_Windows_sources

    > .\clean.bat;.\build.bat
    > .\run.bat

    NB : SFML nécessite que SFML soit compilé avec l'exacte même version du compilateur que le programme.
        Si besoin, recompiler la bibliothèque (les sources sont dans le dossier dist) (voir la documentation pour la génération du makefile avec cmake)

-------- Description du jeu --------

  --- Règles du jeu ---

    Le joueur se déplace dans le menu avec les flèches Haut et Bas et selectionne une option avec la touche Entrée.

    Le joueur contrôle la gravité appliquée sur la balle avec les touches directionnelles du clavier.
    Pour gagner des points, il faut toucher les barres qui se déplacent le long des murs mais attention,
    on ne peut pas gagner deux fois d'affilée des points sur une même barre.
    Il perd des points si il touche une des bords de la fenêtre.

    A certains moments, des bonus et des malus vont apparaître sur l'écran sous la forme de triangles de différentes couleurs.
    Ceux ci peuvent modifier votre vitesse, taille ou vos points.
    A vous de les éviter ou de les récupérer.

    Attention aux effets appliqués sur la balle à cause de sa rotation ! Vous pouvez perdre facilement le contrôle de celle-ci.

  --- Système de points ---

    Toucher une barre : 10 points
    Toucher un mur : -10 points

  --- Bonus / Malus ---

    Points :
        Toucher un triangle vert : +50 points
        Toucher un triangle rouge : -50 points
    Vitesse :
        Toucher un triangle gris : vitesse / 2
        Toucher un triangle Orange : vitesse * 2
    Taille :
        Toucher un triangle Cyan : taille / 2
        Toucher un triangle Jaune : taille * 2