#pragma once

class Title
{
private:
	bool start;
public:
	Title();
	void draw();
	void drawStick();

	bool getStart() { return start; }
	void setStart(bool x) { start = x; }
};