//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 800

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 20

// lives
#define LIVES 3

// height and width of paddle
#define PADDLE_HEIGHT 10
#define PADDLE_WIDTH 40

// space from bottom of paddle
#define SPACE 30

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // initial velocity
    double velocity_x = 1 * drand48();
    double velocity_y = 3 ;
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // Controll Paddle
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard mouse event
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows cursor
                double x = getX(event) - getWidth(paddle) / 2;
                double y = getHeight(window) - SPACE - PADDLE_HEIGHT;
                setLocation(paddle, x, y);
            }
        }
       
        // Bounce the ball of walls
        // move ball 
        move(ball, velocity_x, velocity_y);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            velocity_x = -velocity_x;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            velocity_x = -velocity_x;
        }
        
        // bounce off top edge of window
        else if (getY(ball) <= 0)
        {
            velocity_y = -velocity_y;
        }
        
        // Lose a life when at the bottom of window
        else if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            // lose a life
            lives = lives - 1;
            // move ball to default position 
            
            double x = getWidth(window) / 2 -  RADIUS / 2;
            double y = getHeight(window) / 2 - RADIUS / 2;
            setLocation(ball, x, y);
            // wait for click before continuing
            waitForClick();     
        }
            
        // linger before moving again
        pause(10);
        
        // check for collision of a ball and store the collided object to  "object"
        GObject object = detectCollision(window, ball);
        
        // Bounce the ball of paddle and bricks
        if(object != NULL)
        {
            if (strcmp(getType(object), "GRect") == 0)
            {    
                if (object == paddle && velocity_y > 0 && getY(ball) + getHeight(ball) <= getY(paddle) )
                {
                    velocity_y = -velocity_y; 
                } 
                else if (object != paddle && velocity_y < 0) 
                {
                    velocity_y = -velocity_y; 
                }      
                
                // remove brick from a grid when hit
                else if (object != paddle)
                {  
                    removeGWindow(window, object);
                    
                    // Increase score score
                    points = points + 1;
                    
                    // Change labels score
                    updateScoreboard(window, label, points);
                }
            }        
        } 
        // Winning game
        if (bricks == points)
        {
            // Show text YOU WON    
            GLabel win = newGLabel("YOU WON");
            double x = getWidth(window) / 2 - getWidth(win);
            double y = getHeight(window) / 2 - getHeight(win);
            setLocation(win, x, y);
            setFont(win, "SansSerif-40");
            removeGWindow(window, label);
            add(window, win);
            // wait for click before exiting
            waitForClick();
            closeGWindow(window);
            return 0;
        }     
    }

    // game over
    if (lives == 0)
    {
        closeGWindow(window);
        return 0;
    }
    
    return 1;
   
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            double x = 3 +  WIDTH / COLS * j;
            double y = i * 15 + HEIGHT / 10;
            GRect brick = newGRect(x, y, WIDTH / COLS - 6, PADDLE_HEIGHT);
            setFilled(brick, true);
            if(i == 0)
            {
                setColor(brick, "RED");
            } 
            else if(i == 1)
            {
                setColor(brick, "GREEN");
            }
            else if(i == 2)
            {
                setColor(brick, "BLUE");
            }
            else if(i == 3)
            {
                setColor(brick, "YELLOW");
            }
            else
            {
                setColor(brick, "CYAN");
            }
            add(window, brick);
        }
    }
    

}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    double x = getWidth(window) / 2 -  RADIUS / 2;
    double y = getHeight(window) / 2 - RADIUS / 2;
    GOval ball = newGOval(x, y,  RADIUS,  RADIUS);
    setFilled(ball, true);
    setColor(ball, "BLACK");
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    double x = getWidth(window) / 2 - PADDLE_WIDTH / 2;
    double y = getHeight(window) - SPACE - PADDLE_HEIGHT;
    GRect paddle = newGRect(x, y, PADDLE_WIDTH, PADDLE_HEIGHT);
    setFilled(paddle, true);
    setColor(paddle, "RED");
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{

    GLabel label = newGLabel("0");
    double x = getWidth(window) / 2 - getWidth(label);
    double y = getHeight(window) / 2 - getHeight(label);
    setLocation(label, x, y);
    setFont(label, "SansSerif-40");
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
