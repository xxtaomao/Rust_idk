#pragma once
#include <algorithm>
#include <array>
#include <vector>
#include <cmath>
#include <limits>
#include <numeric>
#undef max
#undef min

namespace geo
{
	class vector2
	{
	public:
		vector2( )
		{
			x = y = 0.f;
		}
		vector2( float fx, float fy )
		{
			x = fx;
			y = fy;
		}

		float x, y;

		vector2 operator+( const vector2& input ) const
		{
			return vector2{ x + input.x, y + input.y };
		}
		vector2 operator-( const vector2& input ) const
		{
			return vector2{ x - input.x, y - input.y };
		}
		vector2 operator/( float input ) const
		{
			return vector2{ x / input, y / input };
		}
		vector2 operator*( float input ) const
		{
			return vector2{ x * input, y * input };
		}
		vector2& operator-=( const vector2& v )
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}
		vector2& operator/=( float input )
		{
			x /= input;
			y /= input;
			return *this;
		}
		vector2& operator*=( float input )
		{
			x *= input;
			y *= input;
			return *this;
		}

		float length( ) const
		{
			return std::sqrt( ( x * x ) + ( y * y ) );
		}

		vector2 normalized( ) const
		{
			return { x / length( ), y / length( ) };
		}

		float dot_product( vector2 input ) const
		{
			return ( x * input.x ) + ( y * input.y );
		}

		float distance( vector2 input ) const
		{
			return ( *this - input ).length( );
		}

		bool empty( ) const
		{
			return x == 0.f && y == 0.f;
		}
	};

	class vector3
	{
	public:
		vector3( )
		{
			x = y = z = 0.f;
		}
		vector3( float fx, float fy, float fz )
		{
			x = fx;
			y = fy;
			z = fz;
		}

		float x, y, z;

		vector3 operator+( const vector3& input ) const
		{
			return vector3{ x + input.x, y + input.y, z + input.z };
		}
		vector3 operator-( const vector3& input ) const
		{
			return vector3{ x - input.x, y - input.y, z - input.z };
		}
		vector3 operator/( float input ) const
		{
			return vector3{ x / input, y / input, z / input };
		}
		vector3 operator*( float input ) const
		{
			return vector3{ x * input, y * input, z * input };
		}
		vector3& operator-=( const vector3& v )
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;

			return *this;
		}
		vector3& operator/=( float input )
		{
			x /= input;
			y /= input;
			z /= input;
			return *this;
		}
		vector3& operator*=( float input )
		{
			x *= input;
			y *= input;
			z *= input;
			return *this;
		}
		bool operator==( const vector3& input ) const
		{
			return x == input.x && y == input.y && z == input.z;
		}

		float length_sqr( ) const
		{
			return ( x * x ) + ( y * y ) + ( z * z );
		}

		float length( ) const
		{
			return std::sqrt( length_sqr( ) );
		}

		float length_2d( ) const
		{
			return std::sqrt( ( x * x ) + ( y * y ) );
		}

		vector3 normalized( ) const
		{
			return { x / length( ), y / length( ), z / length( ) };
		}

		float dot_product( vector3 input ) const
		{
			return ( x * input.x ) + ( y * input.y ) + ( z * input.z );
		}

		float distance( vector3 input ) const
		{
			return ( *this - input ).length( );
		}

		float distance_2d( vector3 input ) const
		{
			return ( *this - input ).length_2d( );
		}

		void clamp( )
		{
			std::clamp( x, -89.f, 89.f );
			std::clamp( y, -180.f, 180.f );

			if ( y < -360.f ) y += 360.f;
			else if ( y > 360.f ) y -= 360.f;

			z = 0.f;
		}

		bool empty( ) const
		{
			return x == 0.f && y == 0.f && z == 0.f;
		}

		bool empty_euler( ) const
		{
			return x == 0.f || y == 0.f;
		}
	};

	class color3
	{
	public:
		color3( )
		{
			r = g = b = 0;
		}
		color3( int ir, int ig, int ib )
		{
			r = ir;
			g = ig;
			b = ib;

			std::clamp( r, 0, 255 );
			std::clamp( g, 0, 255 );
			std::clamp( b, 0, 255 );
		}

		int r, g, b;
	};

	class vector4
	{
	public:
		vector4( ) { x = y = z = w = 0.f; }
		vector4( float fx, float fy, float fz, float fw )
		{
			x = fx;
			y = fy;
			z = fz;
			w = fw;
		}

		float x, y, z, w;
	};
	class matrix
	{
	public:
		inline float* operator[](int i)
		{
			return m[i];
		}

		inline const float* operator[](int i) const
		{
			return m[i];
		}

		inline float* Base()
		{
			return &m[0][0];
		}

		inline const float* Base() const
		{
			return &m[0][0];
		}
	public:

		inline matrix()
		{
		}

		inline matrix(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33)
		{
			Init(
				m00, m01, m02, m03,
				m10, m11, m12, m13,
				m20, m21, m22, m23,
				m30, m31, m32, m33
			);
		}

		inline void Init(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33
		)
		{
			m[0][0] = m00;
			m[0][1] = m01;
			m[0][2] = m02;
			m[0][3] = m03;

			m[1][0] = m10;
			m[1][1] = m11;
			m[1][2] = m12;
			m[1][3] = m13;

			m[2][0] = m20;
			m[2][1] = m21;
			m[2][2] = m22;
			m[2][3] = m23;

			m[3][0] = m30;
			m[3][1] = m31;
			m[3][2] = m32;
			m[3][3] = m33;
		}

		matrix transpose() const
		{
			return matrix(
				m[0][0], m[1][0], m[2][0], m[3][0],
				m[0][1], m[1][1], m[2][1], m[3][1],
				m[0][2], m[1][2], m[2][2], m[3][2],
				m[0][3], m[1][3], m[2][3], m[3][3]);
		}

		float m[4][4];
	};
	using vec2_t = vector2;
	using col3_t = color3;
	using vec3_t = vector3;
	using vec4_t = vector4;
	using mat4x4_t = matrix;
}