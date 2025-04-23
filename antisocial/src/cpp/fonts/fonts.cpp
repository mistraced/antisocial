#include "fonts.hpp"

#include "include/instrument_sans/medium.hpp"

void c_fonts::initialize( )
{
    primary = { ImGui::GetIO( ).Fonts->AddFontFromMemoryTTF( instrument_sans_medium_ttf, sizeof instrument_sans_medium_ttf, 12.f * 2, nullptr, ImGui::GetIO( ).Fonts->GetGlyphRangesCyrillic( ) ), 12.f };

    ImGui::GetIO( ).FontGlobalScale = 0.5f;
}