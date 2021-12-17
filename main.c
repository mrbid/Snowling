/*
    James William Fletcher (james@voxdsp.com)
        December 2021

    A simple bowling game with a festive twist.

    Niggles:
        Speaking English I know how to spell Colour,
        however, I also recognise Color is less to type.
        So I use Colour and Color interchangeably.
        I use Color in var names that will be typed a lot,
        such as in low level code, and I use Colour in
        higher level code where it will be typed less.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define uint unsigned int
#define f32 GLfloat

#include "gl.h"
#define GLFW_INCLUDE_NONE
#include "glfw3.h"

#define NOSSE
#define SEIR_RAND
#include "esAux2.h"

#include "res.h"
#include "scene.h"
#include "dynamic.h"
#include "minball.h"


//*************************************
// globals
//*************************************
GLFWwindow* window;
uint winw = 1024;
uint winh = 768;
double t = 0;
f32 aspect;
f32 sens = 0.3f;
f32 sens_mul = 0.2f;
double ww, wh, ww2, wh2;
double uw, uh, uw2, uh2; // normalised pixel dpi

// render state id's
GLint projection_id;
GLint modelview_id;
GLint position_id;
GLint lightpos_id;
GLint solidcolor_id;
GLint color_id;
GLint opacity_id;
GLint normal_id;
GLint type_id;
GLint texcoord_id;
GLint sampler_id;

// render state matrices
mat projection;
mat view;
mat model;
mat modelview;

// render state inputs
vec lightpos = {0.f, 7.f, 0.f};

// models
ESModel mdlPlane;
    GLuint tex_skyplane;
ESModel mdlScene;
ESModel mdlDynamic;
ESModel mdlMinball;
uint bindstate = 0;

// simulation / game vars
uint ground = 0;        // current round number
uint score = 0;         // total score
uint rscore = 0;        // round score
uint penalty = 0;       // penalty count
uint state = 0;         // game state
double s0lt = 0;        // time offset controls ball swing offset
vec bp;                 // ball position
f32 stepspeed = 0.f;    // ball speed
f32 hardness = 0.f;     // ball hardness


//*************************************
// utility functions
//*************************************
void timestamp(char* ts)
{
    const time_t tt = time(0);
    strftime(ts, 16, "%H:%M:%S", localtime(&tt));
}

//*************************************
// generation functions
//*************************************
void blotColour2(f32 r, f32 g, f32 b, f32 rad)
{
    const GLushort rci = esRand(0, dynamic_numvert-1) * 3;
    const vec tv = (vec){dynamic_vertices[rci], dynamic_vertices[rci+1], dynamic_vertices[rci+2]};

    if(tv.x > 9.6f) // not too close to spawn
        return;

    const GLushort tc = (dynamic_numvert-1)*3;
    for(GLushort i = 0; i < tc; i += 3)
    {
        const vec nv = (vec){dynamic_vertices[i], dynamic_vertices[i+1], dynamic_vertices[i+2]};
        if(vDist(tv, nv) < rad)
        {
            dynamic_colors[i] = r;
            dynamic_colors[i+1] = g;
            dynamic_colors[i+2] = b;
        }
    }
}

void blotColour(f32 r, f32 g, f32 b, GLushort streak)
{
    const GLushort rci = esRand(0, (dynamic_numvert-1)-streak) * 3;
    for(GLushort i = 0; i < streak; i++)
    {
        dynamic_colors[rci+(i*3)] = r;
        dynamic_colors[rci+(i*3)+1] = g;
        dynamic_colors[rci+(i*3)+2] = b;
    }
}

void gNewRound()
{
    // count & log
    ground++;
    char strts[16];
    timestamp(&strts[0]);
    printf("[%s] STARTING ROUND %u - SCORE %u - PENALTY %u\n", strts, ground, score, penalty);
    if(ground > 1)
    {
        char title[256];
        sprintf(title, "Snowling - ROUND %u - SCORE %u - PENALTY %u", ground, score, penalty);
        glfwSetWindowTitle(window, title);
    }

    // reset
    const GLushort tc = dynamic_numvert*3;
    for(GLushort i = 0; i < tc; i++)
        dynamic_colors[i] = 1.f;

    // ice
    for(uint i = 0; i < 6; i++)
    {
        if(esRand(0, 1000) < 500)
            blotColour(0.f, 1.f, 1.f, 32);
        else
            blotColour2(0.f, 1.f, 1.f, esRandFloat(0.1f, 0.9f));
    }

    // boost
    for(uint i = 0; i < 6; i++)
    {
        if(esRand(0, 1000) < 500)
            blotColour(0.50196f, 0.00000f, 0.50196f, 6);
        else
            blotColour2(0.50196f, 0.00000f, 0.50196f, esRandFloat(0.1f, 0.3f));
    }

    // lava
    for(uint i = 0; i < 2; i++)
    {
        if(esRand(0, 1000) < 500)
            blotColour(0.81176f, 0.06275f, 0.12549f, 6);
        else
            blotColour2(0.81176f, 0.06275f, 0.12549f, esRandFloat(0.1f, 0.3f));
    }

    // rebind
    esBind(GL_ARRAY_BUFFER, &mdlDynamic.cid, dynamic_colors, sizeof(dynamic_colors), GL_STATIC_DRAW);
}

uint checkCollisions()
{
    static double ccl = 0;
    if(t < ccl)
        return 0;
    else
        ccl = t + 0.05; // limit checkCollisions() execution frequency

    static double tt1 = 0, tt2 = 0, tt3 = 0;
    static const GLushort tc = (dynamic_numvert-1)*3;
    for(GLushort i = 0; i < tc; i+=3)
    {
        if(t > tt1 && dynamic_colors[i] == 0.f && dynamic_colors[i+1] == 1.f && dynamic_colors[i+2] == 1.f)
        {
            const vec cp = {dynamic_vertices[i], dynamic_vertices[i+1], dynamic_vertices[i+2]};
            if(vDist(cp, bp) < 0.13f)
            {
                hardness += 1.f;
                char strts[16];
                timestamp(&strts[0]);
                printf("[%s] hit ice: %u\n", strts, (uint)hardness);
                tt1 = t+0.3; // freq limiter
                return 1;
            }
        }
        else if(t > tt2 && dynamic_colors[i] == 0.50196f && dynamic_colors[i+1] == 0.f && dynamic_colors[i+2] == 0.50196f)
        {
            const vec cp = {dynamic_vertices[i], dynamic_vertices[i+1], dynamic_vertices[i+2]};
            if(vDist(cp, bp) < 0.13f)
            {
                stepspeed *= 3.4f;
                char strts[16];
                timestamp(&strts[0]);
                printf("[%s] hit boost: %.1f\n", strts, stepspeed);
                tt2 = t+0.3; // freq limiter
                return 2;
            }
        }
        else if(t > tt3 && dynamic_colors[i] == 0.81176f && dynamic_colors[i+1] == 0.06275f && dynamic_colors[i+2] == 0.12549f)
        {
            const vec cp = {dynamic_vertices[i], dynamic_vertices[i+1], dynamic_vertices[i+2]};
            if(vDist(cp, bp) < 0.13f)
            {
                penalty++;
                char strts[16];
                timestamp(&strts[0]);
                printf("[%s] hit lava: %u\n", strts, penalty);
                printf("[%s] ~~ PENALTY YOU GOT MELTED BY LAVA ~~\n", strts);
                tt3 = t+0.3; // freq limiter
                return 3;
            }
        }
    }
    
    return 0;
}

//*************************************
// render functions
//*************************************
void rSkyPlane()
{
    bindstate = 0;

    static mat skyplane_model = {0.f};
    static f32 la = 0;
    if(skyplane_model.m[0][0] == 0.f || la != aspect)
    {
        mIdent(&skyplane_model);
        mTranslate(&skyplane_model, -40.f, 0.f, 0.f);
        mRotY(&skyplane_model, -90.f*DEG2RAD);
        mRotX(&skyplane_model, -90.f*DEG2RAD);
        mScale(&skyplane_model, 40.f*aspect, 23.f*aspect, 0);
        la = aspect;
    }

    mMul(&modelview, &skyplane_model, &view);

    glUniformMatrix4fv(projection_id, 1, GL_FALSE, (f32*)&projection.m[0][0]);
    glUniformMatrix4fv(modelview_id, 1, GL_FALSE, (f32*)&modelview.m[0][0]);

    glBindBuffer(GL_ARRAY_BUFFER, mdlPlane.tid);
    glVertexAttribPointer(texcoord_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(texcoord_id);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex_skyplane);
    glUniform1i(sampler_id, 0);

    glBindBuffer(GL_ARRAY_BUFFER, mdlPlane.vid);
    glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(position_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mdlPlane.iid);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}

void rStaticScene()
{
    bindstate = 0;

    glUniformMatrix4fv(projection_id, 1, GL_FALSE, (f32*) &projection.m[0][0]);
    glUniformMatrix4fv(modelview_id, 1, GL_FALSE, (f32*) &view.m[0][0]);
    glUniform3f(lightpos_id, lightpos.x, lightpos.y, lightpos.z);
    glUniform1f(opacity_id, 1.0f);

    glBindBuffer(GL_ARRAY_BUFFER, mdlScene.vid);
    glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(position_id);

    glBindBuffer(GL_ARRAY_BUFFER, mdlScene.nid);
    glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(normal_id);

    glBindBuffer(GL_ARRAY_BUFFER, mdlScene.cid);
    glVertexAttribPointer(color_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(color_id);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mdlScene.iid);

    glDrawElements(GL_TRIANGLES, scene_numind, GL_UNSIGNED_SHORT, 0);
}

void rDynamicScene()
{
    bindstate = 0;

    glUniformMatrix4fv(projection_id, 1, GL_FALSE, (f32*) &projection.m[0][0]);
    glUniformMatrix4fv(modelview_id, 1, GL_FALSE, (f32*) &view.m[0][0]);
    glUniform3f(lightpos_id, lightpos.x, lightpos.y, lightpos.z);
    glUniform1f(opacity_id, 1.0f);

    glBindBuffer(GL_ARRAY_BUFFER, mdlDynamic.vid);
    glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(position_id);

    glBindBuffer(GL_ARRAY_BUFFER, mdlDynamic.nid);
    glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(normal_id);

    glBindBuffer(GL_ARRAY_BUFFER, mdlDynamic.cid);
    glVertexAttribPointer(color_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(color_id);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mdlDynamic.iid);

    glDrawElements(GL_TRIANGLES, dynamic_numind, GL_UNSIGNED_SHORT, 0);
}

void rMinballRGB(f32 x, f32 y, f32 z, f32 r, f32 g, f32 b, f32 s)
{
    mIdent(&model);
    mTranslate(&model, x, y, z);
    if(s != 1.f)
        mScale(&model, s, s, s);
    mMul(&modelview, &model, &view);

    glUniformMatrix4fv(projection_id, 1, GL_FALSE, (f32*) &projection.m[0][0]);
    glUniformMatrix4fv(modelview_id, 1, GL_FALSE, (f32*) &modelview.m[0][0]);
    glUniform3f(color_id, r, g, b);
    glUniform3f(lightpos_id, lightpos.x, lightpos.y, lightpos.z);
    glUniform1f(opacity_id, 1.0f);

    if(bindstate == 0)
    {
        glBindBuffer(GL_ARRAY_BUFFER, mdlMinball.vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mdlMinball.iid);
        bindstate = 1;
    }

    glDrawElements(GL_TRIANGLES, minball_numind, GL_UNSIGNED_SHORT, 0);
}

static inline void rMinball(f32 x, f32 y, f32 z, f32 s)
{
    rMinballRGB(x, y, z, 1.f, 1.f, 1.f, s);
}

void rPin(f32 x, f32 y, f32 z, uint down)
{
    if(down == 1)
    {
        rMinballRGB(x, y, z, 1.f, 0.f, 0.f, 2.2f);
    }
    else
    {
        rMinball(x, y, z, 2.2f);
        rMinball(x, y, z+0.14f, 1.45f);
        rMinball(x, y, z+0.24f, 0.9f);
    }
}

void rPinSet()
{
    rPin(-0.9, 0.f, 0.f, rscore >= 1 ? 1 : 0);

    rPin(-1.2, -0.14f, 0.f, rscore >= 2 ? 1 : 0);
    rPin(-1.2, 0.14f, 0.f, rscore >= 3 ? 1 : 0);

    rPin(-1.5, 0.f, 0.f, rscore >= 4 ? 1 : 0);
    rPin(-1.5, -0.28f, 0.f, rscore >= 5 ? 1 : 0);
    rPin(-1.5, 0.28f, 0.f, rscore >= 6 ? 1 : 0);

    rPin(-1.8, -0.14f, 0.f, rscore >= 7 ? 1 : 0);
    rPin(-1.8, 0.14f, 0.f, rscore >= 8 ? 1 : 0);
    rPin(-1.8, -0.42f, 0.f, rscore >= 9 ? 1 : 0);
    rPin(-1.8, 0.42f, 0.f, rscore >= 10 ? 1 : 0);
}

//*************************************
// interpolators and steppers for simulation
//*************************************
typedef struct { f32 y,z; } lt;
static inline f32 lerp(lt* a, lt* b, f32 y)
{
    return a->z + (((y - a->y) / (b->y - a->y)) * (b->z - a->z));
}

f32 getHeight(f32 y)
{
    static lt hlt[25];

    if(hlt[0].z == 0.f)
    {
        hlt[0].y = 0;         hlt[0].z = 0.016813;
        hlt[1].y = 0.102108;  hlt[1].z = 0.018762;
        hlt[2].y = 0.191487;  hlt[2].z = 0.024604;
        hlt[3].y = 0.280097;  hlt[3].z = 0.034311;
        hlt[4].y = 0.367561;  hlt[4].z = 0.047843;
        hlt[5].y = 0.453504;  hlt[5].z = 0.065142;
        hlt[6].y = 0.537558;  hlt[6].z = 0.086133;
        hlt[7].y = 0.619362;  hlt[7].z = 0.110728;
        hlt[8].y = 0.698569;  hlt[8].z = 0.138821;
        hlt[9].y = 0.774836;  hlt[9].z = 0.170289;
        hlt[10].y = 0.847838; hlt[10].z = 0.205001;
        hlt[11].y = 0.917262; hlt[11].z = 0.242807;
        hlt[12].y = 0.982812; hlt[12].z = 0.283543;
        hlt[13].y = 1.04421;  hlt[13].z = 0.327039;
        hlt[14].y = 1.10118;  hlt[14].z = 0.373106;
        hlt[15].y = 1.15349;  hlt[15].z = 0.421545;
        hlt[16].y = 1.20092;  hlt[16].z = 0.472152;
        hlt[17].y = 1.24325;  hlt[17].z = 0.524709;
        hlt[18].y = 1.28032;  hlt[18].z = 0.57899;
        hlt[19].y = 1.31195;  hlt[19].z = 0.634764;
        hlt[20].y = 1.33803;  hlt[20].z = 0.69179;
        hlt[21].y = 1.35843;  hlt[21].z = 0.749827;
        hlt[22].y = 1.37305;  hlt[22].z = 0.808624;
        hlt[23].y = 1.38185;  hlt[23].z = 0.867931;
        hlt[24].y = 1.38479;  hlt[24].z = 0.927491;
    }

    y = fabs(y);

    for(uint i = 0; i < 24; i++)
        if(y >= hlt[i].y && y < hlt[i+1].y)
            return lerp(&hlt[i], &hlt[i+1], y);

    return -1.f; // bad times if this happens
}

static inline f32 smoothStepN(f32 v)
{
    return v * v * (3.f - 2.f * v);
}


//*************************************
// update & render
//*************************************
void main_loop()
{
//*************************************
// time delta for interpolation
//*************************************
    static double lt = 0;
    double dt = t-lt;
    lt = t;

//*************************************
// camera control
//*************************************
    static f32 camdist = -15.f;
    mIdent(&view);
    mTranslate(&view, 0.f, -0.5f, camdist);
    mRotate(&view, 80 * DEG2RAD, 1.f, 0.f, 0.f);
    mRotate(&view, 90 * DEG2RAD, 0.f, 0.f, 1.f);

//*************************************
// joystick control
//*************************************
    if(glfwJoystickPresent(GLFW_JOYSTICK_1) == 1 && stepspeed == 0.f)
    {
        int count;
        const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &count);
        if(count >= 2)
        {
            static float bt = 0;
            if(t > bt)
            {
                const unsigned char* buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &count);
                if(count >= 2)
                {
                    if(buttons[0] == GLFW_PRESS)
                    {
                        stepspeed = 0.5f + (((axes[1]*-1.f)+1.f)*0.5f)*4.5f;

                        if(axes[0] < -0.75f)
                            s0lt = t - 3.769911289f;
                        else if(axes[0] > 0.75f)
                            s0lt = t - 0.6283185482f;
                        if(axes[0] < 0.f)
                            s0lt = t - PI;
                        else if(axes[0] >= 0.f)
                            s0lt = t;

                        printf("a: %f\n", axes[0]);
                        bt = t + 0.3f;
                    }
                    else if(buttons[1] == GLFW_PRESS)
                    {
                        s0lt = t - randf()*x2PI;
                        stepspeed = 0.5f + (((axes[1]*-1.f)+1.f)*0.5f)*4.5f;
                        bt = t + 0.3f;
                    }
                }
            }
        }
    }

//*************************************
// begin render
//*************************************
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//*************************************
// main render
//*************************************

    // render sky plane
    shadeFullbrightT(&position_id, &projection_id, &modelview_id, &texcoord_id, &sampler_id);
    rSkyPlane();

    // render static and dynamic scenes
    shadeLambert3(&position_id, &projection_id, &modelview_id, &lightpos_id, &normal_id, &color_id, &opacity_id);
    rStaticScene();
    rDynamicScene();

    // only rendering icospheres from here on out
    shadeLambert(&position_id, &projection_id, &modelview_id, &lightpos_id, &color_id, &opacity_id);
    rPinSet();

    // simulate the blowing snowball & transition the game states
    static double s1lt = 0;
    static f32 x = 10.5f; 

    if(state == 0)
    {
        if(stepspeed == 0.f)
        {
            rMinball(10.5f, 0.f-0.017f, 0.f, 1.f);
        }
        else
        {
            const f32 ddt = stepspeed * dt;
            x -= ddt;
            camdist += ddt;
            if(x <= -1.f)
                state = 1;

            const f32 h = sin(t-s0lt)*(1.38f-((10.5f-x)*0.1f));

            f32 ns = (10.5f-x)*0.4f;
            if(ns < 1.f)
                ns = 1.f;

            lightpos.y = 7.f * smoothStepN(x*0.09523809701f);

            bp.x = x;
            bp.y = h-0.017f;
            bp.z = getHeight(h);
            rMinballRGB(bp.x, bp.y, bp.z, 1.f-(hardness*0.22f), 1.f, 1.f, ns);

            if(checkCollisions() == 3)
                state = 2;
        }
    }
    else if(state == 1)
    {
        if(s1lt == 0)
        {
            // calc score
            if(hardness > 0.f)
            {
                const f32 fscore = ((hardness * stepspeed) * 0.3f)+0.5f;
                rscore = (uint)fscore;
                if(rscore == 0)
                {
                    char strts[16];
                    timestamp(&strts[0]);
                    printf("[%s] ~~ PENALTY YOU FAILED TO KNOCK DOWN ANY PINS ~~\n", strts);
                    penalty++;
                }
                else if(rscore >= 10)
                {
                    rscore = 20;
                    char strts[16];
                    timestamp(&strts[0]);
                    printf("[%s] !!! STRIKE !!! - ROUND %u - SCORE %u\n", strts, ground, rscore);
                }
                else
                {
                    char strts[16];
                    timestamp(&strts[0]);
                    printf("[%s] ~~ ROUND %u SCORE %u ~~\n", strts, ground, rscore);
                }
                score += rscore;
            }
            else
            {
                char strts[16];
                timestamp(&strts[0]);
                printf("[%s] ~~ PENALTY YOU FAILED TO KNOCK DOWN ANY PINS ~~\n", strts);
                penalty++;
            }

            // pause time between rounds
            s1lt = t + 3;
        }
        if(t > s1lt)
            state = 2;
    }
    else if(state == 2)
    {
        // reset
        lightpos.y = 7.f;
        x = 10.5f;
        camdist = -15.f;
        stepspeed = 0.f;
        hardness = 0.f;
        state = 0;
        s1lt = 0;
        rscore = 0;
        gNewRound();
    }

//*************************************
// swap buffers / display render
//*************************************
    glfwSwapBuffers(window);
}

//*************************************
// Input Handelling
//*************************************
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    static uint tab = 0;
    static f32 ls = 3.f;

    // debug reset
    //if(key == GLFW_KEY_SPACE){state = 2;}

    // speed selector
    if((key == GLFW_KEY_TAB || key == GLFW_KEY_SPACE) && action == GLFW_PRESS)
        tab = 1;
    else if((key == GLFW_KEY_TAB || key == GLFW_KEY_SPACE) && action == GLFW_RELEASE)
        tab = 0;

    if(tab == 1)
    {
        if(key == GLFW_KEY_1)
            ls = 0.5f;
        else if(key == GLFW_KEY_2)
            ls = 1.0f;
        else if(key == GLFW_KEY_3)
            ls = 1.5f;
        else if(key == GLFW_KEY_4)
            ls = 2.0f;
        else if(key == GLFW_KEY_5)
            ls = 2.5f;
        else if(key == GLFW_KEY_6)
            ls = 3.0f;
        else if(key == GLFW_KEY_7)
            ls = 3.5f;
        else if(key == GLFW_KEY_8)
            ls = 4.0f;
        else if(key == GLFW_KEY_9)
            ls = 4.5f;
        else if(key == GLFW_KEY_0)
            ls = 5.0f;
        
        static f32 lls = 0.f;
        if(lls != ls)
        {
            char strts[16];
            timestamp(&strts[0]);
            printf("[%s] Launch Speed: %.1f\n", strts, ls);
            lls = ls;
        }
    }

    // launchers
    if(stepspeed == 0.f && tab == 0)
    {
        // center
        if(key == GLFW_KEY_5){ stepspeed = ls; s0lt = t - PI; }
        if(key == GLFW_KEY_6){ stepspeed = ls; s0lt = t; }

        // inner
        if(key == GLFW_KEY_4){ stepspeed = ls; s0lt = t - (0.6283185482f * 4.0f); }
        if(key == GLFW_KEY_7){ stepspeed = ls; s0lt = t - (0.6283185482f * 9.0f); }

        // just off center
        if(key == GLFW_KEY_3){ stepspeed = ls; s0lt = t - (0.6283185482f * 6.0f); }
        if(key == GLFW_KEY_8){ stepspeed = ls; s0lt = t - 0.6283185482f; }

        // wide center
        if(key == GLFW_KEY_2){ stepspeed = ls; s0lt = t - (0.6283185482f * 7.0f); }
        if(key == GLFW_KEY_9){ stepspeed = ls; s0lt = t - (0.6283185482f * 2.0f); }

        // super wide
        if(key == GLFW_KEY_1){ stepspeed = ls; s0lt = t - (0.6283185482f * 8.0f); }
        if(key == GLFW_KEY_0){ stepspeed = ls; s0lt = t - (0.6283185482f * 3.0f); }

        // simple
        if(key == GLFW_KEY_LEFT) { stepspeed = 1.5f; s0lt = t - 3.3f; }
        if(key == GLFW_KEY_RIGHT){ stepspeed = 1.5f; s0lt = t - 6.4f; }
        if(key == GLFW_KEY_UP)   { stepspeed = 4.5f; s0lt = t - 9.9f; }
        if(key == GLFW_KEY_DOWN) { stepspeed = 4.5f; s0lt = t; }

        // random
        if(key == GLFW_KEY_R) 
        {
            stepspeed = 0.5f + randf()*6.f; // 1.5f higher possible speed with random
            s0lt = t - randf()*x2PI;
        }
    }

    // quit
    if(key == GLFW_KEY_ESCAPE)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
    winw = width;
    winh = height;

    glViewport(0, 0, winw, winh);
    aspect = (f32)winw / (f32)winh;
    ww = winw;
    wh = winh;
    ww2 = ww/2;
    wh2 = wh/2;
    uw = (double)aspect / ww;
    uh = 1 / wh;
    uw2 = (double)aspect / ww2;
    uh2 = 1 / wh2;

    mIdent(&projection);
    mPerspective(&projection, 60.0f, aspect, 1.0f, 160.0f); 
}

//*************************************
// Process Entry Point
//*************************************
int main(int argc, char** argv)
{
    // help
    printf("Snowling, A simple bowling game with a festive twist.\n");
    printf("James William Fletcher (james@voxdsp.com)\n\n");
    printf("The premise is simple; you must launch the snowball at the pins and knock them down, seems easy right? Well, your snowball wont knock any pins down unless you roll over some ice first to harden it up. There are three obstacles in the game:\n\n");
    printf("Ice (color: Aqua)\n - Hardens your snowball to pack a heavier punch on the pins.\n\n");
    printf("Boost (color: Purple)\n - Increases the speed of your snowball to blow a heavier punch on the pins.\n\n");
    printf("Lava (color: Red)\n - Melts your snowball; instant penalty.\n\n");
    printf("Joypad Bindings:\n");
    printf(" - [Stick 1 - Left to Right] Launch Angle\n");
    printf(" - [Stick 1 - Up and Down] Launch Speed\n");
    printf(" - [Button 1] Launch\n");
    printf(" - [Button 2] Random Launch\n\n");
    printf("Key Bindings:\n");
    printf(" - [TAB/SPACE + 0-9] Select launch speed.\n");
    printf(" - [0-9] Launch ball at one of 10 different angles, 5-1 for left hand launches and 6-0 for right hand launches.\n");
    printf(" - [R] Launch ball at a random angle and speed.\n");
    printf(" - [Left, Right, Up, Down] Launch ball at four quick selection angles and speeds.\n\n");
    printf("I tend to just use [UP, DOWN, LEFT, RIGHT] and [R] when I play, but if you are competitive you will want to get accustomed with using [TAB + 0-9] & [0-9].\n\n");

    // init glfw
    if(!glfwInit()){exit(EXIT_FAILURE);}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_SAMPLES, 16);
    window = glfwCreateWindow(winw, winh, "Snowling", NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    const GLFWvidmode* desktop = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window, (desktop->width/2)-(winw/2), (desktop->height/2)-(winh/2)); // center window on desktop
    glfwSetWindowSizeCallback(window, window_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1); // 0 for immediate updates, 1 for updates synchronized with the vertical retrace, -1 for adaptive vsync

    // set icon
    unsigned char* ipd = (unsigned char*)&icon_image2.pixel_data;
    srand(time(0));
    const uint r = esRand(0, 2);
    if(r == 0)      {ipd = (unsigned char*)&icon_image.pixel_data;}
    else if(r == 1) {ipd = (unsigned char*)&icon_image1.pixel_data;}
    else            {ipd = (unsigned char*)&icon_image2.pixel_data;}
    glfwSetWindowIcon(window, 1, &(GLFWimage){16, 16, ipd});

    // seed random
    srandf(time(0));

//*************************************
// projection
//*************************************

    window_size_callback(window, winw, winh);

//*************************************
// bind vertex and index buffers
//*************************************

    // ***** BIND SKY PLANE *****
    f32  plane_vert[] = {1.000000,-1.000000,0.000000,-1.000000,1.000000,0.000000,-1.000000,-1.000000,0.000000,1.000000,1.000000,0.000000};
    GLushort plane_indi[] = {0,1,2,0,3,1};
    esBindModel(&mdlPlane, plane_vert, 9, plane_indi, 6);
    f32 plane_texc[] = {1.f,1.f, 0.f,0.f, 0.f,1.f, 1.f,0.f};
    esBind(GL_ARRAY_BUFFER, &mdlPlane.tid, plane_texc, sizeof(plane_texc), GL_STATIC_DRAW);
    tex_skyplane = esLoadTexture(alpinebg.width, alpinebg.height, &alpinebg.pixel_data[0]);

    // ***** BIND STATIC SCENE *****
    esBind(GL_ARRAY_BUFFER, &mdlScene.vid, scene_vertices, sizeof(scene_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &mdlScene.nid, scene_normals, sizeof(scene_normals), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &mdlScene.cid, scene_colors, sizeof(scene_colors), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &mdlScene.iid, scene_indices, sizeof(scene_indices), GL_STATIC_DRAW);

    // ***** BIND DYNAMIC SCENE *****
    esBind(GL_ARRAY_BUFFER, &mdlDynamic.vid, dynamic_vertices, sizeof(dynamic_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &mdlDynamic.nid, dynamic_normals, sizeof(dynamic_normals), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &mdlDynamic.cid, dynamic_colors, sizeof(dynamic_colors), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &mdlDynamic.iid, dynamic_indices, sizeof(dynamic_indices), GL_STATIC_DRAW);

    // ***** BIND MIN BALL *****
    esBind(GL_ARRAY_BUFFER, &mdlMinball.vid, minball_vertices, sizeof(minball_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &mdlMinball.iid, minball_indices, sizeof(minball_indices), GL_STATIC_DRAW);


//*************************************
// compile & link shader program
//*************************************

    // makeAllShaders();
    makeLambert();
    makeLambert3();
    makeFullbrightT();

//*************************************
// configure render options
//*************************************

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 0.0);

//*************************************
// execute update / render loop
//*************************************

    // new round
    gNewRound();

    // reset
    t = glfwGetTime();

    // event loop
    while(!glfwWindowShouldClose(window))
    {
        t = glfwGetTime();
        glfwPollEvents();
        main_loop();
    }

    // done
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
