// Author: wjdwndud0114, Kevin Jeong
// Crappy code and crappy commenting written a long time ago :/
#include "Drawings.h"
/*
int DrawString(char* String, int x, int y, int r, int g, int b, ID3DXFont* ifont)
{
	RECT ShadowPos;
	ShadowPos.left = x + 1;
	ShadowPos.top = y + 1;
	RECT FontPos;
	FontPos.left = x;
	FontPos.top = y;
	ifont->DrawTextA(0, String, strlen(String), &ShadowPos, DT_NOCLIP, D3DCOLOR_ARGB(255, r / 3, g / 3, b / 3));
	ifont->DrawTextA(0, String, strlen(String), &FontPos, DT_NOCLIP, D3DCOLOR_ARGB(255, r, g, b));
	return 0;
}*/



int DrawShadowString(char* String, int x, int y, int r, int g, int b, ID3DXFont* ifont)
{
	RECT Font;
	Font.left = x;
	Font.top = y;
	RECT Fonts;
	Fonts.left = x + 1;
	Fonts.top = y;
	RECT Fonts1;
	Fonts1.left = x - 1;
	Fonts1.top = y;
	RECT Fonts2;
	Fonts2.left = x;
	Fonts2.top = y + 1;
	RECT Fonts3;
	Fonts3.left = x;
	Fonts3.top = y - 1;
	ifont->DrawTextA(0, String, strlen(String), &Fonts3, DT_NOCLIP, D3DCOLOR_ARGB(255, 1, 1, 1));
	ifont->DrawTextA(0, String, strlen(String), &Fonts2, DT_NOCLIP, D3DCOLOR_ARGB(255, 1, 1, 1));
	ifont->DrawTextA(0, String, strlen(String), &Fonts1, DT_NOCLIP, D3DCOLOR_ARGB(255, 1, 1, 1));
	ifont->DrawTextA(0, String, strlen(String), &Fonts, DT_NOCLIP, D3DCOLOR_ARGB(255, 1, 1, 1));
	ifont->DrawTextA(0, String, strlen(String), &Font, DT_NOCLIP, D3DCOLOR_ARGB(255, r, g, b));
	return 0;
}

/*
void GradientFunc(int x, int y, int w, int h, int r, int g, int b, int a)
{
	int iColorr, iColorg, iColorb;
	for (int i = 1; i < h; i++)
	{
		iColorr = (int)((float)i / h*r);
		iColorg = (int)((float)i / h*g);
		iColorb = (int)((float)i / h*b);
		FillRGB(x, y + i, w, 1, r - iColorr, g - iColorg, b - iColorb, a);
	}
}*/
void DrawLine(float x, float y, float xx, float yy, int r, int g, int b, int a)
{
	D3DXVECTOR2 dLine[2];

	p_Line->SetWidth(1);

	dLine[0].x = x;
	dLine[0].y = y;

	dLine[1].x = xx;
	dLine[1].y = yy;

	p_Line->Draw(dLine, 2, D3DCOLOR_ARGB(a, r, g, b));

}
void FillRGB(float x, float y, float w, float h, int r, int g, int b, int a)
{
	D3DXVECTOR2 vLine[2];

	p_Line->SetWidth(w);

	vLine[0].x = x + w / 2;
	vLine[0].y = y;
	vLine[1].x = x + w / 2;
	vLine[1].y = y + h;

	p_Line->Begin();
	p_Line->Draw(vLine, 2, D3DCOLOR_RGBA(r, g, b, a));
	p_Line->End();
}
void DrawBox(float x, float y, float width, float height, float px, int r, int g, int b, int a)
{
	D3DXVECTOR2 points[5];
	points[0] = D3DXVECTOR2(x, y);
	points[1] = D3DXVECTOR2(x + width, y);
	points[2] = D3DXVECTOR2(x + width, y + height);
	points[3] = D3DXVECTOR2(x, y + height);
	points[4] = D3DXVECTOR2(x, y);
	p_Line->SetWidth(1);
	p_Line->Draw(points, 5, D3DCOLOR_RGBA(r, g, b, a));
}
#define PI 3.14159265
void Circle(int X, int Y, int radius, int numSides, int r, int g, int b, int a)
{
	D3DXVECTOR2 Line[128];
	float Step = PI * 2.0 / numSides;
	int Count = 0;
	for (float a = 0; a < PI*2.0; a += Step)
	{
		float X1 = radius * cos(a) + X;
		float Y1 = radius * sin(a) + Y;
		float X2 = radius * cos(a + Step) + X;
		float Y2 = radius * sin(a + Step) + Y;
		Line[Count].x = X1;
		Line[Count].y = Y1;
		Line[Count + 1].x = X2;
		Line[Count + 1].y = Y2;
		Count += 2;
	}
	p_Line->Begin();
	p_Line->Draw(Line, Count, D3DCOLOR_ARGB(a, r, g, b));
	p_Line->End();
}
/*
void DrawGUIBox(float x, float y, float w, float h, int r, int g, int b, int a, int rr, int gg, int bb, int aa)
{
	DrawBox(x, y, w, h, 1, r, g, b, a);
	FillRGB(x, y, w, h, rr, gg, bb, a);
}
void DrawHealthBar(float x, float y, float w, float h, int r, int g)
{
	FillRGB(x, y, w, h, r, g, 0, 255);
}
void DrawHealthBarBack(float x, float y, float w, float h)
{
	FillRGB(x, y, w, h, 0, 0, 0, 255);
}
void DrawCenterLine(float x, float y, int width, int r, int g, int b)
{
	D3DXVECTOR2 dPoints[2];
	dPoints[0] = D3DXVECTOR2(x, y);
	dPoints[1] = D3DXVECTOR2(Width / 2, Height);
	p_Line->SetWidth(width);
	p_Line->Draw(dPoints, 2, D3DCOLOR_RGBA(r, g, b, 255));
}
*/