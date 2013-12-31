#pragma once

class Vector2 {
public:
	float X;
	float Y;

	Vector2(float x, float y) {
		X = x;
		Y = y;
	}

	Vector2() {
		X = Y = 0;
	}

	friend Vector2 operator +(const Vector2 &u, const Vector2 &v);

	friend Vector2 operator *(float s, const Vector2 &u);

	Vector2& operator += (const Vector2 &u) {
		X += u.X;
		Y += u.Y;
		return *this;
	}

	void Set(float x, float y) {
		X = x; Y = y;
	}
};

inline Vector2 operator +(const Vector2 &u, const Vector2 &v) {
	return Vector2(u.X + v.X, u.Y + v.Y);
}

inline Vector2 operator *(float s, const Vector2 &u) {
	return Vector2(s*u.X, s*u.Y);
}