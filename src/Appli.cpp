#include "Window.h"

int main(void) {
    srand(time(NULL));

    Window win("Circles and Rectangles", 800, 600);

    win.display();

    return 0;
}
