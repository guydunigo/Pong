// System data :
    #define DELAY_TIME 0.01

    #define NB_BALLS	1
    #define NB_STARS	100

    #define PI 3.14159

// Mass per volume :
    #define MASS_PER_VOLUME_CIRC 1
    #define MASS_PER_VOLUME_RECT 1
    #define MASS_PER_VOLUME_TRI 1

// Physics coefs
    #define G_COEF		50
    #define ACCg		9.81*G_COEF

    #define FRICT_COEF	1
    #define BOUNCE_COEF	1
    // Coef balls against rectangle
    #define B_R_BOUNCE_COEF BOUNCE_COEF
    #define RECT_BOUNCE_COEF 1

    #define CELERITY_LIM	5

// Points coefs :
    #define BAR_BONUS       10
    #define WALLS_MALUS     -10
    #define TRIG_BONUS      10

// Triangles powerups and traps :
    #define TRIG_CEL_MAL_COLOR  210,100,0
    #define TRIG_CEL_BON_COLOR  200,200,255
    #define TRIG_POINTS_MAL_COLOR     255,0,0
    #define TRIG_POINTS_BON_COLOR     0,255,0

    #define TRIG_CEL_MAL    2f
    #define TRIG_CEL_BON    .5f

    #define TRIG_POINTS_BON 50
    #define TRIG_POINTS_MAL -30

    //...