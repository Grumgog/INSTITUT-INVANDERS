#include "helping.h"
void getOpengGlSizeWindow(double& minx, double& maxx, double &miny, double &maxy, double w, double h, double ort)
{
    minx = 0;
    miny = h;
    maxx = w;
    maxy = 0;

    minx = (minx-w/2)/(w/2);
    miny = (-miny+h/2)/(h/2);

    maxx = (maxx-w/2)/(w/2);
    maxy = (-maxy+h/2)/(h/2);

    if(w<=h)
    {
        minx*=ort+ort*(w/h);
        miny*=ort;

        maxx*=ort+ort*(w/h);
        maxy*=ort;
    }
    else
    {
        miny*=ort+ort*(h/w);
        minx*=ort;

        maxy*=ort+ort*(h/w);
        maxx*=ort;
    }
}
