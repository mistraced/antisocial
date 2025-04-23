#pragma once

#include <math.h>
#include <string>

#define SMALL_FLOAT 0.0000000001
#define PI 3.14159265358979323846264338327950288419716939937510f
#define Deg2Rad ( 2.f * PI / 360.f )
#define Rad2Deg ( 1.f / Deg2Rad )
#define M_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989380952572010654858632788659361533818279682303019520353018529689957736225994138912497217752834791315155748572424541506959508295331168617278558890750983817546374649393192550604009277016711390098488240128583616035637076601047101819429555961989467678374494482553797747268471040475346462080466842590694912933136770289891521047521620569660240580

struct quater_t;

struct vec3_t
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float data[ 3 ];
    };
    inline vec3_t( )
        : x( 0 )
        , y( 0 )
        , z( 0 ) {};
    inline vec3_t( float x, float y, float z )
        : x( x )
        , y( y )
        , z( z ) {};

    inline static vec3_t back( ) { return vec3_t( 0, 0, -1 ); }
    inline static vec3_t down( ) { return vec3_t( 0, -1, 0 ); }
    inline static vec3_t forward( ) { return vec3_t( 0, 0, 1 ); }
    inline static vec3_t left( ) { return vec3_t( -1, 0, 0 ); }
    inline static vec3_t right( ) { return vec3_t( 1, 0, 0 ); }
    inline static vec3_t up( ) { return vec3_t( 0, 1, 0 ); }
    inline static vec3_t zero( ) { return vec3_t( 0, 0, 0 ); }
    inline static vec3_t one( ) { return vec3_t( 1, 1, 1 ); }

    inline static float angle( vec3_t from, vec3_t to );
    inline static float dot( vec3_t lhs, vec3_t rhs );
    inline static vec3_t clamp_magnitude( vec3_t vector, float max_length );
    inline static float component( vec3_t a, vec3_t b );
    inline static vec3_t cross( vec3_t lhs, vec3_t rhs );
    inline static float distance( vec3_t a, vec3_t b );
    inline static vec3_t from_spherical( float rad, float theta, float phi );
    inline static vec3_t lerp( vec3_t a, vec3_t b, float t );
    inline static vec3_t lerp_unclamped( vec3_t a, vec3_t b, float t );
    inline static vec3_t max( vec3_t a, vec3_t b );
    inline static vec3_t min( vec3_t a, vec3_t b );
    inline static vec3_t move_towards( vec3_t current, vec3_t target, float max_distance_delta );
    inline static vec3_t orthogonal( vec3_t v );
    inline static vec3_t rotate_towards( vec3_t current, vec3_t target, float max_radians_delta, float max_magnitude_delta );
    inline static vec3_t scale( vec3_t a, vec3_t b );
    inline static void to_spherical( vec3_t vector, float& rad, float& theta, float& phi );
    inline static float magnitude( vec3_t v );
    inline static float sqr_magnitude( vec3_t v );
    inline static vec3_t normalize( vec3_t v );
    inline static vec3_t normalize_euler( vec3_t v );
    inline static float normalize_angle( float f );
    inline static vec3_t from_string( std::string str );
    inline static vec3_t to_euler_rad( quater_t q1 );
    inline float magnitude( ) { return magnitude( *this ); }
    inline float sqr_magnitude( ) { return sqr_magnitude( *this ); }
    inline vec3_t normalized( ) { return normalize( *this ); }
    inline vec3_t normalized_euler( ) { return normalize_euler( *this ); }

    inline bool is_zero( ) { return x == 0 && y == 0 && z == 0; }

    inline bool operator<( const vec3_t& other ) const
    {
        if ( x != other.x )
            return x < other.x;
        if ( y != other.y )
            return y < other.y;
        return z < other.z;
    }
    inline const vec3_t& operator+=( float v )
    {
        x += v;
        y += v;
        y += v;
        return *this;
    };
    inline const vec3_t& operator-=( float v )
    {
        x -= v;
        y -= v;
        y -= v;
        return *this;
    };
    inline const vec3_t& operator*=( float v )
    {
        x *= v;
        y *= v;
        z *= v;
        return *this;
    };
    inline const vec3_t& operator/=( float v )
    {
        x /= v;
        y /= v;
        z /= v;
        return *this;
    };
    inline const vec3_t& operator+=( vec3_t v )
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    };
    inline const vec3_t& operator-=( vec3_t v )
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    };
    inline const vec3_t& operator*=( vec3_t v )
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    };
    inline vec3_t& operator/=( vec3_t v )
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    };
};

struct quater_t
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        float data[ 4 ];
    };
    inline quater_t( )
        : x( 0 )
        , y( 0 )
        , z( 0 )
        , w( 1 ) {};
    inline quater_t( float data[] )
        : x( data[ 0 ] )
        , y( data[ 1 ] )
        , z( data[ 2 ] )
        , w( data[ 3 ] )
    {
    }
    inline quater_t( vec3_t vector, float scalar )
        : x( vector.x )
        , y( vector.y )
        , z( vector.z )
        , w( scalar ) {};
    inline quater_t( float x, float y, float z, float w )
        : x( x )
        , y( y )
        , z( z )
        , w( w ) {};

    inline static quater_t identity( ) { return quater_t( 0, 0, 0, 1 ); };
    inline static quater_t from_to_rotation( vec3_t fromVector, vec3_t toVector );
    [[maybe_unused]] inline static quater_t look_rotation( vec3_t forward );
    inline static quater_t look_rotation( vec3_t forward, vec3_t upwards );
    inline static float norm( quater_t rotation );
    inline static quater_t normalize( quater_t rotation );
    inline static quater_t conjugate( quater_t rotation );
    [[maybe_unused]] inline static quater_t inverse( quater_t rotation );
    inline static vec3_t to_euler( quater_t rotation );
    inline vec3_t euler( ) { return to_euler( *this ); }

    inline quater_t& operator+=( float v )
    {
        x += v;
        y += v;
        z += v;
        w += v;
        return *this;
    }
    inline quater_t& operator-=( float v )
    {
        x -= v;
        y -= v;
        z -= v;
        w -= v;
        return *this;
    }
    inline quater_t& operator*=( float v )
    {
        x *= v;
        y *= v;
        z *= v;
        w *= v;
        return *this;
    }
    inline quater_t& operator/=( float v )
    {
        x /= v;
        y /= v;
        z /= v;
        w /= v;
        return *this;
    }
    inline quater_t& operator+=( quater_t v )
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }
    inline quater_t& operator-=( quater_t v )
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }
    inline quater_t& operator*=( quater_t v )
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        w *= v.w;
        return *this;
    }
};

inline quater_t operator+( quater_t lhs, const float rhs )
{
    return quater_t( lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs );
}
inline quater_t operator-( quater_t lhs, const float rhs )
{
    return quater_t( lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs );
}
inline quater_t operator*( quater_t lhs, const float rhs )
{
    return quater_t( lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs );
}
inline quater_t operator/( quater_t lhs, const float rhs )
{
    return quater_t( lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs );
}
inline quater_t operator+( const float lhs, quater_t rhs )
{
    return quater_t( lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w );
}
inline quater_t operator-( const float lhs, quater_t rhs )
{
    return quater_t( lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w );
}
inline quater_t operator*( const float lhs, quater_t rhs )
{
    return quater_t( lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w );
}
inline quater_t operator/( const float lhs, quater_t rhs )
{
    return quater_t( lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w );
}
inline quater_t operator+( quater_t lhs, const quater_t rhs )
{
    return quater_t( lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w );
}
inline quater_t operator-( quater_t lhs, const quater_t rhs )
{
    return quater_t( lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w );
}
inline quater_t operator*( quater_t lhs, const quater_t rhs )
{
    return quater_t( lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w );
}
inline quater_t operator/( quater_t lhs, const quater_t rhs )
{
    return quater_t( lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w );
}
inline bool operator==( const quater_t lhs, const quater_t rhs )
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}
inline bool operator!=( const quater_t lhs, const quater_t rhs )
{
    return lhs.x != rhs.x && lhs.y != rhs.y && lhs.z != rhs.z && lhs.w != rhs.w;
}

inline quater_t operator-( quater_t v )
{
    return v * -1;
}

float quater_t::norm( quater_t rotation )
{
    return sqrt( rotation.x * rotation.x +
                 rotation.y * rotation.y +
                 rotation.z * rotation.z +
                 rotation.w * rotation.w );
}

quater_t quater_t::normalize( quater_t rotation )
{
    return rotation / norm( rotation );
}

quater_t quater_t::from_to_rotation( vec3_t fromVector, vec3_t toVector )
{
    float dot = vec3_t::dot( fromVector, toVector );
    float k = sqrt( fromVector.sqr_magnitude( ) * toVector.sqr_magnitude( ) );
    if ( fabs( dot / k + 1 ) < 0.00001 )
    {
        vec3_t ortho = fromVector.orthogonal( fromVector );
        return quater_t( ortho.normalized( ), 0 );
    }
    vec3_t cross = vec3_t::cross( fromVector, toVector );
    return normalize( quater_t( cross, dot + k ) );
}

[[maybe_unused]] quater_t quater_t::look_rotation( vec3_t forward )
{
    return look_rotation( forward, vec3_t( 0, 1, 0 ) );
}

quater_t quater_t::look_rotation( vec3_t forward, vec3_t upwards )
{
    forward = forward.normalized( );
    upwards = upwards.normalized( );
    if ( forward.sqr_magnitude( ) < SMALL_FLOAT || upwards.sqr_magnitude( ) < SMALL_FLOAT )
        return identity( );
    if ( 1 - fabs( vec3_t::dot( forward, upwards ) ) < SMALL_FLOAT )
        return from_to_rotation( vec3_t::forward( ), forward );
    vec3_t right = vec3_t::cross( upwards, forward ).normalized( );
    upwards = vec3_t::cross( forward, right );
    quater_t quater_t;
    float radicand = right.x + upwards.y + forward.z;
    if ( radicand > 0 )
    {
        quater_t.w = sqrt( 1.0f + radicand ) * 0.5f;
        float recip = 1.0f / ( 4.0f * quater_t.w );
        quater_t.x = ( upwards.z - forward.y ) * recip;
        quater_t.y = ( forward.x - right.z ) * recip;
        quater_t.z = ( right.y - upwards.x ) * recip;
    } else if ( right.x >= upwards.y && right.x >= forward.z )
    {
        quater_t.x = sqrt( 1.0f + right.x - upwards.y - forward.z ) * 0.5f;
        float recip = 1.0f / ( 4.0f * quater_t.x );
        quater_t.w = ( upwards.z - forward.y ) * recip;
        quater_t.z = ( forward.x + right.z ) * recip;
        quater_t.y = ( right.y + upwards.x ) * recip;
    } else if ( upwards.y > forward.z )
    {
        quater_t.y = sqrt( 1.0f - right.x + upwards.y - forward.z ) * 0.5f;
        float recip = 1.0f / ( 4.0f * quater_t.y );
        quater_t.z = ( upwards.z + forward.y ) * recip;
        quater_t.w = ( forward.x - right.z ) * recip;
        quater_t.x = ( right.y + upwards.x ) * recip;
    } else
    {
        quater_t.z = sqrt( 1.0f - right.x - upwards.y + forward.z ) * 0.5f;
        float recip = 1.0f / ( 4.0f * quater_t.z );
        quater_t.y = ( upwards.z + forward.y ) * recip;
        quater_t.x = ( forward.x + right.z ) * recip;
        quater_t.w = ( right.y - upwards.x ) * recip;
    }
    return quater_t;
}

inline vec3_t operator+( vec3_t lhs, const float rhs )
{
    return vec3_t( lhs.x + rhs, lhs.y + rhs, lhs.z + rhs );
}
inline vec3_t operator-( vec3_t lhs, const float rhs )
{
    return vec3_t( lhs.x - rhs, lhs.y - rhs, lhs.z - rhs );
}
inline vec3_t operator*( vec3_t lhs, const float rhs )
{
    return vec3_t( lhs.x * rhs, lhs.y * rhs, lhs.z * rhs );
}
inline vec3_t operator/( vec3_t lhs, const float rhs )
{
    return vec3_t( lhs.x / rhs, lhs.y / rhs, lhs.z / rhs );
}
inline vec3_t operator+( const float lhs, vec3_t rhs )
{
    return vec3_t( lhs + rhs.x, lhs + rhs.y, lhs + rhs.z );
}
inline vec3_t operator-( const float lhs, vec3_t rhs )
{
    return vec3_t( lhs - rhs.x, lhs - rhs.y, lhs - rhs.z );
}
inline vec3_t operator*( const float lhs, vec3_t rhs )
{
    return vec3_t( lhs * rhs.x, lhs * rhs.y, lhs * rhs.z );
}
inline vec3_t operator/( const float lhs, vec3_t rhs )
{
    return vec3_t( lhs / rhs.x, lhs / rhs.y, lhs / rhs.z );
}
inline vec3_t operator+( vec3_t lhs, const vec3_t rhs )
{
    return vec3_t( lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z );
}
inline vec3_t operator-( vec3_t lhs, const vec3_t rhs )
{
    return vec3_t( lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z );
}
inline vec3_t operator*( vec3_t lhs, const vec3_t rhs )
{
    return vec3_t( lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z );
}
inline vec3_t operator/( vec3_t lhs, const vec3_t rhs )
{
    return vec3_t( lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z );
}
inline bool operator==( const vec3_t lhs, const vec3_t rhs )
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}
inline bool operator!=( const vec3_t lhs, const vec3_t rhs )
{
    return lhs.x != rhs.x && lhs.y != rhs.y && lhs.z != rhs.z;
}
inline vec3_t operator-( vec3_t v )
{
    return v * -1;
}
inline vec3_t operator*( quater_t lhs, const vec3_t rhs )
{
    vec3_t u = vec3_t( lhs.x, lhs.y, lhs.z );
    float s = lhs.w;
    return u * ( vec3_t::dot( u, rhs ) * 2.0f ) + rhs * ( s * s - vec3_t::dot( u, u ) ) + vec3_t::cross( u, rhs ) * ( 2.0f * s );
}

quater_t quater_t::conjugate( quater_t rotation )
{
    return quater_t( -rotation.x, -rotation.y, -rotation.z, rotation.w );
}

[[maybe_unused]] quater_t quater_t::inverse( quater_t rotation )
{
    float n = norm( rotation );
    return conjugate( rotation ) / ( n * n );
}

vec3_t quater_t::to_euler( quater_t rotation )
{
    float sqw = rotation.w * rotation.w;
    float sqx = rotation.x * rotation.x;
    float sqy = rotation.y * rotation.y;
    float sqz = rotation.z * rotation.z;
    float unit = sqx + sqy + sqz + sqw;
    float test = rotation.x * rotation.w - rotation.y * rotation.z;
    vec3_t v;
    if ( test > 0.4995f * unit )
    {
        v.y = 2 * atan2f( rotation.y, rotation.x );
        v.x = ( float ) M_PI_2;
        v.z = 0;
        return v;
    }
    if ( test < -0.4995f * unit )
    {
        v.y = -2 * atan2f( rotation.y, rotation.x );
        v.x = -( float ) M_PI_2;
        v.z = 0;
        return v;
    }
    v.y = atan2f( 2 * rotation.w * rotation.y + 2 * rotation.z * rotation.x, 1 - 2 * ( rotation.x * rotation.x + rotation.y * rotation.y ) );
    v.x = asinf( 2 * ( rotation.w * rotation.x - rotation.y * rotation.z ) );
    v.z = atan2f( 2 * rotation.w * rotation.z + 2 * rotation.x * rotation.y, 1 - 2 * ( rotation.z * rotation.z + rotation.x * rotation.x ) );
    return ( v * Rad2Deg ) + 180;
}

float vec3_t::angle( vec3_t from, vec3_t to )
{
    float v = dot( from, to ) / ( from.magnitude( ) * to.magnitude( ) );
    v = fmax( v, -1.0 );
    v = fmin( v, 1.0 );
    return acos( v );
}

float vec3_t::dot( vec3_t lhs, vec3_t rhs )
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

vec3_t vec3_t::clamp_magnitude( vec3_t vector, float max_length )
{
    float length = vector.magnitude( );
    if ( length > max_length )
        vector *= max_length / length;
    return vector;
}

float vec3_t::component( vec3_t a, vec3_t b )
{
    return dot( a, b ) / b.magnitude( );
}

vec3_t vec3_t::cross( vec3_t lhs, vec3_t rhs )
{
    float x = lhs.y * rhs.z - lhs.z * rhs.y;
    float y = lhs.z * rhs.x - lhs.x * rhs.z;
    float z = lhs.x * rhs.y - lhs.y * rhs.x;
    return vec3_t( x, y, z );
}

float vec3_t::distance( vec3_t a, vec3_t b )
{
    return ( a - b ).magnitude( );
}

vec3_t vec3_t::from_spherical( float rad, float theta, float phi )
{
    vec3_t v;
    v.x = rad * sin( theta ) * cos( phi );
    v.y = rad * sin( theta ) * sin( phi );
    v.z = rad * cos( theta );
    return v;
}

vec3_t vec3_t::lerp( vec3_t a, vec3_t b, float t )
{
    if ( t < 0 )
        return a;
    else if ( t > 1 )
        return b;
    return lerp_unclamped( a, b, t );
}

vec3_t vec3_t::lerp_unclamped( vec3_t a, vec3_t b, float t )
{
    return ( b - a ) * t + a;
}

vec3_t vec3_t::max( vec3_t a, vec3_t b )
{
    float x = a.x > b.x ? a.x : b.x;
    float y = a.y > b.y ? a.y : b.y;
    float z = a.z > b.z ? a.z : b.z;
    return vec3_t( x, y, z );
}

vec3_t vec3_t::min( vec3_t a, vec3_t b )
{
    float x = a.x > b.x ? b.x : a.x;
    float y = a.y > b.y ? b.y : a.y;
    float z = a.z > b.z ? b.z : a.z;
    return vec3_t( x, y, z );
}

vec3_t vec3_t::move_towards( vec3_t current, vec3_t target, float max_distance_delta )
{
    vec3_t d = target - current;
    float m = d.magnitude( );
    if ( m < max_distance_delta || m == 0 )
        return target;
    return current + ( d * max_distance_delta / m );
}

vec3_t vec3_t::orthogonal( vec3_t v )
{
    return v.z < v.x ? vec3_t( v.y, -v.x, 0 ) : vec3_t( 0, -v.z, v.y );
}

vec3_t vec3_t::rotate_towards( vec3_t current, vec3_t target, float max_radians_delta, float max_magnitude_delta )
{
    float mag_cur = current.magnitude( );
    float mag_tar = target.magnitude( );
    float new_mag = mag_cur + max_magnitude_delta * ( ( mag_tar > mag_cur ) - ( mag_cur > mag_tar ) );
    new_mag = fmin( new_mag, fmax( mag_cur, mag_tar ) );
    new_mag = fmax( new_mag, fmin( mag_cur, mag_tar ) );
    float total_angle = angle( current, target ) - max_radians_delta;
    if ( total_angle <= 0 )
        return normalize( target ) * new_mag;
    else if ( total_angle >= M_PI )
        return -target.normalized( ) * new_mag;
    vec3_t axis = cross( current, target );
    float mag_axis = axis.magnitude( );
    if ( mag_axis == 0 )
        axis = cross( current, current + vec3_t( 3.95, 5.32, -4.24 ) ).normalized( );
    else
        axis /= mag_axis;
    current = current.normalized( );
    vec3_t new_vector = current * cos( max_radians_delta ) + cross( axis, current ) * sin( max_radians_delta );
    return new_vector * new_mag;
}

vec3_t vec3_t::scale( vec3_t a, vec3_t b )
{
    return vec3_t( a.x * b.x, a.y * b.y, a.z * b.z );
}

void vec3_t::to_spherical( vec3_t vector, float& rad, float& theta, float& phi )
{
    rad = vector.magnitude( );
    float v = vector.z / rad;
    v = fmax( v, -1.0 );
    v = fmin( v, 1.0 );
    theta = acos( v );
    phi = atan2( vector.y, vector.x );
}

float vec3_t::magnitude( vec3_t v )
{
    return sqrt( v.x * v.x + v.y * v.y + v.z * v.z );
}

float vec3_t::sqr_magnitude( vec3_t v )
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

vec3_t vec3_t::normalize( vec3_t v )
{
    float mag = v.magnitude( );
    if ( mag == 0 )
        return vec3_t::zero( );
    return v / mag;
}

float vec3_t::normalize_angle( float f )
{
    while ( f > 360 )
        f -= 360;
    while ( f < 0 )
        f += 360;
    return f;
}

vec3_t vec3_t::normalize_euler( vec3_t vec )
{
    vec.x = normalize_angle( vec.x );
    vec.y = normalize_angle( vec.y );
    vec.z = normalize_angle( vec.z );
    return vec;
}

vec3_t vec3_t::to_euler_rad( quater_t q1 )
{
    // float Rad2Deg = 360.0f / (M_PI * 2.0f);
    float sqw = q1.w * q1.w;
    float sqx = q1.x * q1.x;
    float sqy = q1.y * q1.y;
    float sqz = q1.z * q1.z;
    float unit = sqx + sqy + sqz + sqw;
    float test = q1.x * q1.w - q1.y * q1.z;
    vec3_t v;

    if ( test > 0.4995f * unit )
    {
        v.y = 2.0f * atan2f( q1.y, q1.x );
        v.x = M_PI / 2.0f;
        v.z = 0;
        return normalize_euler( v * Rad2Deg );
    }
    if ( test < -0.4995f * unit )
    {
        v.y = -2.0f * atan2f( q1.y, q1.x );
        v.x = -M_PI / 2.0f;
        v.z = 0;
        return normalize_euler( v * Rad2Deg );
    }
    quater_t q( q1.w, q1.z, q1.x, q1.y );
    v.y = atan2f( 2.0f * q.x * q.w + 2.0f * q.y * q.z, 1 - 2.0f * ( q.z * q.z + q.w * q.w ) ); // yaw
    v.x = asinf( 2.0f * ( q.x * q.z - q.w * q.y ) );                                           // pitch
    v.z = atan2f( 2.0f * q.x * q.y + 2.0f * q.z * q.w, 1 - 2.0f * ( q.y * q.y + q.z * q.z ) ); // roll
    return normalize_euler( v * Rad2Deg );
}
