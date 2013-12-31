#pragma once
#include <gl/GL.h>
#include "Vector2.h"

class Body {
public:
	Vector2 P;
	Vector2 V;
	Vector2 Size;

	Body(const Vector2& pos, const Vector2 &vel, const Vector2 &size) 
	{
		P = pos;
		V = vel;
		Size = size;
	}

	Body() 
	{
		P.Set(0, 0); 
		V.Set(0, 0);
		Size.Set(10, 10);
	}

	void Render() {
		glPushMatrix();
			//CT <- T * S
			glTranslatef(P.X, P.Y, 0);
			glScalef(Size.X, Size.Y, 1);
			glBegin(GL_QUADS);
				glColor3f(1, 0, 0);
				glVertex2f(-0.5f, -0.5f);
				glVertex2f(0.5f, -0.5f);
				glVertex2f(0.5f, 0.5f);
				glVertex2f(-0.5f, 0.5f);
			glEnd();
		glPopMatrix();
	}

	void Update(float dtTimeSec) {
		P += dtTimeSec * V;
	}
};
