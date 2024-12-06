#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) :
    QRadioButton(parent)
{
    ResID++;            // Increment of counter by one
    buttonID = ResID;   /* Assigning a button number which will be further work with buttons
                         * */
}

QDynamicButton::~QDynamicButton()
{

}

/* Method to return the value of the button numbers
 * */
int QDynamicButton::getID()
{
    return buttonID;
}

/* Initialize static class variable.
 * Static class variable must be initialized without fail
 * */
int QDynamicButton::ResID = 0;
