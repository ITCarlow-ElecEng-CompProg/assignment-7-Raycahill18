/** \ Ray Cahill
 *
 * \ 22/11/2017
 * \ Exercise 7
 * \ Coordinate Conversion
 *
 */

 /**< preprocessor directives */

#include <iostream>
#include <math.h>

using namespace std;


void Ctopolar ( float x, float y, float *ptr_rad, float *ptr_ang);
void PtoCartesian ( float rad, float ang, float *ptr_x, float *ptr_y);
char menu(void);
void pol2cart(void);
void cart2pol(void);

/**< main function */
int main()
{
    /** declare variables */
    char userinput;

    cout << "Coordinate Conversion" << endl;

    /**< A do while loop is in operation */
    do
    {
        userinput = menu();
        /** switch case to select which sub-functions operations to carry out */
        switch (userinput)
        {
            case 'p':   cart2pol();
                        break;

            case 'c':   pol2cart();
                        break;

            case 'q':   cout <<"Goodbye, Have a lovely evening"<< endl;
                        break;

            default:    cout << "Please choose correct program:"<<endl;
                        break;
        }
    }
    /**< While operation od do while loop */
    while (userinput != 'q');

    return 0;
}
/**< Cart to polar conversion function */
void Ctopolar ( float x, float y, float *ptr_rad, float *ptr_ang)
{

    *ptr_rad = sqrt(pow(x,2)+ pow(y,2));
    *ptr_ang = 180.0 * (atan2(y,x))/M_PI;

    return;
}
/**< Polar to Cart conversion function */
void PtoCartesian ( float rad, float ang, float *ptr_x, float *ptr_y)
{
    *ptr_x = rad * cos(ang);
    *ptr_y = rad * sin(ang);

    return;
}
/**< Menu function */
char menu(void)
{
    char input;

    cout << "Choose conversion\n"<<
    "p = Cartesian to Polar coordinates\n"<<
    "c = Polar to Cartesian\n"<<
    "q = quit program.\n" << endl ;
    cin >> input;

    return input;
}
/**< Sub function */
void cart2pol(void)
{
    float x =0, y=0, ang =0, rad =0;
    float *ptr_ang, *ptr_rad;

    ptr_ang = &ang;
    ptr_rad = &rad;

    cout << "Enter a valuie for x and y"<<endl;
    cin >> x >> y ;
    Ctopolar ( x, y, ptr_rad,ptr_ang);
    cout << "\nThe Magnitude of the angle is: " << *ptr_rad<< endl;
    cout << "The angle is:"<< *ptr_ang<< endl;

    return;
}
/**< Sub function */
void pol2cart(void)
{
    float x =0, y=0, ang =0, rad =0;
    float *ptr_x, *ptr_y;

    ptr_x = &x;
    ptr_y = &y;

    cout << "Enter the magnitude for R:"<<endl;
    cin >> rad;
    cout << "Enter the angle:"<<endl;
    cin >> ang;
    PtoCartesian (rad, ang*M_PI/180 ,ptr_x, ptr_y);
    cout <<"The x coOdinate is :"<< *ptr_x<< endl;
    cout << "The y coOrdinate is:" << *ptr_y << endl;

    return;
}
