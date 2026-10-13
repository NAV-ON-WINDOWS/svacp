    #include <iostream>
    #include <graphcis.h>
    #include <cmath>
    using namespace std;

    class Pattern {
        public:
            // DDA line drawing alg
            void drawLine (float x1, float x2, float y1, float y2) {
                float dx = x2 - x1;
                float dy = y2 - y1;
                float steps = max(abs(dx), abs(dy));

                float xIn = dx / steps;
                float yIn = dy / steps;

                float x = x1;
                float y = y1;

                for (int i = 0; i <= steps; i++) {
                    putpixel(round(x), round(y), WHITE);
                    x += xIn; 
                    y += yIn;
                }
            }

            void plot8points(int xc, int yc, int x, int y) {
                putpixel(xc + x, yc + y, WHITE);
                putpixel(xc - x, yc + y, WHITE);
                putpixel(xc + x, yc - y, WHITE);
                putpixel(xc - x, yc - y, WHITE);
                putpixel(xc + y, yc + x, WHITE);
                putpixel(xc - y, yc + x, WHITE);
                putpixel(xc + y, yc - x, WHITE);
                putpixel(xc - y, yc - x, WHITE);
            }

            // Bresehnham's circle drawing
            void cricleDrawing(int xc, int yx, int r) {
                int x = 0;
                int y = r;
                int d = 3 - (2 * r);

                plot8points(xc, yc, x, y);

                while(x <= y) {
                    if (d < 0) {
                        d = d + (4 * x) + 6;
                    } else {
                        d = d + 4 * (x - y) + 10;
                        y--;
                    }
                    
                    x++;
                    plot8points(xc, yc, x, y);
                }
            }
    };

    int main() {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, NULL);

        Pattern P;

        // 1. Coordinates for outer rectangle.
        float x1 = 150, y1 = 100;
        float x2 = 450, y2 = 300;

        // centre and dimensions
        float xc = (x1 + x2) / 2.0;
        float yc = (y1 + y2) / 2.0;
        float w = x2 - x1;
        float h = y2 - y1;

        // 2. Outer rectangle (4 lines using DDA)
        P.drawLine(x1, x2, y1, y2);
        P.drawLine(x1, x2, y1, y2);
        P.drawLine(x1, x2, y1, y2);
        P.drawLine(x1, x2, y1, y2);

        // drawing diamond
        P.drawLine(xc, y1, x2, yc);
        P.drawLine(x2, yc, xc, y2);
        P.drawLine(xc, y2, x1, yc);
        p.drawLine(x1, yc, xc, y1);

        // 4. Calculate inscribed circle radius
        float a = w / 2.0;
        float b = h / 2.0;
        float r = round((a * b) / sqrt((a * a) + (b * b)));

        // 5. Draw circle
        P.cricleDrawing(xc, yc, r);

        getch();
        closegraph();
        return 0;
    }