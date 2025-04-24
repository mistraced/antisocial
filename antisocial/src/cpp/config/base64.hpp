#pragma once

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

class base64
{
private:
    static const char base64_encoding_table[ 64 ];
    static const int base64_decoding_table[ 131 ];

    static int binary_string_to_decimal( std::string binary_string );
    static bool is_string_ascii( std::string message );

public:
    static bool is_number( const std::string input );
    static std::string line_splitting( std::string base64_message, int length );

    static std::string base64_encode( std::string message );
    static std::string base64_decode( std::string message );
};

const char base64::base64_encoding_table[ 64 ] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/' };

const int base64::base64_decoding_table[ 131 ] = {
    // Corresponding values with BASE64Table            // ASCII
    -1,                                     // 000
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 001 ~ 010
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 011 ~ 020
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 021 ~ 030
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 031 ~ 040
    -1, -1, 62, -1, -1, -1, 63, 52, 53, 54, // 041 ~ 050   (- - + - - - / 0 1 2)
    55, 56, 57, 58, 59, 60, 61, -1, -1, -1, // 051 ~ 060   (3 4 5 6 7 8 9 - - -)
    -1, -1, -1, -1, 0, 1, 2, 3, 4, 5,       // 061 ~ 070   (- - - - A B C D E F)
    6, 7, 8, 9, 10, 11, 12, 13, 14, 15,     // 071 ~ 080   (G H I J K L M N O P)
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 081 ~ 090   (Q R S T U V W X Y Z)
    -1, -1, -1, -1, -1, -1, 26, 27, 28, 29, // 091 ~ 100   (- - - - - - a b c d)
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, // 101 ~ 110   (e f g h i j k l m n)
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, // 111 ~ 120   (o p q r s t u v w x)
    50, 51, -1, -1, -1, -1, -1, -1, -1, -1, // 121 ~ 130   (y z - - - - - - - -)
};

int base64::binary_string_to_decimal( std::string binary_string )
{
    int num = stoi( binary_string );
    int dec_value = 0;

    int base = 1;
    int temp = num;

    while ( temp )
    {

        int last_dig = temp % 10;
        temp = temp / 10;

        dec_value += last_dig * base;

        base = base * 2;
    }

    return dec_value;
}

bool base64::is_string_ascii( std::string message )
{
    return !std::any_of( message.begin( ), message.end( ), []( char character ) {
        return static_cast< unsigned char >( character ) > 127;
    } );
}

std::string base64::base64_encode( std::string message )
{
    if ( !base64::is_string_ascii( message ) )
        throw "The given string isn't fully consisted of ASCII characters. Please check your input.";

    std::string binary_message = "";
    for ( char character : message )
        binary_message += std::bitset< 8 >( character ).to_string( );

    if ( binary_message.length( ) % 24 != 0 )
    {
        int pad_length = ( binary_message.length( ) / 24 + 1 ) * 24 - binary_message.length( );
        for ( int _seq = 0; _seq <= pad_length; ++_seq )
            binary_message.push_back( '~' );
    }

    std::vector< std::string > base64_vector;
    std::string unit;
    int current_position = 1;

    for ( char bit : binary_message )
    {
        unit.push_back( bit );
        if ( current_position % 6 == 0 )
        {
            base64_vector.push_back( unit );
            unit = "";
        }
        current_position++;
    }

    std::string base64_string = "";
    for ( std::string chunk : base64_vector )
    {
        if ( chunk == "~~~~~~" )
        {
            base64_string += '=';
        } else
        {
            std::regex regex_for_tilde( "~" );
            chunk = std::regex_replace( chunk, regex_for_tilde, "0" );
            int decimal_converted_character = base64::binary_string_to_decimal( chunk );
            base64_string.push_back( base64::base64_encoding_table[ decimal_converted_character ] );
        }
    }

    return base64_string;
}

std::string base64::base64_decode( std::string message )
{
    message.erase( remove( message.begin( ), message.end( ), '\n' ), message.cend( ) );

    if ( !base64::is_string_ascii( message ) )
        throw "The given string isn't fully consisted of ASCII characters. Please check your input.";

    std::string binary_decoded_message;

    size_t pos = message.find( "=" );
    while ( pos != std::string::npos )
    {
        message.erase( pos, 1 );
        pos = message.find( "=", pos );
    }

    for ( char character : message )
    {
        std::string binary_one_byte_message = std::bitset< 8 >( ( int ) character ).to_string( );
        int sextet_dec = base64::base64_decoding_table[ base64::binary_string_to_decimal( binary_one_byte_message ) ];

        binary_decoded_message.append( std::bitset< 6 >( sextet_dec ).to_string( ) );
    }

    std::string decoded_message;
    std::string character_buffer;
    int counter = 0;

    for ( char character : binary_decoded_message )
    {
        character_buffer += character;
        counter++;

        if ( counter % 8 == 0 && counter > 1 )
        {
            int octat = base64::binary_string_to_decimal( character_buffer );

            if ( octat >= 32 && octat <= 126 )
            {
                decoded_message += ( char ) octat;
            }

            character_buffer = "";
        }
    }

    return decoded_message;
}

std::string base64::line_splitting( std::string base64_message, int length )
{
    int character_count = 1;
    std::string result;

    for ( char character : base64_message )
    {
        result += character;
        if ( character_count % length == 0 )
            result += '\n';

        character_count++;
    }

    return result;
}

bool base64::is_number( const std::string input )
{
    for ( char const ch : input )
    {
        if ( isdigit( ch ) == 0 )
            return false;
    }
    return true;
}
