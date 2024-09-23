// Tu nombre
// Animación básica usando ncurses

#include <ncurses.h>
#include <unistd.h>
#include <cmath>
#include <ctime>
using namespace std;

// Función que dibuja un rectángulo de color usando el caracter c con esquina superior
// izquierda en startRow y startCol y dimensiones height y width

void draw_rectangle(int startRow, int startCol, int height, int width, int color, char c)
{
    attron(COLOR_PAIR(color));
    for (int i = startRow; i <= startRow + height; i++)
        mvhline(i, startCol, c, width); // Top line
    attroff(COLOR_PAIR(color));
}

// Función para inicializar los colores que se pueden usar a través del programa
void initColors(){
    init_color(COLOR_RED, 1000, 0, 0);  
    init_color(COLOR_BLUE, 0, 0, 1000); 
    init_color(COLOR_GREEN, 0, 1000, 0);  
    init_pair(1, COLOR_RED, COLOR_YELLOW); 
    init_pair(2, COLOR_GREEN, COLOR_BLUE); 
    init_pair(3, COLOR_BLUE, COLOR_GREEN); 
    init_pair(4, COLOR_YELLOW, COLOR_RED); 
}

// Función que devuelve true si val está entre a y b

bool isBetween(int a, int b, int val) {
    if (a > b) {int tmp = a; a = b; b = tmp;}
    return (val >= a && val <= b);
}

// Función que dibuja una linea desde x0,y0 hasta x1,y1

void draw_line(int x0, int y0, int x1, int y1, int color, char c)
{
    int deltax = x1 - x0;
    int deltay = y1 - y0;

    attron(COLOR_PAIR(color));
    if (deltax == 0) mvvline( y0 < y1 ? y0:y1, x1, c, abs(deltay));
    else if (deltay == 0) mvhline(  y1, x0 < x1 ? x0:x1, c, abs(deltax));
    else {
        float m = (static_cast<float>(y1)-y0)/ (x1-x0);
        int ctr = 0;
        int firstX = x0 < x1 ? x0 : x1;
        int lastX = x0 < x1 ? x1 : x0;
        int firstY = x0 < x1 ? y0 : y1;
        int lastY = x0 > x1 ? y0 : y1;
        

        for(int x = firstX; x <= lastX; x = x + 1) {
            int tmpY = round(firstY + (x-firstX)*m);
            if (isBetween(y0, y1, tmpY)) {
                mvvline(tmpY, x, c, 1);
            }
        }

        firstY = y0 < y1 ? y0 : y1;
        lastY = y0 < y1 ? y1 : y0;
        firstX = y0 < y1 ? x0 : x1;
        lastX = y0 < y1 ? x1 : x0;

        for(int y = firstY; y <= lastY; y =y + 1) {
            int tmpX = round(firstX + (y-firstY)* (1/m));
            if (isBetween(x0, x1, tmpX)) {
                mvvline(y, tmpX, c, 1);
            }
        }
    }
    attroff(COLOR_PAIR(color));
}


// Función que dibuja un triangulo con los vértices en x0,y0, x1,y1, x2,y2.

void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, int color, char c) {
    draw_line(x0, y0, x1, y1, color, c);
    draw_line(x1, y1, x2, y2, color, c);
    draw_line(x2, y2, x0, y0, color, c);
}

// Función que devuelve el mínimo de dos enteros

int min(int a, int b) { return a < b ? a : b;}

// Función que devuelve el máximo de dos enteros

int max(int a, int b) { return a > b ? a : b;}


int main()
{
    srand(time(NULL));
    initscr();     // Initialize the ncurses library
    start_color();
    initColors();

    curs_set(0);
    // Enable keypad input and non-blocking input
    keypad(stdscr, TRUE);



    int rectWidth = 9;
    int rectHeight = 3;
    
    int x = COLS/2;
    int y = LINES/2;

    // init to a random number in the range [-3,3] but not 0
    int dx = 2;
    int dy = 1;


    while (1)
    {
        clear();

        draw_rectangle(y, x, rectHeight, rectWidth,1, 'X');

        x += dx;
        y += dy;
        
        refresh();
        usleep(20000);
        
        // getch();
    }
    
    getch();  // Wait for a user input to exit
    endwin(); // End ncurses mode and clean up

    return 0;
}
