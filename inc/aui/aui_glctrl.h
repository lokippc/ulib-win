#ifndef U_AUI_GL_CTRL_H
#define U_AUI_GL_CTRL_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "ubasewindow.h"
#include "uglut.h"

#include "adt/uautoptr.h"

#define  UAUIGLCTRL_CLASSNAME "UAUI_UGLCTRL_{7BD1020E-02CB-4a7c-BADD-C1FFBD33299A}"

namespace AUI
{


class UGLCtrl :  public UBaseWindow
{
    enum {
        ID_TIMER_INTERNAL = 22
    };
public:
    UGLCtrl(UBaseWindow *pWndParent)
    : UBaseWindow(pWndParent)
    {
        setMenu(0);
        setWndClassName(_T(UAUIGLCTRL_CLASSNAME));
        setTitle(_T("DOCK"));

        addStyles(WS_CHILD);
        setExStyles(WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_APPWINDOW);

        m_uInterval = 100;
    }

    ~UGLCtrl()
    {
        this->killTimer(ID_TIMER_INTERNAL);
    }

    BOOL onPreRegisterWindowClass(huys::UWindowClass &uwc)
    {
        uwc.setStyles(CS_OWNDC);
        return FALSE;
    }

    BOOL onCreate()
    {
        UGlut::EnableOpenGL(*this, m_hdc, m_hrc);

        this->setTimer(ID_TIMER_INTERNAL, m_uInterval);

        return UBaseWindow::onCreate();
    }

    BOOL onClose()
    {
        this->hide();
        return FALSE;
    }

    void onDraw(HDC hdc)
    {
        render();
        SwapBuffers(m_hdc);
    }

    BOOL onDestroy()
    {
        UGlut::DisableOpenGL(getHandle(), m_hdc, m_hrc);

        return UBaseWindow::onDestroy();
    }

    //
    void setInterval(UINT uInterval)
    {
        m_uInterval = uInterval;
    }

    BOOL onSize(WPARAM wParam, LPARAM lParam)
    {
        ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));
        return FALSE;
    }


    BOOL onTimer(WPARAM wParam, LPARAM lParam)
    {
        switch (wParam)
        {
        case ID_TIMER_INTERNAL:
            {
                render();
                // Swap buffers
                SwapBuffers(m_hdc);

                return TRUE;
            }
        default:
            return FALSE;
        }
    }
private:
    HDC m_hdc;
    HGLRC m_hrc;
    UINT m_uInterval;

    void ReSizeGLScene(GLsizei width, GLsizei height)        // Resize And Initialize The GL Window
    {
        if (height==0)                                        // Prevent A Divide By Zero By
        {
            height=1;                                        // Making Height Equal One
        }

        glViewport(0,0,width,height);                        // Reset The Current Viewport

        glMatrixMode(GL_PROJECTION);                        // Select The Projection Matrix
        glLoadIdentity();                                    // Reset The Projection Matrix

        // Calculate The Aspect Ratio Of The Window
        gluPerspective(.0f,(GLfloat)width/(GLfloat)height,0.5f,10.0f);

        glMatrixMode(GL_MODELVIEW);                            // Select The Modelview Matrix
        glLoadIdentity();                                    // Reset The Modelview Matrix
    }

    void render()
    {
        //glViewport(0, 0, 640.0, 480.0);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //glScalef(0.5,0.5,0.5);
        glRotatef(2.0,0,0,1);
        //
        glBegin(GL_LINES);

        //
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.9f, 0.1f, 0.0f);
        glVertex3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.9f, -0.1f, 0.0f);

        //
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.1f, 0.9f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-0.1f, 0.9f, 0.0f);

        //
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.1f, 0.9f);
        glVertex3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, -0.1f, 0.9f);

        //
        glEnd();

        //
        glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(1.0f, 0.5f);
        glVertex2f(1.0f, 1.0f);
        glEnd();

        //cnt1+=(cnt1>10?.0f:0.05f);
    }
};

typedef huys::ADT::UAutoPtr<UGLCtrl> UGLCtrlP;

}; // namespace AUI

#endif // U_AUI_GL_CTRL_H